/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
*/

#include "RemoveCommand.h"
#include "Proxy.h"
#include<iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fileSys) : fs(fileSys) {}

// removes a file from the current working directory
int RemoveCommand::execute(std::string& CWD, std::string options) {
	string fullPath = CWD;
	if (options.find("-r") != string::npos) {
		auto index = options.find(" -r");
		string path = options.substr(0, options.size() - 3);
		fullPath += '/';
		fullPath += path;
		AbstractFile* a = fs->openFile(fullPath);
		Proxy* p = dynamic_cast<Proxy*> (a);
		fs->closeFile(a);
		if (p != nullptr) {
			fs->deleteFile(fullPath);
			p->~Proxy();
			return success;
		}
		int result = fs->deleteFile(fullPath);
		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		else if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		else if (result == AbstractFileSystem::directorynotempty) {
			AbstractFile* file = fs->openFile(fullPath);
			vector<char> contents = file->read();
			size_t next_start;
			string filename;
			for (next_start = 0; next_start < contents.size(); ++next_start) {
				if (contents[next_start] != '\n') {
					filename += contents[next_start];
				}
				else {
					filename += " -r";
					execute(fullPath, filename);
					filename = "";
				}
			}
			fs->closeFile(file);
			fs->deleteFile(fullPath);
			return success;
		}
		else {
			return success;
		}
	}
	else {
		fullPath += '/';
		fullPath += options;
		AbstractFile* a = fs->openFile(fullPath);
		Proxy* p = dynamic_cast<Proxy*> (a);
		fs->closeFile(a);
		if (p != nullptr) {
			fs->deleteFile(fullPath);
			p->~Proxy();
			return success;
		}
		int result = fs->deleteFile(fullPath);
		if (result == AbstractFileSystem::filedoesnotexist) {
			cout << "File does not exist" << endl;
			return filedoesnotexist;
		}
		else if (result == AbstractFileSystem::fileisopen) {
			cout << "File is currently in use" << endl;
			return fileinuse;
		}
		else if (result == AbstractFileSystem::directorynotempty) {
			cout << "Directory isn't empty." << endl;
			return directorynotempty;
		} 
		return success;
	}
}
void RemoveCommand::displayInfo() {
	cout << "touch removes a file from the file system and then deletes the file" << endl;
	cout << "Usage: rm <filename>" << endl;
}