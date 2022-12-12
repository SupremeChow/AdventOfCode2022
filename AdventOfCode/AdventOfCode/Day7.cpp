#include "Day7.h"

//Static Member init (assume used to ensure that data is init even if Directory isn't used)
int Directory::totalFileSize = 0;
set<int> Directory::mappedTotalSizeDir;

void Day7::day7() {
	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	Directory* root = new Directory("/", nullptr);
	Directory* currentDir = root;

	//Iterate through commands
	while (getline(inputFile, currentLine)) {
		if (currentLine[0] == '$') {
			//Command being issued
			switch (currentLine[2]) {
				//cd command
				case 'c':
					if (currentLine[5] == '.') {
						//Think we can safely assume if the dir starts with '.', its always '..'
						currentDir = currentDir->cdBack();
					}
					else if (currentLine[5] == '/') {
						//Think we can safely assume if the dir starts with / will be jump back to root
						currentDir = root;
					}
					else {
						string targetDir = currentLine.substr(5, currentLine.size() - 5);
						currentDir = currentDir->cd(targetDir);
					}
					break;
				//ls command (we will do nothing for this)
				case 'l':
					break;
			}
		}
		else {
			//listing dir and files
			if (currentLine.substr(0, 3) == "dir") {
				//listing a directory, add to current dir's list
				string directoryName = currentLine.substr(4, currentLine.size() - 4);
				Directory* newDir = new Directory(directoryName, currentDir);
				currentDir->addDirectory(directoryName, newDir);
			}
			else {
				//listing a file
				int fileSize = stoi(currentLine.substr(0, currentLine.find(' ')));
				currentDir->addFile(fileSize);
				//Don't need the file name in this instance. Otherwise, get it here and implement
			}
		}
	}

	/*cout << "\n\n\n Printing Dirs \n\n";
	root->listDirs(1);*/

	//Now call checkNumValidSubDir() at root
	cout << "\n\n \n starting check... \n\n";
	pair<int, int> checkTreeResult = root->checkNumValidSubDir(100000);
	cout << "\n\n Resulting number of prunable dirs: " << checkTreeResult.first;
	cout << "\n\n Resulting Total Size of prunable dirs: " << root->getTotal();
}

void Day7::day7Pt2() {

	//My guess is to now keep track of individual dir sizes as it bubbles up from recursion.
	//Then, iterate to find the lowest filesize that will meet the necesseary difference

	ifstream inputFile;
	inputFile.open("input.txt");
	string currentLine;

	Directory* root = new Directory("/", nullptr);
	Directory* currentDir = root;

	//Iterate through commands
	while (getline(inputFile, currentLine)) {
		if (currentLine[0] == '$') {
			//Command being issued
			switch (currentLine[2]) {
				//cd command
			case 'c':
				if (currentLine[5] == '.') {
					//Think we can safely assume if the dir starts with '.', its always '..'
					currentDir = currentDir->cdBack();
				}
				else if (currentLine[5] == '/') {
					//Think we can safely assume if the dir starts with / will be jump back to root
					currentDir = root;
				}
				else {
					string targetDir = currentLine.substr(5, currentLine.size() - 5);
					currentDir = currentDir->cd(targetDir);
				}
				break;
				//ls command (we will do nothing for this)
			case 'l':
				break;
			}
		}
		else {
			//listing dir and files
			if (currentLine.substr(0, 3) == "dir") {
				//listing a directory, add to current dir's list
				string directoryName = currentLine.substr(4, currentLine.size() - 4);
				Directory* newDir = new Directory(directoryName, currentDir);
				currentDir->addDirectory(directoryName, newDir);
			}
			else {
				//listing a file
				int fileSize = stoi(currentLine.substr(0, currentLine.find(' ')));
				currentDir->addFile(fileSize);
				//Don't need the file name in this instance. Otherwise, get it here and implement
			}
		}
	}

	/*cout << "\n\n\n Printing Dirs \n\n";
	root->listDirs(1);*/

	//Now call checkNumValidSubDir() at root
	cout << "\n\n \n starting check... \n\n";
	pair<int, int> checkTreeResult = root->checkNumValidSubDir(100000);
	cout << "\n\n Resulting number of prunable dirs: " << checkTreeResult.first;
	cout << "\n\n Total Dir Size: " << checkTreeResult.second;

	int totalDirSize = checkTreeResult.second;
	cout << "\n\n Resulting Total Size of prunable dirs: " << root->getTotal() << "\n";

	//Calculate the ammount of free space needed
	int TOTAL_DISK = 70000000;
	int NEEDED_SPACE = 30000000;

	int NEEDED_ADDITIONAL_SPACE = NEEDED_SPACE - (TOTAL_DISK - totalDirSize);
	cout << "Target spaced to prune to: " << NEEDED_ADDITIONAL_SPACE << "\n";

	//iterate through Directory::mappedTotalSizeDir and find minimum needed size
	int targetMin = TOTAL_DISK;
	for (auto iter = Directory::mappedTotalSizeDir.begin(); iter != Directory::mappedTotalSizeDir.end(); iter++) {
		if ((*iter) >= NEEDED_ADDITIONAL_SPACE && (*iter) <= targetMin) {
			targetMin = (*iter);
		}
	}

	cout << "\n\n Smallest size of Dir to remove to meet target: " << targetMin;
}



// ------------------- Directory --------------------------------

Directory::Directory() {
	name = "";
	parent = nullptr;
	dataSize = 0;
}

Directory::Directory(string newName, Directory* newParent) {
	name = newName;
	parent = newParent;
	dataSize = 0;
}

void Directory::addDirectory(string newDirName, Directory* newDirectory) {
	subDirectories[newDirName] = newDirectory;
}

void Directory::addFile(int fileSize) {
	dataSize += fileSize;
}

string Directory::getName() {
	return name;
}

pair<int, int> Directory::checkNumValidSubDir(int maxFileSize) {
	int totalSize = 0;
	int numValidChildDir = 0;
	for (auto iter = subDirectories.begin(); iter != subDirectories.end(); iter++) {
		pair<int, int> result = ((*iter).second)->checkNumValidSubDir(maxFileSize);
		numValidChildDir += result.first;
		totalSize += result.second;
	}
	if ((totalSize + dataSize) <= maxFileSize) {
		Directory::totalFileSize += totalSize + dataSize;
		Directory::mappedTotalSizeDir.insert(totalSize + dataSize); //map this dir's actual total size, for pt2
		return pair <int, int> (numValidChildDir + 1, totalSize + dataSize);
	}
	else {
		Directory::mappedTotalSizeDir.insert(totalSize + dataSize); //map this dir's actual total size, for pt2
		return pair <int, int>(numValidChildDir, totalSize + dataSize);
	}
		
}

Directory* Directory::cd(string targetDir) {
	return subDirectories[targetDir];
}

Directory* Directory::cdBack() {
	return parent;
}

void Directory::initTotal() {
	Directory::totalFileSize = 0;
}
int Directory::getTotal() {
	return Directory::totalFileSize;
}

//Helper function to show directories

void Directory::listDirs(int level) {
	cout << "\n";
	for (int i = 1; i < level; i++) {
		cout << "  ";
	}
	cout << " | -- ";
	cout << name << " : " << dataSize;
	for (auto iter = subDirectories.begin(); iter != subDirectories.end(); iter++) {
		(*iter).second->listDirs(level + 1);
	}

}

