#include "Day6.h"

void Day6::day6() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	int charPos = 4; //Be sure to return pos + 1 in answer 
	map<char, int> charCount;
	queue<char> buffer;

	getline(inputFile, currentLine);

	//initiate the first 4 chars
	int numRepeats = 0;
	for (int i = 0; i < 4; i++)
	{
		char currentChar = currentLine[i];
		buffer.push(currentChar);
		charCount[currentChar]++;
		if (charCount[currentChar] == 2)
		{
			numRepeats++;
		}
			
	}
	if (numRepeats == 0)
	{
		cout << "Position of message: 4";
		return;
	}

	//Now do same, but iterate through rest of text

	while (charPos != currentLine.size()) {

		//remove queue head from queue and map, check if that removes repeat
		charCount[buffer.front()]--;
		if (charCount[buffer.front()] == 1)
			numRepeats--;
		buffer.pop();

		//enqueue and add to map
		char currentChar = currentLine[charPos];
		buffer.push(currentChar);
		charCount[currentChar]++;
		if (charCount[currentChar] == 2) {
			numRepeats++;
		}

		//Check, if no repeats, return position + 1
		if (numRepeats == 0) {
			cout << "Position of message: " << (charPos + 1);
			return;
		}
		charPos++;
	}
}

void Day6::day6Pt2() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	//Same as previous, except "buffer" size of 14

	int charPos = 14; //Be sure to return pos + 1 in answer 
	map<char, int> charCount;
	queue<char> buffer;

	getline(inputFile, currentLine);

	//initiate the first 4 chars
	int numRepeats = 0;
	for (int i = 0; i < 14; i++)
	{
		char currentChar = currentLine[i];
		buffer.push(currentChar);
		charCount[currentChar]++;
		if (charCount[currentChar] == 2)
		{
			numRepeats++;
		}

	}
	if (numRepeats == 0)
	{
		cout << "Position of message: 14";
		return;
	}

	//Now do same, but iterate through rest of text

	while (charPos != currentLine.size()) {

		//remove queue head from queue and map, check if that removes repeat
		charCount[buffer.front()]--;
		if (charCount[buffer.front()] == 1)
			numRepeats--;
		buffer.pop();

		//enqueue and add to map
		char currentChar = currentLine[charPos];
		buffer.push(currentChar);
		charCount[currentChar]++;
		if (charCount[currentChar] == 2) {
			numRepeats++;
		}

		//Check, if no repeats, return position + 1
		if (numRepeats == 0) {
			cout << "Position of message: " << (charPos + 1);
			return;
		}
		charPos++;
	}

}