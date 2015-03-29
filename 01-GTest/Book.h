#ifndef __BOOK_H__
#define __BOOK_H__

class Book {
public:
	Book(const std::string &name) {
		setName(name);
	}

	std::string getName() const {
		return name_; 
	}
	void setName(std::string val) {
		name_ = val;
		bool firstChar = true;
		for (auto &c : name_) {
			if (isalpha(c)) {
				if (firstChar) {
					firstChar = false;
					c = toupper(c);
				}
				else {
					c = tolower(c);
				}
			}
			else {
				firstChar = true;
			}
		}
	}
private:
	std::string name_;
};

#endif // __BOOK_H__
