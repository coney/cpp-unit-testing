#include <gmock/gmock.h>
#include "BookVendor.h"

TEST(BookVendor, ShouldReturnVendorWithRandomBooksToSupply) {
	std::shared_ptr<BookVendor> vendor = BookVendor::create();
	ASSERT_GT(vendor->bookCount(), 0U);
	for (size_t i = 0; i < vendor->bookCount(); i++)
	{
		std::shared_ptr<Book> book = vendor->getBook(i);
		ASSERT_FALSE(book->name().empty());
		ASSERT_GT(book->price(), 0U);
	}
}