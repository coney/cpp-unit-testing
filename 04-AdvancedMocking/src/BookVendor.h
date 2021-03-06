#ifndef __BOOKVENDOR_H__
#define __BOOKVENDOR_H__

#include "Book.h"

class BookVendor {
public:
    virtual ~BookVendor();
    virtual std::shared_ptr<Book> getBookAt(unsigned int index) const = 0;
    virtual unsigned int getBookCount() const = 0;
    virtual void pay(unsigned int price) = 0;

    // generate BookVendor with random books
    static std::shared_ptr<BookVendor> create();
};

#endif
