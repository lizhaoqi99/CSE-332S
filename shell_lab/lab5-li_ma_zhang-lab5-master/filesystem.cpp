/*
Author: Jon Shidal
Purpose: CSE 332 lab 5
filesystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include <iostream>
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include<algorithm>
#include<iterator>
#include "ReadFileVisitor.h"
#include "HierarchicalFileSystem.h"
#include "HierarchicalFileFactory.h"
#include "CommandPrompt.h"
#include "TouchCommand.h"
#include "CDCommand.h"
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "CatCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "SymCommand.h"

using namespace std;

int main(int argc, char * arg[])
{
	// allocate all objects needed
	AbstractFileFactory* ff = new HierarchicalFileFactory();
	AbstractFileSystem *fs = new HierarchicalFileSystem();
	AbstractCommand* com = new TouchCommand(ff,fs);
	AbstractCommand* com1 = new CDCommand(fs);
	AbstractCommand* com2 = new LSCommand(fs);
	AbstractCommand* com3 = new RemoveCommand(fs);
	AbstractCommand* com4 = new CatCommand(fs);
	AbstractCommand* com5 = new DisplayCommand(fs);
	AbstractCommand* com6 = new CopyCommand(fs);
	AbstractCommand* com7 = new SymCommand(fs);

	AbstractFile* dir1 = new DirectoryFile("dir1");
	AbstractFile* dir2 = new DirectoryFile("dir2");
	AbstractFile* dir3 = new DirectoryFile("dir3");
	AbstractFile* text = new TextFile("text.txt");
	AbstractFile* img = new ImageFile("img.img");
	vector<char> vec1 = { 'a', 'b', 'c', '\n', 'd', 'e', 'f' };
	vector<char> vec2 = { 'X', ' ', 'X', 'X', '2' };
	text->write(vec1);
	img->write(vec2);
	fs->addFile("root/", dir1);
	fs->addFile("root/dir1/", dir2);
	fs->addFile("root/dir1/", img);
	fs->addFile("root/dir1/", text);
	fs->addFile("root/dir1/dir2/", dir3);
	//fs->openFile("root/dir1/img.img");
	// create command prompt and configure
	// NOTE: the above commands will not work with a SimpleFileSystem, it would need a new set of commands
	// or a second CommandPrompt class
	CommandPrompt cmd;
	cmd.setFileSystem(fs);
	cmd.setFileFactory(ff);
	cmd.addCommand("touch", com);
	cmd.addCommand("cd", com1);
	cmd.addCommand("ls", com2);
	cmd.addCommand("rm", com3);
	cmd.addCommand("rm -r", com3);
	cmd.addCommand("cat", com4);
	cmd.addCommand("cat -a", com4);
	cmd.addCommand("ds", com5);
	cmd.addCommand("ds -d", com5);
	cmd.addCommand("cp", com6);
	cmd.addCommand("sym", com7);
	// run the command prompt
	cmd.run();

	// clean up dynamically allocated resources
	delete ff;
	delete fs; // all files are destroyed here (in the file system destructor)
	delete com;
	delete com1;
	delete com2;
	delete com3;
	delete com4;
	delete com5;
	delete com6;
	delete com7;

	return 0;
}

