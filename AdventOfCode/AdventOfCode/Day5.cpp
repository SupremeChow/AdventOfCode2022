#include "Day5.h"

void Day5::day5() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;
	vector<string> inputBoxLevels; // used to read input and determine the given illustrated rows

	bool illustratedPart = true; 
	int numColumns = 0;
	while (illustratedPart){
		getline(inputFile, currentLine);
		if (currentLine[1] == '1') {
			//should now be on row labeling stacks
			illustratedPart = false;

			//get number of columns
			numColumns = stoi(currentLine.substr(currentLine.length() - 2, 1)); //Think there is one space at the end
			cout << numColumns << "\n";
		}
		else {
			inputBoxLevels.push_back(currentLine);
		}
	}

	//clear next line, which should be blank, to prepate to move into directions
	getline(inputFile, currentLine);


	//create vector of stacks
	vector<stack<char>> crateStacks(numColumns);


	//populate stacks

	for (vector<string>::reverse_iterator iter = inputBoxLevels.rbegin(); iter != inputBoxLevels.rend(); iter++) {
		string currentLine = (*iter);
		for (int i = 0; i < numColumns; i++) {
			int index = 1 + (i*4);
			char targetChar = currentLine.at(index);

			if(targetChar != ' ')
				crateStacks[i].push(targetChar);
		}


	}

	//Now loop through rest of input, which should be instructions
	while (getline(inputFile, currentLine)) {
		int numMoves, fromCrate, toCrate;

		numMoves = stoi(currentLine.substr(5, currentLine.find(" from"))); //first 5 positions always 'move '
		fromCrate = stoi(currentLine.substr(currentLine.find("from") + 5, currentLine.find(" to"))) - 1;
		toCrate = stoi(currentLine.substr(currentLine.find("to") + 3, currentLine.size())) - 1;

		while (numMoves != 0 && crateStacks[fromCrate].size() != 0)
		{
			crateStacks[toCrate].push(crateStacks[fromCrate].top());
			crateStacks[fromCrate].pop();
			numMoves--;
		}
	}

	//Now iterate through each stack and print top
	for (int i = 0; i < numColumns; i++) {
		cout << crateStacks[i].top();
	}

}

void Day5::day5Pt2() {
	// Only difference is we will use an extra stack to hold the crates being moved over, to preserve order
	// Technically, the previous code could have been implemented with a queue to move crates between stacks,
	// with the difference being this code is like a single element buffer moving elements one item at a time.

	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;
	vector<string> inputBoxLevels; // used to read input and determine the given illustrated rows

	bool illustratedPart = true;
	int numColumns = 0;
	while (illustratedPart) {
		getline(inputFile, currentLine);
		if (currentLine[1] == '1') {
			//should now be on row labeling stacks
			illustratedPart = false;

			//get number of columns
			numColumns = stoi(currentLine.substr(currentLine.length() - 2, 1)); //Think there is one space at the end
			cout << numColumns << "\n";
		}
		else {
			inputBoxLevels.push_back(currentLine);
		}
	}

	//clear next line, which should be blank, to prepate to move into directions
	getline(inputFile, currentLine);


	//create vector of stacks
	vector<stack<char>> crateStacks(numColumns);
	
	// The new stack for moving crates around
	stack<char> movingStack;


	//populate stacks

	for (vector<string>::reverse_iterator iter = inputBoxLevels.rbegin(); iter != inputBoxLevels.rend(); iter++) {
		string currentLine = (*iter);
		for (int i = 0; i < numColumns; i++) {
			int index = 1 + (i * 4);
			char targetChar = currentLine.at(index);

			if (targetChar != ' ')
				crateStacks[i].push(targetChar);
		}
	}

	//Now loop through rest of input, which should be instructions
	while (getline(inputFile, currentLine)) {
		int numMoves, fromCrate, toCrate;

		numMoves = stoi(currentLine.substr(5, currentLine.find(" from"))); //first 5 positions always 'move '
		fromCrate = stoi(currentLine.substr(currentLine.find("from") + 5, currentLine.find(" to"))) - 1;
		toCrate = stoi(currentLine.substr(currentLine.find("to") + 3, currentLine.size())) - 1;

		//New way, push to intermediate movingStack first, then dump to target stack
		while (numMoves != 0 && crateStacks[fromCrate].size() != 0)
		{
			movingStack.push(crateStacks[fromCrate].top());
			crateStacks[fromCrate].pop();
			numMoves--;
		}
		while (movingStack.size()) {
			crateStacks[toCrate].push(movingStack.top());
			movingStack.pop();
		}
	}

	//Now iterate through each stack and print top
	for (int i = 0; i < numColumns; i++) {
		cout << crateStacks[i].top();
	}
}