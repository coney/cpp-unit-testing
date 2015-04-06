#ifndef __BOOKVENDORMOCK_H__
#define __BOOKVENDORMOCK_H__

#include "../src/BookVendor.h"

class BookVendorMock : public BookVendor {
public:
    virtual ~BookVendorMock() {}
    MOCK_CONST_METHOD0(getBooks, BookList());
    MOCK_METHOD1(pay, void(unsigned int price));
};

#endif
