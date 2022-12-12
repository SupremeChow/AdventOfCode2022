#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>


using namespace std;
class Day7
{
private:
public:
	static void day7();
	static void day7Pt2();
};

class Directory {
private:
	
	Directory* parent;
	map<string, Directory*> subDirectories;
	int dataSize; //For this level directory only, child directory data should be calculated
	string name;
public:
	static int totalFileSize; // use this to report the final output
	static set<int> mappedTotalSizeDir; // Used in Pt2 to calculate minimum sized Dir needed to prune
	Directory();
	Directory(string newName, Directory* newParent);

	void addDirectory(string newDirName, Directory* newDirectory);
	void addFile(int fileSize);

	string getName();


	//Recursively checks number of child Directories that are below maxFileSize. 
	//Returns pair, first value number of valid Directories (called directory included), second is totalFileSize (useful for knowing when to stop checking)
	pair<int, int> checkNumValidSubDir(int maxFileSize); 

	Directory* cd(string targetDir);
	Directory* cdBack();

	void listDirs(int level);

	void initTotal();
	int getTotal();

};



