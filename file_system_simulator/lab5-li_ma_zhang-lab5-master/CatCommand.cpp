#include "CatCommand.h"
#include <iostream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fileSys):fs(fileSys) {}

int CatCommand::execute(std::string& CWD, std::string options) {
	if (options.find(".txt") == string::npos && options.find(".img") == string::npos) {
		return filetypecannotappend;
	}
	else {
		if (options.find(" -a") != string::npos) {	// if input contains "-a"
			string fullPath = CWD + '/' + options;
			fullPath = fullPath.substr(0, fullPath.size() - 3);
			AbstractFile* f = fs->openFile(fullPath);
			if (f == nullptr) { // file creation failed
				cout << "failed to open file" << endl;
				return filedoesnotexist;
			}
			vector<char> content = f->read();
			for (auto begin = content.cbegin(); begin != content.cend(); ++begin) {	// get the content of the target file
				if (*begin != '\n') {
					cout << *begin;
				}
				
			}
			cout << '\n' << flush;
			cout << "Please enter your input (Enter ':wq' to append your input, enter ':q' to quit):" << endl;
			string input;
			vector<char> vec;
			getline(cin, input);				// get user inputs
			while (input != ":wq" && input != ":q") {
				vec.push_back('\n'); 
				for (auto begin = input.cbegin(); begin != input.cend(); ++begin) {
					vec.push_back(*begin);
				}
				getline(cin, input);
			}
			if (input == ":wq") {
				f->append(vec);
				fs->closeFile(f);
				return success;
			}
			if (input == ":q") {
				fs->closeFile(f);
				return success;
			}
		}
		else {
			string fullPath = CWD + '/' + options;
			AbstractFile* f = fs->openFile(fullPath);
			if (f == nullptr) { // file creation failed
				cout << "failed to open file" << endl;
				return filedoesnotexist;
			}
			vector<char> content = f->read();
			cout << "Please enter your input (Enter ':wq' to override your input, enter ':q' to quit): " << endl;
			string input;
			vector<char> vec;
			getline(cin, input);// get user inputs
			while (input != ":wq" && input != ":q") {
				if (options.find(".txt") != string::npos) {
					vec.push_back('\n');
				}
				for (auto begin = input.cbegin(); begin != input.cend(); ++begin) {
					vec.push_back(*begin);
				}
				getline(cin, input);
			}
			if (input == ":wq") {
				f->write(vec);
				fs->closeFile(f);
				return success;
			}
			if (input == ":q") {
				fs->closeFile(f);
				return success;
			}
		}
		
	}
	return success;
}

void CatCommand::displayInfo() {
	cout << "cat is a utility that is useful for concatenating files" << endl;
	cout << "Usage: cat <filename> [-a]" << endl;
}