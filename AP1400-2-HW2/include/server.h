#ifndef SERVER_H
#define SERVER_H
#include<iostream>
#include <stdlib.h>
#include<map>
#include<memory>
#include<string>
#include<vector>

extern std::vector<std::string> pending_trxs;

class Client;

class Server
{
public:
	Server();
	std::shared_ptr<Client> add_client(std::string id);
	std::shared_ptr<Client> get_client(std::string id)const;
	double get_wallet(std::string id) const;

	static bool parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value);
	bool add_pending_trx(std::string trx, std::string signature);
	size_t mine();
	std::map<std::shared_ptr<Client>, double> get_clients() const;

private:
	std::map<std::shared_ptr<Client>, double> clients;
};
void show_wallets(const  Server& server);

#endif //SERVER_H