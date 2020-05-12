#pragma once
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include <iostream>

class Proxy : public AbstractFile {
	// friends
	friend class HierarchicalFileSystem;
	friend class SimpleFileSystem;

public:
	Proxy(AbstractFile* file);	
	Proxy(Proxy* proxy);
	virtual int write(std::vector<char> v) override; // re-writes file
	virtual int append(std::vector<char> v) override; // appends to current contents
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual AbstractFile* clone() override;

	virtual ~Proxy();

	virtual std::vector<char> read() override;
	// visitor pattern function
	virtual void accept(AbstractFileVisitor* visitor) override;

protected:
	// composite pattern functions, should only be used by file system objects or command objects which should be friended
	virtual int addChild(AbstractFile* f) override;
	virtual int removeChild(std::string name) override;
	virtual void setParent(AbstractFile* f) override;
	virtual AbstractFile* getChild(std::string name) override;
	virtual AbstractFile* getParent() override;
	AbstractFile* getFile();

private:
	std::string proxyName;
	AbstractFile* parent;
	AbstractFile* realObj;
	int* count;
};