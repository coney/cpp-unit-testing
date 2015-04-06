#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>
#include <map>
#include "BookVendor.h"

class Librarian {
public:
	unsigned int store(const std::shared_ptr<Book>& book);
	unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

private:
	typedef std::map<std::string, std::shared_ptr<Book>> Books;
	Books books_;
};


#endif // __LIBRARIAN_H__
