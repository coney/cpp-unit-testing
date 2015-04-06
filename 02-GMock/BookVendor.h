#ifndef __BOOKVENDOR_H__
#define __BOOKVENDOR_H__

#include "Book.h"

class BookVendor {
public:
	virtual ~BookVendor();
	virtual std::shared_ptr<Book> getBook(unsigned int index) const = 0;
	virtual unsigned int bookCount() const = 0;

	static std::shared_ptr<BookVendor> create();
};

#endif
