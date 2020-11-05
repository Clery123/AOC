#include<iostream>
#include<fstream>
#include<sstream>
#include <Windows.h>
#include<vector>
#include<thread>
void Intcode(std::vector<int>& opcode, int noun, int verb) {
	opcode[1] = noun;
	opcode[2] = verb;
	for (int i = 0; i < opcode.size(); i += 4) {
		int a = opcode[i + 1];
		int b = opcode[i + 2];
		int c = opcode[i + 3];
		if (opcode[i] == 1)
			opcode[c] = opcode[a] + opcode[b];
		else if (opcode[i] == 2)
			opcode[c] = opcode[a] * opcode[b];
		else if (opcode[i] == 99) {
			return;
			
		}
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
	std::vector< int > storage = allNumbers;
	//allNumbers.push_back(0);
	for (int i = 0; i < 99; i++)
	{
		for (int j = 0; j < 99; j++) {
			
			Intcode(allNumbers, j, i);
			if (allNumbers[0] == 19690720) {
				std::cout << allNumbers[0] << "\n";
				std::cout << i << "FOUND IT " << j;
			}
			allNumbers = storage;
		}

	}	
	MyreadFile.close();
}
