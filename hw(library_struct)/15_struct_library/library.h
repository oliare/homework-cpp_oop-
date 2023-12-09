#pragma once
#include <iostream>
#include <string>
using namespace std;

const size_t SIZE = 50;
struct Book
{
	char name[SIZE];
	char author[SIZE];
	char publisher[SIZE];
	char genre[SIZE];
};

void printBooks(Book* library, size_t& libSize);
void printBook(Book& book, string text);

void editBook(Book& book, size_t index);

int searchByName(Book* library, size_t& size, char* name);
int searchByAuthor(Book* library, size_t& size, char* author);

void sortBooksByName(Book* library, size_t& size);
void sortBooksByAuthor(Book* library, size_t& size);
void sortBooksByPublisher(Book* library, size_t& size);

void addBook(Book* library, size_t& size);
void deleteBookByName(Book*& library, size_t& size, const char* bookName);


