#ifndef __RECOMMENDENGINEMOCK_H__
#define __RECOMMENDENGINEMOCK_H__

#include <gmock/gmock.h>
#include "../src/RecommendEngine.h"

class RecommendEngineMock : public RecommendEngine {
public:
    virtual ~RecommendEngineMock() {}
    MOCK_CONST_METHOD1(filter, std::shared_ptr<Book>(const BookList &bookList));
};

#endif
