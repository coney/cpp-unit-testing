#include "SearchEngine.h"

SearchEngine::~SearchEngine()
{
}

std::list<std::shared_ptr<Book>> SearchEngine::search(
    const BookStore &bookStore, const std::string &keyword) 
{
    BookList bookList;
    for (BookStore::const_iterator it = bookStore.begin();
        it != bookStore.end(); ++it) {
        if (it->first.find(keyword) != std::string::npos) {
            bookList.push_back(it->second);
        }
    }
    return bookList;
}
