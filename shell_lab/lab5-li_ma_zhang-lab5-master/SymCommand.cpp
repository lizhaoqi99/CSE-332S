#include "SymCommand.h"
#include <iostream>
using namespace std;

SymCommand::SymCommand(AbstractFileSystem* fileSys): fs(fileSys){}

int SymCommand::execute(std::string& CWD, std::string options) {
	size_t index = options.find_first_of(' ');
	string fileName = options.substr(0, index);
	string destination = options.substr(index + 1, string::npos);
	AbstractFile* f = fs->openFile(CWD+'/'+fileName);
	if (f != nullptr) {
		fs->closeFile(f);
		Proxy* p = dynamic_cast<Proxy*> (f);	// distinguish between Proxy and other file types
		if (p != nullptr) {		// copy proxy
			Proxy* toAdd = new Proxy(p);
			if (toAdd == nullptr) {
				return directorycannotbecopied;
			}
			fs->addFile(destination, toAdd);
		}
		else {			// add new proxy
			Proxy* toAdd = new Proxy(f);
			if (toAdd == nullptr) {
				return directorycannotbecopied;
			}
			int result = fs->deleteFile(CWD+'/'+fileName);
			fs->addFile(CWD + '/' + fileName, toAdd);	// replace original file with a Proxy
			fs->addFile(destination, new Proxy(toAdd));	// add a Proxy to the destination
		}
		return success;
	}
	else {
		return filedoesnotexist;
	}
}

void SymCommand::displayInfo() {
	cout << "sym will create a symbolic link to an existing file and add the symbolic link to the file system at a given location" << endl;
	cout << "sym <filename> <full_path_to_destination>" << endl;
}