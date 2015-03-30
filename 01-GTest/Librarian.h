#ifndef __LIBRARIAN_H__
#define __LIBRARIAN_H__

#include <set>
#include <string>

class Librarian {
public:
	unsigned int store(const std::string &name) {
		books_.insert(name);
		return books_.size();
	}

	unsigned int borrow(const std::string &name) {
		BookSet::const_iterator it = books_.find(name);
		if (it == books_.end()) {
			throw std::runtime_error(name + " is not available");
		}
		else {
			books_.erase(it);
			return books_.size();
		}
	}
private:
	typedef std::set<std::string> BookSet;
	BookSet books_;
};


#endif // __LIBRARIAN_H__
