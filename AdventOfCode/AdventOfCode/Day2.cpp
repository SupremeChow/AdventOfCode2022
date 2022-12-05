#include  "Day2.h"

void Day2::day2() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;
	char char1, char2;

	map<char, char> opponentHand;
	opponentHand['A'] = 'X';
	opponentHand['B'] = 'Y';
	opponentHand['C'] = 'Z';

	map<char, int> handScore;
	handScore['X'] = 1;
	handScore['Y'] = 2;
	handScore['Z'] = 3;

	int totalScore = 0;
	while (getline(inputFile, currentLine)) {
		char1 = currentLine[0];
		char2 = currentLine[2];


		totalScore += handScore[char2];

		if (opponentHand[char1] == char2) {
			//Draw
			totalScore += 3;
		}
		else {
			switch (char2) {
			case 'X':
				if (opponentHand[char1] == 'Z')
					totalScore += 6;
				break;
			case 'Y':
				if (opponentHand[char1] == 'X')
					totalScore += 6;
				break;
			case 'Z':
				if (opponentHand[char1] == 'Y')
					totalScore += 6;
				break;
			}
		}
		
	}

	cout << "Total Score: " << totalScore << '\n';
}

void Day2::day2Pt2() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;
	char char1, char2;

	map<char, char> opponentHand;
	opponentHand['A'] = 'X';
	opponentHand['B'] = 'Y';
	opponentHand['C'] = 'Z';

	map<char, int> matchScore;
	matchScore['X'] = 0;
	matchScore['Y'] = 3;
	matchScore['Z'] = 6;

	map<char, int> handScore;
	handScore['X'] = 1;
	handScore['Y'] = 2;
	handScore['Z'] = 3;

	int totalScore = 0;
	while (getline(inputFile, currentLine)) {
		char1 = currentLine[0];
		char2 = currentLine[2];


		totalScore += matchScore[char2];

		if (char2 == 'Y') {
			//Draw
			totalScore += handScore[opponentHand[char1]];
		}
		else if (char2 == 'X') {
			switch (opponentHand[char1]) {
			case 'X':
					totalScore += 3;
				break;
			case 'Y':
					totalScore += 1;
				break;
			case 'Z':
					totalScore += 2;
				break;
			}
		}
		else {
			switch (opponentHand[char1]) {
			case 'X':
				totalScore += 2;
				break;
			case 'Y':
				totalScore += 3;
				break;
			case 'Z':
				totalScore += 1;
				break;
			}
		}

	}

	cout << "Total Score New Strat: " << totalScore << '\n';
}

