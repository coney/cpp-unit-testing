#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>
#include <memory>

class Book {
public:
	virtual ~Book();
	virtual const std::string name() const = 0;
	virtual const unsigned int price() const = 0;

	static std::shared_ptr<Book> create(const std::string &name, unsigned int price);
};

#endif
