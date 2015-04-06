#ifndef __FILTERENGINE_H__
#define __FILTERENGINE_H__

#include "Book.h"

class RecommendEngine
{
public:
    virtual ~RecommendEngine();
    std::shared_ptr<Book> filter(const BookList &bookList) const;
};

#endif
