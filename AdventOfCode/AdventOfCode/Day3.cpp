#include "Day3.h"

void Day3::day3() {
	map<char, int> priority = { {'a',1},{'b',2}, {'c',3}, {'d',4},
		{'e',5}, {'f',6}, {'g',7}, {'h',8}, {'i',9}, {'j',10}, {'k',11},
		{'l',12}, {'m',13}, {'n',14}, {'o',15}, {'p',16}, {'q',17}, {'r',18}, {'s',19},
		{'t',20}, {'u',21}, {'v',22}, {'w',23}, {'x',24}, {'y',25}, {'z',26},
		{'A',27},{'B',28}, {'C',29}, {'D',30},
		{'E',31}, {'F',32}, {'G',33}, {'H',34}, {'I',35}, {'J',36}, {'K',37},
		{'L',38}, {'M',39}, {'N',40}, {'O',41}, {'P',42}, {'Q',43}, {'R',44}, {'S',45},
		{'T',46}, {'U',47}, {'V',48}, {'W',49}, {'X',50}, {'Y',51}, {'Z',52},

	};
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	unordered_set<char> set1, set2;

	char duplicateChar;
	int totalPriorities = 0;


	while (getline(inputFile, currentLine)) {
		for (int i = 0, j = ((currentLine.length()) / 2); i < (currentLine.length()) / 2; i++, j++) {
			set1.insert(currentLine[i]);
			set2.insert(currentLine[j]);
		}
		for (unordered_set<char>::iterator it = set1.begin(); it != set1.end(); it++) {
			if (set2.count(*it) > 0) {
				duplicateChar = *it;
				cout << "Duplcate is: " << duplicateChar << " with score: " << priority[duplicateChar] << "\n";
				break;
			}
		}
		totalPriorities += priority[duplicateChar];
		cout << "Total: " << totalPriorities << "\n";
		set1.clear();
		set2.clear();
	}

	cout << "Total Priority Value: " << totalPriorities << "\n";

}

void Day3::day3Pt2() {

	map<char, int> priority = { {'a',1},{'b',2}, {'c',3}, {'d',4},
		{'e',5}, {'f',6}, {'g',7}, {'h',8}, {'i',9}, {'j',10}, {'k',11},
		{'l',12}, {'m',13}, {'n',14}, {'o',15}, {'p',16}, {'q',17}, {'r',18}, {'s',19},
		{'t',20}, {'u',21}, {'v',22}, {'w',23}, {'x',24}, {'y',25}, {'z',26},
		{'A',27},{'B',28}, {'C',29}, {'D',30},
		{'E',31}, {'F',32}, {'G',33}, {'H',34}, {'I',35}, {'J',36}, {'K',37},
		{'L',38}, {'M',39}, {'N',40}, {'O',41}, {'P',42}, {'Q',43}, {'R',44}, {'S',45},
		{'T',46}, {'U',47}, {'V',48}, {'W',49}, {'X',50}, {'Y',51}, {'Z',52},

	};
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	unordered_set<char> set1, set2, set3;

	char duplicateChar;
	int totalPriorities = 0;

	while (!inputFile.eof()) {
		getline(inputFile, currentLine);
		if (currentLine == "") {
			//edge case where at last line, so should break early
			cout << "Breaking early, eof \n";
			break;
		}
		for (int i = 0; i < (currentLine.length()); i++) {
			set1.insert(currentLine[i]);
		}
		getline(inputFile, currentLine);
		for (int i = 0; i < (currentLine.length()); i++) {
			set2.insert(currentLine[i]);
		}
		getline(inputFile, currentLine);
		for (int i = 0; i < (currentLine.length()); i++) {
			set3.insert(currentLine[i]);
		}

		for (unordered_set<char>::iterator it = set1.begin(); it != set1.end(); it++) {
			if (set2.count(*it) > 0 && set3.count(*it) > 0) {
				duplicateChar = *it;
				cout << "Duplcate is: " << duplicateChar << " with score: " << priority[duplicateChar] << "\n";
				break;
			}
		}
		totalPriorities += priority[duplicateChar];
		cout << "Total: " << totalPriorities << "\n";
		set1.clear();
		set2.clear();
		set3.clear();
	}
	cout << "Total Priority pt2 Value: " << totalPriorities << "\n";

}