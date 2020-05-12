#include "Proxy.h"

using namespace std;

Proxy::Proxy(AbstractFile* file): realObj(nullptr), parent(nullptr) {
	proxyName = file->getName();
	count = new int{};
	(*count)++;
	cout << "link count after a new proxy is created: " << *count << endl;
	realObj = file;
}

Proxy::Proxy(Proxy* proxy) : realObj(nullptr), parent(nullptr) {
	proxyName = proxy->getName();
	(*(proxy->count))++;
	count = proxy->count;

	cout << "link count after a copy proxy is created: " << *(proxy->count) << " another proxy count: " << *count << endl;
	realObj = proxy->realObj;
}

AbstractFile* Proxy::getFile() {
	return realObj;
}

int Proxy::write(std::vector<char> v) {
	return getFile()->write(v);
}

int Proxy::append(std::vector<char> v) {
	return getFile()->append(v);
}

unsigned int Proxy::getSize() {
	return getFile()->getSize();
}

AbstractFile* Proxy::clone() {
	return getFile()->clone();
}

std::string Proxy::getName() {
	return proxyName;
}

std::vector<char> Proxy::read() {
	return getFile()->read();
}

void Proxy::accept(AbstractFileVisitor* visitor) {
	getFile()->accept(visitor);
	return;
}

int Proxy::addChild(AbstractFile* f) {
	return getFile()->addChild(f);
}

int Proxy::removeChild(std::string name) {
	return getFile()->removeChild(name);
}

void Proxy::setParent(AbstractFile* f) {
	parent = f;
	return;
}

AbstractFile* Proxy::getChild(std::string name) {
	return getFile()->getChild(name);
}

AbstractFile* Proxy::getParent() {
	return parent;
}

Proxy::~Proxy() {
	(*count)--;
	cout << "link count after rm a proxy: " << *count << endl;
	if ((*count) == 0) {
		(*realObj).~AbstractFile();	// delete the real object
		realObj = nullptr;
		parent = nullptr;
	}
	else {
		realObj = nullptr;
		parent = nullptr;
	}
}