#include "gtest/gtest.h"

#include "Book.h"

TEST(Book, ShouldCamelizeBookName) {
	ASSERT_EQ("Hello World", Book("Hello World").getName());
	ASSERT_EQ("Hello World", Book("HELLO WORLD").getName());
	ASSERT_EQ("Hello World", Book("hello world").getName());
}