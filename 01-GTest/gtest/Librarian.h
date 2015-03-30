#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>

class Librarian {
public:
	unsigned int store(const std::string &name) {
		books_.insert(name);
		return books_.size();
	}

	unsigned int borrow(const std::string &name) {
		throw std::runtime_error("not implemented");
	}
private:
	std::set<std::string> books_;
};


#endif // __LIBRARIAN_H__
