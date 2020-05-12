#include "CopyCommand.h"
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fileSys) :fs(fileSys) {}

int CopyCommand::execute(std::string& CWD, std::string options) {
	size_t index = options.find_first_of(' ');
	string fileName = options.substr(0, index);
	string destination = options.substr(index + 1, string::npos);
	string d = destination.substr(0, destination.size() - 1);
	AbstractFile* t = fs->openFile(d);
	if (t != nullptr) {
		fs->closeFile(t);
		if (destination.find(".txt/") == string::npos && destination.find(".img/") == string::npos) {
			string fullPath = CWD + '/' + fileName;
			AbstractFile* f = fs->openFile(fullPath);
			AbstractFile* copy = f->clone();
			int result = fs->addFile(destination, copy);
			if (result != success) {
				return result;
			}
			fs->closeFile(f);
			return success;
		}
		else {
			return notadirectory;
		}
	}
	else {
		return filedoesnotexist;
	}
}

void CopyCommand::displayInfo() {
	cout << "copy command will copy a file that exists in the file system and add the copy to the file system in a different location" << endl;
	cout << "Usage: cp <file_to_copy> <full_path_to_destination>" << endl;
}