#include "library.h"

void printBooks(Book* library, size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		printBook(library[i], "Book " + to_string(i + 1));
	}
}

void printBook(Book& book, string text)
{
	cout << "\n\n---------------------- " << text << " ---------------------- " << endl;
	cout << "\t\t Name      :: " << book.name << endl;
	cout << "\t\t Author    :: " << book.author << endl;
	cout << "\t\t Publisher :: " << book.publisher << endl;
	cout << "\t\t Genre     :: " << book.genre << endl;
}

void editBook(Book& book, size_t index)
{
	if (index >= 0 && index < SIZE) {
		cout << ">>> enter new data for the book :" << endl;
		cout << "\t\t Enter Name      :: "; cin.getline(book.name, SIZE);
		cout << "\t\t Enter Author    :: "; cin.getline(book.author, SIZE);
		cout << "\t\t Enter Publisher :: "; cin.getline(book.publisher, SIZE);
		cout << "\t\t Enter Genre     :: "; cin.getline(book.genre, SIZE);
	}
	else {
		cout << "- invalid book index -" << endl;
	}
}

char* toLowerCase(char* line) {
	char* newLine = new char[strlen(line) + 1];
	for (int i = 0; i < strlen(line); i++)
	{
		newLine[i] = tolower(line[i]);
	}
	newLine[strlen(line)] = '\0';
	return newLine;
}

int searchByAuthor(Book* library, size_t& size, char* author) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(library[i].author, author) == 0)
		{
			return i;
			cout << "+ book by \"" << author << "\" was found" << endl;
		}
	}
	cout << "- book by \"" << author << "\" not found" << endl;
	return -1;
}

int searchByName(Book* library, size_t& size, char* name) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(library[i].name, name) == 0) {
			return i;
			cout << "+ book \"" << name << "\" was found" << endl;
		}
	}
	cout << "- book \"" << name << "\" not found" << endl;
	return -1;
}

void sortBooksByName(Book* library, size_t& size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(library[j].name, library[j + 1].name) > 0)
			{
				Book tmp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = tmp;
			}
		}
	}
	cout << ">>> the books were sorted by name" << endl;
}

void sortBooksByAuthor(Book* library, size_t& size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(library[i].author, library[j].author) > 0) {
				Book tmp = library[i];
				library[i] = library[j];
				library[j] = tmp;
			}
		}
	}
	cout << ">>> the books were sorted by author" << endl;
}

void sortBooksByPublisher(Book* library, size_t& size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(library[i].publisher, library[j].publisher) > 0)
			{
				Book tmp = library[i];
				library[i] = library[j];
				library[j] = tmp;
			}
		}
	}
	cout << ">>> the books were sorted by publisher" << endl;
}

void addBook(Book* library, size_t& size)
{
	if (size >= SIZE)
	{
		cout << "- unpossible to add a book because the library is full -" << endl;
		return;
	}
	cout << ">>> enter new data for the new book:" << endl;
	cout << "\t\t Enter Name      :: ";cin.getline(library[size].name, SIZE);
	cout << "\t\t Enter Author    :: ";cin.getline(library[size].author, SIZE);
	cout << "\t\t Enter Publisher :: ";cin.getline(library[size].publisher, SIZE);
	cout << "\t\t Enter Genre     :: ";cin.getline(library[size].genre, SIZE);
	size++;
	cout << ">>> book added to the library" << endl;
}

void deleteBookByName(Book*& library, size_t& size, const char* bookName) {
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(library[i].name, bookName) == 0) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = index; i < size - 1; i++) {
			library[i] = library[i + 1];
		}
		size--;
		cout << ">>> book \"" << bookName << "\" was deleted" << endl;
	}
	else {
		cout << "- book \"" << bookName << "\" not found" << endl;
	}
}
