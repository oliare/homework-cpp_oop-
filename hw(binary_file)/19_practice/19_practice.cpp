#include <iostream>
#include <fstream>
#include "Game.h"
using namespace std;

int main() {
    Game g1("Call of Duty", ACTION, 95);
    Game g2("Warcraft", RTS, 88);
    Game g3("PUBG", BATTLE, 87);
    Game g4("GTA", ACTION, 93);

    AboutGames games;
    games.addGame(g1);
    games.addGame(g2);
    games.addGame(g3);
    games.addGame(g4);
    games.printGames();

    cout << "\nSearching by NAME: \n";
    games.searchByName("PUBG");

    cout << "\nSearching by CATEGORY: \n";
    games.searchByCategory(RTS);
    games.searchByCategory(ACTION);

    cout << "\nEditing by NAME: ";
    Game editGame("Wheelman", ACTION, 85);
    games.editByName("GTA", editGame);
    games.printGames();
    cout << "\nRemove by NAME : ";
    games.removeGame("PUBG");
    games.printGames();
    games.clearData();
    cout << "\n\t ! Game base cleared !" << endl;
    games.save("games.dat");
    cout << "\nView file >> " << endl;
    games.viewGames("games.dat");
}