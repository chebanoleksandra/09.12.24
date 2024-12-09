#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char str[100];
	cout << "Enter text:\n";
	cin.getline(str, 100);

	ofstream write("MyFile.txt");
	write << str << endl;
	write.close();

	ifstream read("MyFile.txt");

}