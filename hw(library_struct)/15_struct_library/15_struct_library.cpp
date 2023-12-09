#include <iostream>
#include "library.h"
using namespace std;

int main()
{
	size_t size = 10;
	Book* library = new Book[size]{
		{"Harry Potter and the Half-Blood Prince","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
		{"Iron Flame","Rebecca Yarros","Entangled: Red Tower Books","Fantasy"},
		{"The Ever King","LJ Andrews","Victorious","Fantasy"},
		{"Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
		{"Harry Potter and the Chamber of Secrets","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
		{"Crown of Blood and Ruin","LJ Andrews","Victorious","Dark Fantasy Horror"},
		{"Harry Potter and the Prisoner of Azkaban","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
		{"Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
		{"Battlefield Reclaimer","David North","High Peak Publishing","Fiction"},
		{"Swords of Empire","Robert Ryan","Trotting Fox Press","Fantasy"},
	};

    while (true) {
        cout << "\n\n\t============= MENU =============\n" << endl;
        cout << "1. edit book" << endl;
        cout << "2. print all books" << endl;
        cout << "3. search book by author " << endl;
        cout << "4. search book by name" << endl;
        cout << "5. sort book by name" << endl;
        cout << "6. sort book by author" << endl;
        cout << "7. sort book by publisher" << endl;
        cout << "8. add new book" << endl;
        cout << "9. remove book by name" << endl;
        cout << "0. exit\n" << endl;

        int choice;
        cout << "Choose action: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        default:
            cout << "- invalid choice, try again..." << endl;
            break;
        case 1:
            editBook(library[3], 3);
            break;
        case 2:
            printBooks(library, size);
            break;
        case 3: {
            char authorName[SIZE];
            cout << ">>> enter the name of the author to search: ";
            cin.getline(authorName, SIZE);
            int index = searchByAuthor(library, size, authorName);
            if (index != -1) {
                printBook(library[index], "YOUR REQUEST");
            }
            break;
        }
        case 4: {
            char bookName[SIZE];
            cout << ">>> enter the name of the book to search: ";
            cin.getline(bookName, SIZE);
            int index = searchByName(library, size, bookName);
            if (index != -1) {
                printBook(library[index], "YOUR REQUEST");
            }
            break;
        }
        case 5:
            sortBooksByName(library, size);
            break;
        case 6:
            sortBooksByAuthor(library, size);
            break;
        case 7:
            sortBooksByPublisher(library, size);
            break;
        case 8: {
            addBook(library, size); 
            break;
        }
        case 9: {
            char bookName[SIZE];
            cout << ">>> enter the name of the book you want to delete: ";
            cin.getline(bookName, SIZE);
            deleteBookByName(library, size, bookName);
            break;
        }
        case 0:
            delete[] library;
            return 0;
        }
}
}