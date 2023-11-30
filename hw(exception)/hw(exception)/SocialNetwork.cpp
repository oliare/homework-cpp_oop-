#include "SocialNetwork.h"

void SocialNetwork::register_(const string& login, const string& password)
{
	if (!checkLogin(login))
	{
		throw ExistLoginException();
	}
	if (!checkPassword(password))
	{
		throw WrongPasswordLengthException();
	}
	User new_user(login, password);
	accounts.push_back(new_user);
}

void SocialNetwork::sign_in(const string& login, const string& password)
{
	if (findLogin(login) == -1) {
		throw;
	}
	if (accounts[findLogin(login)].getpassword() != password) {
		throw;
	}
	cout << "\n* welcome *" << endl;
}

bool SocialNetwork::checkPassword(const string& password) const
{
	return findDigit(password) and findLowAlpha(password) and findPunct(password) and findUpAlpah(password) && password.size() > 7;
}

bool SocialNetwork::checkLogin(const string& login) const
{
	return findLogin(login) == -1;
}

int SocialNetwork::findLogin(const string& login) const
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].getlogin() == login) {
			return i;
		}
	}
	return -1;
}

bool SocialNetwork::findDigit(const string& password) const
{
	for (size_t i = 0; i < password.size(); i++)
	{
		if (isdigit(password[i])) {
			return true;
		}
	}
	return false;
}

bool SocialNetwork::findUpAlpah(const string& password) const
{
	for (size_t i = 0; i < password.size(); i++)
	{
		if (isupper(password[i])) {
			return true;
		}
	}
	return false;
}

bool SocialNetwork::findLowAlpha(const string& password) const
{
	for (size_t i = 0; i < password.size(); i++)
	{
		if (islower(password[i])) {
			return true;
		}
	}
	return false;
}

bool SocialNetwork::findPunct(const string& password) const
{
	string symbols = ".,+-_&$#!?|@*^[]{}()%~`/|";
	for (size_t i = 0; i < password.size(); i++)
	{
		for (size_t j = 0; j < symbols.size(); j++)
		{
			if (password[i] == symbols[j]) {
				return true;
			}
		}
	}
	return false;
}

void SocialNetwork::registerUser(const string& login, const string& password)
{
	if (isExist(login))
	{
		throw ExistLoginException();
	}
	User user(login, password);
	accounts.push_back(user);
}

bool SocialNetwork::isExist(const string& login) const
{
	for (const User& user : accounts) {
		if (user.getlogin() == login) {
			return true; 
		}
	}
	return false;
}
