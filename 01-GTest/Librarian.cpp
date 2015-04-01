#include "Librarian.h"

unsigned int Librarian::store(const std::string &name)
{
	books_.insert(name);
	return books_.size();
}

unsigned int Librarian::borrow(const std::string &name)
{
	BookSet::const_iterator it = books_.find(name);
	if (it == books_.end()) {
		throw std::invalid_argument(name + " is not available");
	}
	else {
		books_.erase(it);
		return books_.size();
	}
}
