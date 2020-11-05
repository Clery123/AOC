#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
int fuel(int mass) {
	int fuelNeed;
	return fuelNeed = (mass / 3) - 2;
}

int main(void) 
{
	std::string value;
	int alltogether = 0;
	int number;
	std::ifstream MyreadFile("data.txt");
	while (std::getline(MyreadFile, value)) {
		std::stringstream x(value);
		x >> number;
		alltogether += fuel(number);
	}
	std::cout << alltogether;
	MyreadFile.close();
}
