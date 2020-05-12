/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "LSCommand.h"
#include "ReadFileVisitor.h"
#include<iostream>
#include "ReadMetadataFileVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem * fileSys) : fs(fileSys) {}

int LSCommand::execute(std::string& CWD, std::string options) {
	AbstractFile* f = fs->openFile(CWD);
	if (f == nullptr) { // file creation failed
		cout << "failed to open directory" << endl;
		return directorydoesnotexist;
	}
	else if (options == "-l") {
		vector<char> contents = f->read();
		string filename = CWD + "/";
		size_t next_start;
		for (next_start = 0; next_start < contents.size(); ++next_start) {
			if (contents[next_start] != '\n') {
				filename += contents[next_start];
			}
			else {
				AbstractFile* file = fs->openFile(filename);
				ReadMetadataFileVisitor visitor;
				file->accept(&visitor);
				fs->closeFile(file);
				filename = CWD + "/";
			}
		}
		fs->closeFile(f);
		return success;
	}
	else {
		ReadFileVisitor reader;
		f->accept(&reader);
		fs->closeFile(f);
		return success;
	}
}
void LSCommand::displayInfo() {
	cout << "lists the contents of the current directory" << endl;
	cout << "Usage: ls" << endl;
}