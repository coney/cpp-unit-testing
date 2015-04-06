#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <functional>
#include "Book.h"
#include "BookVendor.h"
#include "SearchEngine.h"
#include "RecommendEngine.h"

class Librarian {
public:
    typedef std::function<BookList(const BookStore &, const std::string &)> BookSearchFn;
    Librarian(const BookSearchFn &searchFn = SearchEngine::search, 
        const std::shared_ptr<RecommendEngine> &recommendEngine = std::make_shared<RecommendEngine>())
        :recommendEngine_(recommendEngine), searchFn_(searchFn) {

    }
	unsigned int store(const std::shared_ptr<Book>& book);
	unsigned int borrow(const std::string &name);
    void store(BookVendor &vendor);

    std::shared_ptr<Book> recommend(const std::string &keyword);

private:
    BookSearchFn searchFn_;
    std::shared_ptr<RecommendEngine> recommendEngine_;
	BookStore books_;
};


#endif // __LIBRARIAN_H__
