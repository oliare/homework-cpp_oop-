#pragma once
#include <iostream>
using namespace std;

class User
{
	string login, password;
public:
	User(const string& login, const string& password) :
		login(login), password(password)
	{}
	const string& getlogin() const;
	const string& getpassword() const;
};