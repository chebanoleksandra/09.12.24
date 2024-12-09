#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student() = default;
	Student(const char* n, const char* s, int a)
	{
		name = n;
		surname = s;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << "\nSurname: " << surname << "\nAge: " << age << endl;
	}
	void SaveFile()
	{
		ofstream write;
		write.open("StudentFile.txt", ios::out | ios::app);
		write << name << " " << surname << " " << age << " y. o.\n";
		write.close();
	}
	void ReadFile()
	{
		ifstream read("StudentFile.txt");
		if (read)
		{
			const int size = 100;
			do
			{
				char buff[size] = {};
				read.getline(buff, size);
				cout << buff << endl;
			} while (read);
			read.close();
		}
		else
		{
			cout << "Could not open the file" << endl;
		}
	}
};

int main()
{
	/*char str[100];
	cout << "Enter text:\n";
	cin.getline(str, 100);

	ofstream write("MyFile.txt");
	write << str << endl;
	write.close();

	ifstream read("MyFile.txt");
	char buff[10];
	while (!read.eof())
	{
		read >> buff;
		cout << buff << " ";
	}
	read.close();*/

	Student sasha("Oleksandra", "Cheban", 16);
	sasha.Print();
	sasha.SaveFile();

	Student sofia("Sofia", "Cheban", 12);
	sofia.SaveFile();

	sofia.ReadFile();
}