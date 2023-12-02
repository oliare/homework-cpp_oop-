#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Category {
	ACTION, BATTLE, RPG, RTS
};
const size_t SIZE = 150;

class Game {
	char name[SIZE];
	Category category;
	int popularity;
public:
	Game() = default;
	Game(const char* name, const Category& category, const int& popularity)
		: category{ category }, popularity{ popularity }, name{ 0 }
	{
		strncpy_s(this->name, name, SIZE - 1);
	}
	const char* getName() const {
		return name;
	}

	Category getCategory() const {
		return category;
	}
	int getPopularity() const {
		return popularity;
	}
	void print() const {
		cout << "\tGame       : " << name << endl;
		cout << "\tCategory   : " << category << endl;
		cout << "\tPopularity : " << popularity << endl;
	}
};

class AboutGames
{
	vector<Game> games;
public:
	AboutGames() {};

	void save(const string& fname) const {
		ofstream file(fname, ios::binary | ios::app);
		if (!file.is_open()) {
			cout << "error opening file" << endl;
			return;
		}
		for (const auto& game : games) {
			file.write(reinterpret_cast<const char*>(&game), sizeof(Game));
		}
		file.close();
	}
	
	static void viewGames(const string& fname) {
		ifstream file(fname, ios::binary | ios::in);
		if (!file.is_open()) {
			cout << "error opening file" << endl;
			return;
		}
		Game res;
		while (file.read(reinterpret_cast<char*>(&res), sizeof(Game))) {
			res.print();
			cout << "\t-----------------------" <<endl;
		}
		file.close();
	}

	void printGames() const {
		cout << "\n\t   * * *  GAMES  * * *\n\n";
		for (const auto& game : games) {
			game.print();
			cout << "\t----------------------" << endl;
		}
	}

	void addGame(const Game& newGame) {
		games.push_back(newGame);
		ofstream file("games.dat", ios::binary | ios::app);
		if (!file.is_open()) {
			cout << "error opening file" << endl;
			return;
		}
		file.write(reinterpret_cast<const char*>(&newGame), sizeof(Game));
		file.close();
	}

	void searchByName(const string& name) const {
		bool found = false;
		for (const auto& game : games) {
			if (game.getName() == name)
			{
				game.print();
				cout << "\t----------------------" << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "no game with such name exist. . ." << endl;
		}
	}

	void searchByCategory(const Category& category) const {
		bool found = false;
		for (const auto& game : games) {
			if (game.getCategory() == category)
			{
				game.print();
				cout << "\t----------------------" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "no game with such category exist. . ." << endl;
		}
	}

	void editByName(const string& name, const Game& newerGame) {
		bool found = false;
		for (auto& game : games) {
			if (game.getName() == name)
			{
				game = newerGame;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "' " << name << " ' - not found " << endl;
		}
	}
	void removeGame(const string& name) {
		bool found = false;
		for (auto it = games.begin(); it != games.end(); it++) {
			if (it->getName() == name) {
				it = games.erase(it);
				found = true;
				cout << name << " was deleted" << endl;
			}
		}
		if (!found) {
			cout << " - game not found - " << endl;
		}
	}

	void clearData() {
		games.clear();
	}

};


