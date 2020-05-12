#include "DisplayCommand.h"
#include <iostream>
#include "ReadFileVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) :fs(fileSys) {}

int DisplayCommand::execute(std::string& CWD, std::string options) {
	if (options.find(".txt") == string::npos && options.find(".img") == string::npos) {
		return filetypecannotappend;
	}
	else {
		if (options.find(" -d") == string::npos) {	// if input doesn't contains "-d", formatted
			string fullPath = CWD + '/' + options;
			AbstractFile* f = fs->openFile(fullPath);
			if (f == nullptr) { // file creation failed
				cout << "failed to open file" << endl;
				return filedoesnotexist;
			}
			ReadFileVisitor* visitor = new ReadFileVisitor;
			f->accept(visitor);
			fs->closeFile(f);
			delete visitor;
			return success;
		}
		else {
			string fullPath = CWD + '/' + options;
			fullPath = fullPath.substr(0, fullPath.size() - 3);
			AbstractFile* f = fs->openFile(fullPath);
			if (f == nullptr) { // file creation failed
				cout << "failed to open file" << endl;
				return filedoesnotexist;
			}
			vector<char> content = f->read();
			
			for (auto begin = content.cbegin(); begin != content.cend(); ++begin) {	// get the content of the target text file
				if (*begin != '\n') {
					cout << *begin;
				}
			}
			cout << endl;
			fs->closeFile(f);
			return success;
		}
	}
}

void DisplayCommand::displayInfo() {
	cout << "display opens a file and displays its contents, either formatted or not" << endl;
	cout << "Usage: ds <filename> [-d]" << endl;
}