#include <iostream>
#include <string>
using namespace std;

class Animal
{
	string name;
	size_t age;
public:
	Animal(const string& name, const size_t& age)
		: name(name), age(age)
	{}

	string getName() const {
		return name;
	}
	size_t getAge() const {
		return age;
	}
	virtual void sound() const = 0;
	virtual void type() const = 0;
	virtual void show() const = 0;
};

class Dog : public Animal {
public:
	Dog(const string& name, const size_t& age)
		: Animal(name, age) {}

	void sound() const override {
		cout << "woof" << endl;
	}
	void type() const override {
		cout << "dog" << endl;
	}
	void show() const override {
		cout << "\tName : " << getName() << "\n\tAge: " << getAge() << endl;
		cout << "\tType : "; type();
		cout << "\tSound: "; sound();
	}
};

class Cat : public Animal {
public:
	Cat(const string& name, const size_t& age)
		: Animal(name, age) {}

	void sound() const override {
		cout << "meow" << endl;
	}
	void type() const override {
		cout << "cat" << endl;
	}
	void show() const override {
		cout << "\tName : " << getName() << "\n\tAge: " << getAge() << endl;
		cout << "\tType : "; type();
		cout << "\tSound: "; sound();
	}
};

class Parot : public Animal
{
public:
	Parot(const string& name, const size_t& age)
		: Animal(name, age) {}
	void sound() const {
		cout << "chirp" << endl;
	}
	void type() const override {
		cout << "parot" << endl;
	}
	void show() const override {
		cout << "\tName : " << getName() << "\n\tAge: " << getAge() << endl;
		cout << "\tType : "; type();
		cout << "\tSound: "; sound();
	}
};

class Hamster : public Animal
{
public:
	Hamster(const string& name, const size_t& age)
		: Animal(name, age) {}
	void sound() const {
		cout << "squeal" << endl;
	}
	void type() const override {
		cout << "hamster" << endl;
	}
	void show() const override {
		cout << "\tName : " << getName() << "\n\tAge: " << getAge() << endl;
		cout << "\tType : "; type();
		cout << "\tSound: "; sound();
	}
};

class HomeZoo
{
	Animal** zoo;
	size_t size;
public:
	HomeZoo() : zoo(nullptr), size(0)
	{}
	~HomeZoo()
	{
		if (zoo != nullptr) {
			for (size_t i = 0; i < size; ++i)
			{
				delete zoo[i];
			}
			delete[] zoo;
		}
	}
	void addAnimal(Animal* newAnimal)
	{
		//string type, name, breet, color;
		//size_t age;
		//cout << "Adding new animal > > >" << endl;
		//cout << "\tEnter type of animal    : "; cin >> type;
		//cout << "\tEnter name of animal    : "; cin >> name;
		//cout << "\tEnter age of animal     : "; cin >> age;
		//cout << "\tEnter color of animal   : "; cin >> color;
		//cout << "\tEnter breet of animal   : "; cin >> breet;

		Animal** tmp = new Animal * [size + 1];
		for (size_t i = 0; i < size; i++) 
		{
			tmp[i] = zoo[i];
		}
		delete[] zoo;
		zoo = tmp;
		zoo[size++] = newAnimal;
	}

	void print() const {
		for (size_t i = 0; i < size; i++)
		{
			zoo[i]->show();
			cout << "\t----------------";
			cout << endl;
		}
	}
	void removeAnimal(const string& name) {
		for (size_t i = 0; i < size; ++i) {
			if (zoo[i]->getName() == name) 
			{
				delete zoo[i];
				zoo[i] = zoo[size - 1]; 
				zoo[size - 1] = nullptr;
				size--;
				return;
			}
		}
		cout << "animal not found. . . " << endl;
	}
	void removeAllAnimals() {
		for (size_t i = 0; i < size; ++i) {
			delete zoo[i];
		}
		delete[] zoo;
		zoo = nullptr;
		size = 0;
	}
};


int main()
{
	HomeZoo animal;

	cout << "\n\t* * * ANIMALS * * *\n" << endl;
	animal.addAnimal(new Cat("Smarti", 5));
	animal.addAnimal(new Dog("Jack", 12));
	animal.addAnimal(new Parot("Hunter", 3));
	animal.addAnimal(new Hamster("Sharman", 1));
	animal.addAnimal(new Hamster("Sharman2", 1));

	animal.print();
	cout << "\nAfter removing an animal >>>\n" << endl;
	animal.removeAnimal("Sharman");
	animal.print();
	cout << "\nAfter removing all animals >>>" << endl;
	animal.removeAllAnimals();
	animal.print();
	cout << "zoo is empty. . ."<<endl;

}
