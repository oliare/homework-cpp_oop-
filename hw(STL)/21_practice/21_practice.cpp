#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename ContType>
void print(const ContType& cont, const string& prompt = "") {
	cout << prompt << endl;
	cout << "\t";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}cout << endl;
}

int main()
{
	
	vector<int> v1;
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	// рекомендую ввести хоча б одне парне число, аби перевірити на роботу пункт 5 
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++) {
		int el;
		cin >> el;
		v1.push_back(el);
	}
	cout << endl;
	print(v1, "Print v1 :: ");

	vector<int> v2(10, 0);
	print(v2, "Print v2 :: ");

	int n3;
	cout << "Enter the number of elements: ";
	cin >> n3;
	vector<int> v3;
	srand(time(0));
	for (int i = 0; i < n3; i++)
	{
		v3.push_back(rand() % 50);
	}
	print(v3, "Print v3 :: ");

	vector<int> v4(v1.begin(), v1.end());
	print(v4, "Print v4 :: ");

	vector<int> v5(v3.begin() + 1, v3.end() - 1);
	print(v5, "Print v5 :: ");

	////
	cout << "\n\t< < < TASK 2 > > > \n" << endl;
	cout << "v3 elements :: ";
	for (auto itt = v3.rbegin(); itt != v3.rend(); itt++)
	{
		cout << *itt << "\t";
	}

	ofstream file("Numbers.txt");
	if (!file.is_open())
	{
		cout << "Error";
	}
	for (auto itt = v1.rbegin(); itt != v1.rend(); itt++)
	{
		file << *itt << " ";
	}
	cout << "\n* data entered into the file" << endl;
	file.close();

	////
	cout << "\n\t< < < TASK 3 > > > \n" << endl;
	v2.clear();
	cout << "Print v2 :: ";
	for (int i = 1; i <= 10; i++)
	{
		v2.push_back(i);
		cout << i << "\t";
	}
	v2.pop_back();
	v2.erase(v2.begin() + 1);
	print(v2, "\nPrint v2 :: ");

	////
	cout << "\n\t< < < TASK 4 > > > \n" << endl;
	for (auto it = v4.begin(); it != v4.end(); it++)
	{
		cout << *it << " " << *it << "\t";
	}
	cout << endl;

	////
	cout << "\n\t< < < TASK 5 > > > \n" << endl;
	v5.clear();
	for (auto it = v4.begin(); it != v4.end(); it++)
	{
		if (*it % 2 == 0)
		{
			v5.push_back(*it / 2);
		}
	}
	for (auto elements : v5)
	{
		cout << elements << "\t";
	}
	cout << endl;

	////
	cout << "\n\t< < < TASK 6 > > > \n" << endl;
	vector<int> v{2, 5, 4, 6, 2, 5, 10, 5};
	int value = 5;
	auto it = find(v.begin(), v.end(), 5);
	while (it != v.end())
	{
		cout << "value -> " << *it << "\tindex -> " << it - v.begin() << endl;
		it = find(it + 1, v.end(), value);
	}
	cout << "Count of value ' " << value << " ' : " << count(v.begin(), v.end(), value)<< endl;
	
	////
	cout << "\n\t< < < TASK 7 > > > \n" << endl;

	cout << "Before swap >> \nv4 :: " << v4.size() << " elements" << endl;
	cout << "v5 :: " << v5.size()<<" elements" << endl;;
	cout << "\nAfter swap >> "<<endl;
	swap(v4, v5);

	cout << "v4 :: " << v4.size()<<" elements" << endl;
	for (auto it = v4.begin(); it != v4.end(); it++)
	{
		cout << *it << "\t";
	}

	cout << "\n\nv5 :: " << v5.size()<<" elements" << endl;;
	for (auto it = v5.begin(); it != v5.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl <<endl;
	
	cout << "\n\t\tPART II \n" << endl;
	const size_t size = 10;
	vector<vector<int>> table(size, vector<int>(size));

	for (size_t i = 1; i <= size; i++)
	{
		for (size_t j = 1; j <= size; j++)
		{
			table[i - 1][j - 1] = i * j;
		}
	}

	for (auto el : table) 
	{
		for (size_t vector : el) 
		{
			cout << vector << "\t";
		}
		cout << endl;
	}

}