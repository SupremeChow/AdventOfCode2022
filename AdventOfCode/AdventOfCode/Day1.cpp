#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Day2.h"

int main() {
	/*
	ifstream inputFile;
	inputFile.open("input.txt");
	*/


	//Just iterate and track highest number after newline or eof
	/*
	* 
	int highestNumber = 0;
	int currentNumber = 0;
	string currentLine;

	
	
	while (getline(inputFile, currentLine)) {
		if (currentLine == "") {
			//End of section, compare total to current highest
			highestNumber = currentNumber >= highestNumber ? currentNumber : highestNumber;
			currentNumber = 0;
		}
		else {
			currentNumber += stoi(currentLine);
		}
	}

	// Do a last total check since EOF will break loop before comparing against current highest
	highestNumber = currentNumber >= highestNumber ? currentNumber : highestNumber;

	cout << "\n \n Highest Number: " << highestNumber;

	*/


	//Part 2
	// Do the same thign but with three comparisons. Too lazy to think of something more elegant. O(n) is still n

	/*

	int highestNumber1 = 0;
	int highestNumber2 = 0;
	int highestNumber3 = 0;
	int currentNumber = 0;
	string currentLine;



	while (getline(inputFile, currentLine)) {
		cout << currentLine;
		if (currentLine == "") {
			//End of section, compare total to list of highest
			if (currentNumber >= highestNumber1) {
				//shift numbers down
				highestNumber3 = highestNumber2;
				highestNumber2 = highestNumber1;
				highestNumber1 = currentNumber;
			} 
			else if (currentNumber >= highestNumber2) {
				highestNumber3 = highestNumber2;
				highestNumber2 = currentNumber;
			}
			else if (currentNumber >= highestNumber3) {
				highestNumber3 = currentNumber;
			}
			currentNumber = 0;
		}
		else {
			currentNumber += stoi(currentLine);
		}
	}

	// Do a last total check since EOF will break loop before comparing against current highest
	if (currentNumber >= highestNumber1) {
		//shift numbers down
		highestNumber3 = highestNumber2;
		highestNumber2 = highestNumber1;
		highestNumber1 = currentNumber;
	}
	else if (currentNumber >= highestNumber2) {
		highestNumber3 = highestNumber2;
		highestNumber2 = currentNumber;
	}
	else if (currentNumber >= highestNumber3) {
		highestNumber3 = currentNumber;
	}

	cout << "\n \n The total of top three values is: " << (highestNumber1 + highestNumber2 + highestNumber3);

	*/

	Day2::day2();
	Day2::day2Pt2();

	


}