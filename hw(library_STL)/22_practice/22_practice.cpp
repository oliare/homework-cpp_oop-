#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;

struct Book {
	string author;
	string name;
	size_t year;
	bool available;
};

class Library {
	list<Book>library;
public:
	Library() = default;

	void addBook(const Book& book);
	void printBooks() const;
	Book* findBook(const string& author, const string& name);
	list<Book> searchByAuthor(const string& author);

	void givenBook(const string& author, const string& name, const size_t& year);
	void returnBook(const string& author, const string& name, const size_t& year);

	void sortByAuthor(const string& author);
	void sortByName(const string& name);

	void removeBook(const string& author, const string& name, const size_t& year);
	void removeBookByInd(const size_t& index);

	void editBook(const int& index, const string& otherAuthor, const string& otherName, const size_t& otherYear, const bool& isAvailable);

	void save(const string& fname);
	void load(const string& fname);
};


int main()
{
	Library library;

	library.addBook({ "Maria Fontana", "Stone of Wisdom", 1998, true });
	library.addBook({ "Neil Gaiman", "Good Omens", 1990, true });
	library.addBook({ "Rebecca Yarros", "Fourth Wind", 2023, true });
	library.addBook({ "Terry Pratchett", "Good Omens", 1990, true });
	library.addBook({ "Rebecca Kuang", "The Burning God", 2021, true });
	library.addBook({ "Rebecca Kuang", "Dragon Republic", 2020, true });
	library.printBooks();

	library.givenBook("Terry Pratchett", "Good Omens", 1990);
	library.printBooks();
	library.returnBook("Terry Pratchett", "Good Omens", 1990);
	library.printBooks();
	library.findBook("Neil Gaiman", "Good Omens");
	library.printBooks();
	library.searchByAuthor("Rebecca Kuang");

	library.sortByAuthor("Rebecca Kuang");
	library.printBooks();
	library.sortByName("Good Omens");
	library.printBooks();
	library.editBook(1, "Neil Gaiman", "Good Women", 2020, true);
	library.printBooks();

	library.removeBook("Maria Fontana", "Stone of Wisdom", 1998);
	library.printBooks();
	library.removeBookByInd(3);
	library.printBooks();
	library.save("library.txt");
	library.load("library.txt");

}


void Library::addBook(const Book& book)
{
	library.push_back(book);
}

void Library::printBooks() const
{
	cout << "\n\n\t*  *  * * * LIBRARY * * *  *  *\n" << endl;
	cout << "Author\t\t\tName\t\t\tYear\tAvailable" << endl << endl;
	for (const auto& book : library) {
		cout << book.author << "\t\t";
		cout << book.name << "\t\t";
		cout << book.year << "\t";
		cout << boolalpha << book.available << endl;
	}
	cout << endl << endl;
}

void Library::givenBook(const string& author, const string& name, const size_t& year)
{
	for (auto it = library.begin(); it != library.end(); it++)
	{
		if (it->author == author && it->name == name && it->year == year && it->available) {
			it->available = false;
			cout << "-----> book '" << name << "(" << year << "') by " << author << " has been given" << endl;
		}
	}
	cout << "!!! book '" << name << "' not found... " << endl;
}

void Library::returnBook(const string& author, const string& name, const size_t& year) {
	auto it = find_if(library.begin(), library.end(), [&](const Book& b) {
		return (b.author == author && b.name == name && b.year == year && !b.available);
		});

	if (it != library.end())
	{
		it->available = true;
		cout << "-----> book '" << name << "' by " << author << " has been returned" << endl;
	}
	else {
		cout << "!!! book '" << name << "' not found . . ." << endl;
	}
}

void Library::sortByAuthor(const string& author)
{
	bool issort = false;
	library.sort([&author, &issort](const Book& a, const Book& b) {
		if (a.author == author && b.author != author) {
			issort = true;
			return true;
		}
		else if (a.author != author && b.author == author) {
			issort = true;
			return false;
		}
		else {
			return a.author < b.author;
		}
		});

	if (issort) {
		cout << "-----> books sorted by author: " << author << endl;
	}
	else {
		cout << "!!! there are no books with such author . . . " << author << endl;
	}
}

void Library::sortByName(const string& name)
{
	bool issort = false;
	library.sort([&name, &issort](const Book& a, const Book& b) {
		if (a.name == name && b.name != name) {
			issort = true;
			return true;
		}
		else if (a.name != name && b.name == name) {
			issort = true;
			return false;
		}
		else {
			return a.name < b.name;
		}
		});

	if (issort) {
		cout << "-----> books sorted by name: " << name << endl;
	}
	else {
		cout << "!!! there are no books with such name . . . " << name << endl;
	}
}

void Library::removeBook(const string& author, const string& name, const size_t& year)
{
	bool removed = false;
	library.remove_if([&](const Book& b) {
		if (b.author == author && b.name == name && b.year == year) {
			removed = true;
			cout << "-----> book '" << name << "(" << year << "') by " << author << " has been removed" << endl;
			return true;
		}
		return false; });
}

void Library::removeBookByInd(const size_t& index)
{
	if (index >= library.size() || index < 0) {
		cout << "!!! invalid index . . ." << endl;
	}
	auto it = library.begin();
	advance(it, index);
	library.erase(it);
	cout << "-----> book by index [" << index << "] has been removed" << endl;
}

void Library::editBook(const int& index, const string& otherAuthor, const string& otherName, const size_t& otherYear, const bool& isAvailable)
{
	if (index >= 0 && index < library.size())
	{
		auto it = library.begin();
		advance(it, index);

		it->author = otherAuthor;
		it->name = otherName;
		it->year = otherYear;
		it->available = isAvailable;
		cout << "-----> book by index [" << index << "] has been edited " << endl;
	}
	else {
		cout << "!!! invalid index . . ." << endl;
	}
}

void Library::save(const string& fname)
{
	ofstream file(fname);
	if (!file.is_open()) {
		cout << "\t!! error to open file !!" << endl;
	}
	for (const auto& book : library) {
		file << book.author << "_ _ _ _" << book.name << "_ _ _ _" << book.year << "_ _ _ _" << boolalpha <<book.available << endl;
	}
	file.close();
}

void Library::load(const string& fname)
{
	ifstream file(fname);
	if (!file.is_open()) {
		cout << "\t!! error to read file !!" << endl;
	}
	library.clear();

	Book book;
	while (file >> book.author >> book.name >> book.year >> book.available)
	{
		library.push_back(book);
	}
	file.close();
}


Book* Library::findBook(const string& author, const string& name)
{
	auto it = find_if(library.begin(), library.end(), [author, name](const Book& b)
		{ return b.author == author && b.name == name; });

	if (it != library.end()) {
		cout << "-----> book '" << name << "' by " << author << " has been found" << endl;
		return &(*it);
	}
	else {
		cout << "-----> book '" << name << "' by " << author << " not found" << endl;
		return nullptr;
	}
}

list<Book> Library::searchByAuthor(const string& author)
{
	list<Book> find;
	auto it = find_if(library.begin(), library.end(), [author](const Book& b) {return b.author == author; });

	if (it != library.end()) {
		while (it != library.end())
		{
			if (it->author == author) {
				find.push_back(*it);
			}
			it++;
		}
		cout << "-----> books by '" << author << "' were found " << endl;
		for (const auto& book : find) {
			cout << "Name :: " << book.name << endl;
		}
		cout << endl;
		return find;
	}
	else {
		cout << "!!! no books by '" << author << "' not found . . ." << endl;
		return find;
	}
}