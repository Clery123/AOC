#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
int fuel(int mass) {
	if ((mass / 3) - 2 <= 0)
		return 0;
	return (((mass / 3) - 2) + fuel((mass / 3) - 2));
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
