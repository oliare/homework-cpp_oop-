#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Shape
{
public:
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};

class Square : public Shape
{
	double x, y, sideLen;
public:
	Square(const double x, const double y, const double sideLen)
		:x{ x }, y{ y }, sideLen{ sideLen }
	{}
	void Show() override {
		cout << "\n\t * Square Data *" << "\ncoordinates - (" << x << ", " << y << ")\tside - " << sideLen << endl;
	}
	void Save() override {
		ofstream file("data.txt", ios::ate);
		file << "* Square" << "\ncoordinates - (" << x << ", " << y << ")\tside - " << sideLen << endl;
		file.close();
	};
	void Load() override {
		ifstream file("data.txt");
		double x, y, sideLen;

		if (!file.is_open())
		{
			cout << "ERROR" << endl;
		}
		file >> x >> y >> sideLen;
	}
};

class Rectangle : public Shape
{
	double x, y, width, height;
public:
	Rectangle(const double x, const double y, const double w, const double h)
		: x{ x }, y{ y }, width{ w }, height{ h } {}
	void Show() override {
		cout << "\n\n\t * Rectangle Data *" << "\ncoordinates - (" << x << ", " << y << ")\twidth - " << width << "  height - " << height << endl;
	}
	void Save() override {
		ofstream file("data.txt", ios::app);
		file << "\n* Rectangle" << "\ncoordinates - (" << x << ", " << y << ")\twidth - " << width << "  height - " << height << endl;
		file.close();
	};
	void Load() override {
		ifstream file("data.txt");
		double x, y, width, height;

		if (!file.is_open())
		{
			cout << "ERROR" << endl;
		}
		file >> x >> y >> width >> height;
	}
};

class Circle : public Shape
{
	double x, y, radius;
public:
	Circle(const double x, const double y, const double r)
		: x{ x }, y{ y }, radius{ r } {}
	void Show() override {
		cout << "\n\n\t * Circle Data  *" << "\ncenter - (" << x << ", " << y << ")\tradius - " << radius << endl;
	}
	void Save() override {
		ofstream file("data.txt", ios::app);
		file << "\n* Circle" << "\ncenter - (" << x << ", " << y << ")\tradius - " << radius << endl;
		file.close();
	};
	void Load() override {
		ifstream file("data.txt");
		double x, y, radius;

		if (!file.is_open())
		{
			cout << "ERROR" << endl;
		}
		file >> x >> y >> radius;
	}
};

class Ellipse : public Shape
{
	double x, y, w, h;
public:
	Ellipse(const double x, const double y, const double w, const double h)
		: x{ x }, y{ y }, w{ w }, h{ h }
	{}
	void Show() override {
		cout << "\n\n\t * Ellipse Data *" << "\ncoordinates - (" << x << ", " << y << ")\twidth - " << w << "  height - " << h << endl << endl;
	}
	void Save() override {
		ofstream file("data.txt", ios::app);
		file << "\n* Ellipse" << "\ncoordinates - (" << x << ", " << y << ")\twidth - " << w << "  height - " << h << endl;
		file.close();
	};
	void Load() override {
		ifstream file("data.txt");
		double x, y, w, h;

		if (!file.is_open())
		{
			cout << "ERROR" << endl;
		}
		file >> x >> y >> w >> h;
	}
};


int main()
{

	vector<Shape*> shapes;
	shapes.push_back(new Square(5, 3, 13));
	shapes.push_back(new Rectangle(7, 2, 12, 3));
	shapes.push_back(new Circle(16, 16, 7));
	shapes.push_back(new Ellipse(5, 6, 9, 10));


	for (Shape* item : shapes)
	{
		item->Save();
	}
	for (Shape* item : shapes)
	{
		item->Load();
	}
	for (Shape* item : shapes)
	{
		item->Show();
	}
	for (Shape* item : shapes) {
		delete item;
	}
	shapes.clear();

}
