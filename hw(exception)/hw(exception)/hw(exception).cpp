#include <iostream>
#include <string>
#include "SocialNetwork.h"
using namespace std;


int main()
{
    SocialNetwork twi;
    twi.registerUser("Julia", "password123*");
    twi.registerUser("Max", "password321*");

    while (true)
    {
        int choice;
        cout << " \n\t1 - Register \n\t2 - Sign in \n Enter >> ";
        cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1:
        {
            try
            {
                string login, password;
                cin.ignore();
                cout << "\nEnter login    :: ";
                getline(cin, login);
                cout << "Enter password :: ";
                getline(cin, password);
                twi.registerUser(login, password);
                cout << "\t>> registered <<" << endl;
            }
            catch (const std::exception& ex)
            {
                cout << typeid(ex).name() << " \t " << ex.what() << endl;
            }
            break;
        }
        case 2:
        {
            bool correct = false;
            while (!correct){
                try
                {
                    string login, password;
                    cin.ignore();
                    cout << "\nEnter login    :: ";
                    getline(cin, login);
                    cout << "Enter password :: ";
                    getline(cin, password);
                    twi.sign_in(login, password);
                    correct = true;
                }
                catch (const std::exception& ex)
                {
                    cout << typeid(ex).name() << " \t " << ex.what() << endl;
                    cout << "!try again" << endl;
                }
            }
            break;
        }
        default:
            cout << "Invalid choice (enter 1 or 2)\n";
            break;
        }
    }
    return 0;
}
