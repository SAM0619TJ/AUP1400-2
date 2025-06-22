#include "client.h"
#include "crypto.h"
#include "server.h"
using std::string;
#include<random>

static std::default_random_engine e;



Client::Client(std::string id, Server& server) : id(id), server(&server){
    std::string public_key{}, private_key{}; 
    crypto::generate_key(public_key,private_key);
    this->public_key = public_key;
    this->private_key = private_key;
}

string Client::get_id(){ return this->id; }

string Client::get_publickey()const{ return this->public_key; }

double Client::get_wallet() {
    return server->get_wallet(id);
}

string Client::sign(string txt)const{ return crypto::signMessage(this->private_key, txt);}

bool Client::transfer_money(string receiver,double value)
{
    string trx = get_id() + '-' + receiver + '-' + std::to_string(value);
    auto signmessage = sign(this->private_key);
    return (Server*)(this->server)->add_pending_trx(trx, signmessage);
}

size_t Client::generate_nonce(){ return e() % 10000;}