#include "Day4.h"

void Day4::day4() {

	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine, lhs, rhs;

	int low1, low2, high1, high2;
	int lowestNum; //use to define which has lowest range, ie low (1) or low (2). 
	int highestNum; //use to define which has highest range, ie high (1) or high (2). 
	int numOverlap = 0;

	while (getline(inputFile, currentLine)) {
		lhs = currentLine.substr(0, currentLine.find(","));
		rhs = currentLine.substr(currentLine.find(',')+1, currentLine.length());

		low1 = stoi(lhs.substr(0, lhs.find("-")));
		high1 = stoi(lhs.substr(lhs.find("-")+1, lhs.length()));

		low2 = stoi(rhs.substr(0, rhs.find("-")));
		high2 = stoi(rhs.substr(rhs.find("-") + 1, rhs.length()));

		//lows
		if (low1 == low2) {
			//no need to check, if both same one will always cover the other
			numOverlap++;
			continue;
		}
		else {
			lowestNum = low1 < low2 ? 1 : 2;
		}

		//highs
		if (high1 == high2) {
			//no need to check, if both same one will always cover the other
			numOverlap++;
			continue;
		}
		else {
			highestNum = high1 > high2 ? 1 : 2;
		}

		//final check
		if (lowestNum == highestNum) {
			numOverlap++;
		}

	}
	cout << "total full overlap: " << numOverlap;
}

void Day4::day4Pt2() {

	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine, lhs, rhs;

	int low1, low2, high1, high2;
	int lowestNum; //use to define which has lowest range, ie low (1) or low (2). 
	int highestLow, lowestHigh;
	int highestNum; //use to define which has highest range, ie high (1) or high (2). 
	int numOverlap = 0;

	while (getline(inputFile, currentLine)) {
		//cout << "current Total: " << numOverlap << "     ::     ";
		lhs = currentLine.substr(0, currentLine.find(","));
		rhs = currentLine.substr(currentLine.find(',') + 1, currentLine.length());

		low1 = stoi(lhs.substr(0, lhs.find("-")));
		high1 = stoi(lhs.substr(lhs.find("-") + 1, lhs.length()));

		low2 = stoi(rhs.substr(0, rhs.find("-")));
		high2 = stoi(rhs.substr(rhs.find("-") + 1, rhs.length()));

		//lows
		if (low1 == low2) {
			//no need to check, if both same one will always cover the other
			numOverlap++;
			continue;
		}
		else {
			lowestNum = low1 < low2 ? 1 : 2;
			highestLow = low1 < low2 ? 2 : 1;

			switch (highestLow) {
			case 1: 
				if (low1 <= high2) {
					numOverlap++;
					continue;
					
				}
				break;
			case 2:
				if (low2 <= high1) {
					numOverlap++;
					continue;
				}
				break;
			}
		}

		//highs
		if (high1 == high2) {
			//no need to check, if both same one will always cover the other
			numOverlap++;
			continue;
		}
		else {
			highestNum = high1 > high2 ? 1 : 2;
			lowestHigh = high1 > high2 ? 2 : 1;
		}

		//final check (redundant in this part)
		if (lowestNum == highestNum) {
			numOverlap++;
		}
		
	}
	cout << "total partial full overlap: " << numOverlap;

}