#pragma once
#include "User.h"
#include "myExc.h"
#include <vector>
class SocialNetwork
{
	vector<User> accounts;
	bool checkPassword(const string& password) const;
	bool checkLogin(const string& login) const;
	int findLogin(const string& login) const;
	bool findDigit(const string& password) const;
	bool findUpAlpah(const string& password) const;
	bool findLowAlpha(const string& password) const;
	bool findPunct(const string& password) const;
public:
	void registerUser(const string& login, const string& password);
	bool isExist(const string& login) const;
	void register_(const string& login, const string& password);
	void sign_in(const string& login, const string& password);
};