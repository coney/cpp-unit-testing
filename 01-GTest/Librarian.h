#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>

class Librarian {
public:
	unsigned int store(const std::string &name);
	unsigned int borrow(const std::string &name);

private:
	typedef std::set<std::string> BookSet;
	BookSet books_;
};


#endif // __LIBRARIAN_H__
