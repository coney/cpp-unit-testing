#ifndef __RECOMMENDENGINEMOCK_H__
#define __RECOMMENDENGINEMOCK_H__

#include "gmock/gmock.h"
class IRecommendEngineMock : public IRecommendEngine {
public:
    virtual ~IRecommendEngineMock() {}
    MOCK_CONST_METHOD1(filter, std::shared_ptr<Book>(const BookList &bookList));
};

#endif
