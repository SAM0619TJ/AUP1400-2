#include "server.h"
#include "client.h"
#include "crypto.h"
#include<random>
static std::default_random_engine e;


using std::string;
using std::runtime_error;
using std::cout;
using std::endl;

std::vector<std::string> pending_trxs = {};
Server::Server(){ this->clients = {}; }

string prodoucerandom()
{
	string res = "";
	for (int i = 0;i < 4; i++)
	{
		auto num = e() % 10;
		res+= std::to_string(num);
	}
	return res;

}
std::shared_ptr<Client> Server::add_client(string id){
	auto isExist{false};

	for (auto& [client , amount] : clients){
		if (client->get_id() == id)
		{
			isExist = true;
			break;
		}
	}
	string NewId = id;
	if (isExist){
		NewId = id + prodoucerandom();
	}
	Client *newClient = new Client(NewId, *this);
	std::shared_ptr<Client> sp(newClient);
	this->clients[sp] = 5;
	return sp;
}
std::shared_ptr<Client> Server::get_client(string id)const{
	for (auto& [k, v] :clients)
	{
		if (k->get_id() == id)
		{
			return k;
		}
	}
	return nullptr;
}

double Server::get_wallet(string id) const
{
    auto sp = get_client(id);
    if (sp == nullptr) return 0;
    auto it = clients.find(sp);
    if (it == clients.end()) return 0;
    return it->second;
}

bool Server::parse_trx(string trx, string& sender, string& receiver, double& value)
{
	int p = 0;
	int mark[] = {0,0};
	for(int i = 0; i < trx.size(); i++)
	{
		if(trx.at(i) == '_'|| p >=2 && trx.at(i) == '-'){ throw runtime_error("fomat is not corrected");}
		if(trx.at(i) == '-')
		{
			mark[p] = i;
			p++;
		}
	}

	sender = trx.substr(0, mark[0]);
	receiver = trx.substr(mark[0]+1, mark[1] - mark[0]-1);
	value = std::stod(trx.substr(mark[1]+1, trx.size() - mark[1]-1));
	return true;

}
bool Server::add_pending_trx(std::string trx, std::string signature)
{
	string sender{};
	string receiver{};
	double value = 0;
	try
	{
		parse_trx(trx, sender, receiver, value);
	}catch (runtime_error e) {
        std::cout << e.what() << std::endl;
        return false;
    }


	auto t_sender = this->get_client(sender);
	auto t_receiver = this->get_client(receiver);
	auto public_key = t_sender->get_publickey();
	if (!t_receiver || !t_sender)return false;
	
	bool authentic = crypto::verifySignature(public_key, trx , signature);
	//if (!authentic)return false;
	if(get_wallet(sender) < value) return false;
	
	this->clients[this->get_client(sender)] -= value;
	this->clients[this->get_client(receiver)] += value;

	pending_trxs.push_back(trx);
	return true;

}
void show_wallets(const Server& server) {
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& client : server.get_clients())
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}
std::map<std::shared_ptr<Client>, double> Server::get_clients() const {
    return clients;
}

size_t Server::mine()
{
	if (pending_trxs.empty()) return 0;

	//connecting every trx into a string
	string mempool;
	for (auto& trx : pending_trxs)
	{
		mempool += trx;
	}
	cout<<mempool<<endl;


	for (auto& [client,_] : clients)
	{
		for (int attempt = 0; attempt < 1000; ++attempt)
		{
			size_t nonce = client->generate_nonce();
			string final_message = mempool + std::to_string(nonce);
			string hash = crypto::sha256(final_message);
			// 判断是否有连续的000在前10个
			if (hash.substr(0, 10).find("000") != std::string::npos){
				    clients[client] += 6.25;
			 		cout << client->get_id() << endl;
					//清空数据
			 		pending_trxs.clear();
			 		return nonce;
			}
		}
	}
    return 0;
}



