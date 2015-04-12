#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <functional>
#include "Book.h"
#include "BookVendor.h"
#include "SearchEngine.h"
#include "RecommendEngine.h"

class Librarian {
    typedef std::function<BookList(const BookStore&, const std::string &)> searchFn;
public:
    Librarian(std::shared_ptr<IRecommendEngine>
        recommendEngine = RecommendEngine::create(),
        searchFn searcher = SearchEngine::search);
    unsigned int store(const std::shared_ptr<Book>& book);
    unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

    std::shared_ptr<Book> recommend(const std::string &keyword);

private:
    searchFn bookSearcher_;
    std::shared_ptr<IRecommendEngine> recommendEngine_;
    BookStore books_;
};


#endif // __LIBRARIAN_H__
