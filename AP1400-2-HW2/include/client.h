#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>

class Server;

class Client
{
public:
	Client(std::string id, Server& server);
	std::string get_id();
	std::string get_publickey()const;
	double get_wallet();
	
	
	std::string sign(std::string txt) const;
	
	bool transfer_money(std::string receiver, double value);
	size_t generate_nonce();
private:
	Server* server;
	const std::string id;
	std::string public_key;
	std::string private_key;
};
#endif //CLIENT_H