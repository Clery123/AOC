#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<sstream>
#include <Windows.h>
#include<vector>
#include<stdio.h>
#include<thread>
#include<math.h>
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
	std::string value1;
	std::string value2;
	std::ifstream MyreadFile("data1.txt");
	int(*erej)[22000] = new int[22000][22000];
	std::fill(erej[0], erej[0] + 22000 * 22000, 0);
	int centralPointX = 5;
	int centralPointY = 5;
	int currentX = 8001;
	int currentY = 8001;
	char direction=' ';
	int distance;

	std::getline(MyreadFile, value1);
	std::getline(MyreadFile, value2);
	std::string stringica = "";
	int firstIteration = 1;
	for (char x : value1) {
		if (x != ',' and isdigit(x)) {
			stringica += x;
		}
		if (x != ',' and isalpha(x))
			direction = x;
		else if(x == ',') {
			std::stringstream n(stringica);
			n >> distance;
			if (direction == 'R') {
				for (int i = currentX; i < currentX + distance-firstIteration; i++) {
					erej[i][currentY-1] = 1;
				}
				//std::fill(erej[currentX], erej[currentX] + direction * 1, true);
				currentX += distance-firstIteration;
				firstIteration = 0;
			}
			if (direction == 'L') {
				for (int i = currentX-distance-1; i < currentX; i++) {
					erej[i][currentY-1] = 1;
				}
				//std::fill(erej[currentX], erej[currentX] - direction * 0, true);
				currentX -= distance;
			}
			if (direction == 'U') {
				for (int i = currentY-distance-1; i < currentY; i++) {
					erej[currentX-1][i] = 1;
				}
				//std::fill(&erej[currentX][currentY], &erej[currentX][currentY+distance], true);
				currentY -= distance;
			}
			if(direction =='D'){
				for (int i = currentY; i < currentY + distance; i++) {
					erej[currentX-1][i] = 1;
				}
				//std::fill(erej[currentX],erej[currentX] - 0 *direction ,true);
				currentY += distance;
			}

			stringica = "";
			distance = 0;

		}
		
	}






	currentX = 8001;
	firstIteration = 1;
	currentY = 8001;
	for (char x : value2) {
		if (x != ',' and isdigit(x)) {
			stringica += x;
		}
		if (x != ',' and isalpha(x))
			direction = x;
		else if (x == ',') {
			std::stringstream n(stringica);
			n >> distance;
			if (direction == 'R') {
				for (int i = currentX; i < currentX + distance; i++) {
					if (erej[i][currentY - 1] == 1)
						erej[i][currentY - 1] = 3;
					else
						erej[i][currentY - 1] = 2;
				}
				//std::fill(erej[currentX], erej[currentX] + direction * 1, true);
				currentX += distance;
			}
			if (direction == 'L') {
				for (int i = currentX - distance-1+firstIteration; i < currentX; i++) {
					if (erej[i][currentY - 1] == 1)
						erej[i][currentY - 1] = 3;
					else
						erej[i][currentY - 1] = 2;
				}
				//std::fill(erej[currentX], erej[currentX] - direction * 0, true);
				currentX -= distance-firstIteration;
				firstIteration = 0;
			}
			if (direction == 'U') {
				for (int i = currentY - distance - 1; i < currentY; i++) {
					if (erej[currentX - 1][i] == 1)
						erej[currentX - 1][i] = 3;
					else
						erej[currentX - 1][i] = 2;
				}
				//std::fill(&erej[currentX][currentY], &erej[currentX][currentY+distance], true);
				currentY -= distance;
			}
			if (direction == 'D') {
				for (int i = currentY; i < currentY + distance; i++) {
					if (erej[currentX - 1][i] == 1)
						erej[currentX - 1][i] = 3;
					else
						erej[currentX - 1][i] = 2;
				}
				//std::fill(erej[currentX],erej[currentX] - 0 *direction ,true);
				currentY += distance;
			}

			stringica = "";
			distance = 0;

		}

	}

	int temp = 999999;
	for (int a = 0; a <= 19999; a++) {
		for (int b = 0; b <= 19999; b++) {
			if (erej[b][a] == 3) {
				int lulX = 0;
				int lulY = 0;
				std::cout << "X: " << a << " Y: " << b;
				if (b > 8000)
					lulX = b - 8000;
				else
					lulX = 8000 - b;
				if (a > 8000)
					lulY = a - 8000;
				else
					lulY = 8000 - a;

				if (lulX + lulY < temp) {
					temp = lulX + lulY;
					std::cout <<"\nSuradnice: "<< a << "___" << b << "\n";
				}
			}	
		}
	}

	std::cout <<"\n\n"<<temp << "\n";

	/*for (int a = 0; a <= 19; a++) {
		for (int b = 0; b <= 19; b++) {
			//if (erej[a][b] == true) {
			std::cout << erej[b][a];
			if (b == 19)
				std::cout << std::endl;
			
			//}
		}
	}*/
	delete[] erej;
	MyreadFile.close();
}
