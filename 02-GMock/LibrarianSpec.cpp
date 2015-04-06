#include "gmock/gmock.h"
#include "Librarian.h"

class LibrarianSpec : public testing::Test {
protected:
    virtual void SetUp() {
    }

    void prepareBooks()
    {
        librarian.store("C++ Primer");
        librarian.store("The C++ Programming Language");
        librarian.store("Thinking in Java");
    }

    virtual void TearDown() {
    }

    Librarian librarian;
};

TEST_F(LibrarianSpec, ShouldIncreaseBookCountOnStore) {
    ASSERT_EQ(1, librarian.store("The C Programming Language"));
    ASSERT_EQ(2, librarian.store("Thinking in Java"));
}

TEST_F(LibrarianSpec, ShouldReduceBookCountOnBorrow) {
    prepareBooks();
    ASSERT_EQ(2, librarian.borrow("Thinking in Java"));
    ASSERT_EQ(1, librarian.borrow("C++ Primer"));
    ASSERT_EQ(0, librarian.borrow("The C++ Programming Language"));
}

TEST_F(LibrarianSpec, ShouldThrowExceptionWhenNoBookIsAvailable) {
    prepareBooks();
    ASSERT_THROW({
        librarian.borrow("Learning Python");
    }, std::invalid_argument);
}