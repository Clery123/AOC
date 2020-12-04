#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
void Intcode(std::vector<int>& opcode) {
	for (int i = 0; i < opcode.size(); i+=4) {
		int a = opcode[i + 1];
		int b = opcode[i + 2];
		int c = opcode[i + 3];
		if (opcode[i]==1) 
			opcode[c] = opcode[a] + opcode[b];
		else if (opcode[i] == 2) 
			opcode[c] = opcode[a] * opcode[b];
		else if (opcode[i] >= 3) 
			return;
	}
}

int main(void) 
{
	std::string value;
	std::ifstream MyreadFile("data.txt");
	std::vector< int > allNumbers;
	std::string number = "";
	int num=0;
	std::getline(MyreadFile, value);

	for (char x : value) {
		if (x != ',')
			number += x;
		else {
			std::stringstream n(number);
			n >> num;
			allNumbers.push_back(num);
			number = "";
		}
	}
	//allNumbers.push_back(0);
	Intcode(allNumbers);
	for (int x : allNumbers)
		std::cout << x<<" ";
	MyreadFile.close();
}
