#include "gtest/gtest.h"
#include "Librarian.h"

class LibrarianSpec : public testing::Test {
protected:
	virtual void SetUp() {
		librarian.store("C++ Primer");
		librarian.store("The C++ Programming Language");
		librarian.store("Thinking in Java");
	}

	virtual void TearDown() {
	}
	Librarian librarian;
};

TEST_F(LibrarianSpec, ShouldIncreaseBookCountOnStore) {
	ASSERT_EQ(4, librarian.store("C++ Primer Plus"));
	ASSERT_EQ(5, librarian.store("The C Programming Language"));
}

TEST_F(LibrarianSpec, ShouldReduceBookCountOnBorrow) {
	ASSERT_EQ(2, librarian.borrow("Thinking in Java"));
	ASSERT_EQ(1, librarian.borrow("C++ Primer"));
	ASSERT_EQ(0, librarian.borrow("The C++ Programming Language"));

}

TEST_F(LibrarianSpec, ShouldThrowExceptionWhenNoBookIsAvailable) {
	// how to assert an exception, look up the document
	ASSERT_THROW({
		librarian.borrow("Learning Python");
	}, std::invalid_argument);
}