Stubs & Mocks
===========
## Preparation
* 通过git添加新的remote, 指向此repo: `git remote add source https://github.com/coney/cpp-unit-testing.git`
* 从此repo上pull最新代码: `git pull source master`, 合入当前主干
* 打开`02-GMock.sln`, 确保现有代码能够正确地被编译和执行

## Problem
图书馆管理员(Librarian)会定期向书商(BookVendor)购买一些书籍来充实图书馆:

1. 书商能够提供多种图书(附有价格)供管理员进行选择
2. 管理员仅会挑选当前图书馆中不存在的书籍进行购买
3. 管理员选好图书后, 会向书商支付所选书籍的总金额

书商(BookVendor)和书籍(Book)的声明为:
``` c++
class Book {
public:
	virtual const std::string name() const = 0;
	virtual const unsigned int price() const = 0;
};
```
``` c++
class BookVendor {
public:
	virtual std::shared_ptr<Book> getBookAt(unsigned int index) const = 0;
	virtual unsigned int getBookCount() const = 0;
  virtual void pay(unsigned int price) = 0;
};
```

图书馆管理员需要新增`store`方法, 用于从书商处进书
``` c++
class Librarian {
public:
	void store(BookVendor &vendor);
};
```

## Stage 1
需求中引入了新的依赖`Book`, 首先对`Librarian`进行重构, 使`Librarian`可以通过`store`方法保存一本图书`Book`, 即实现:
``` c++
class Librarian {
public:
	unsigned int store(const std::shared_ptr<Book> &book);
};
```
## Stage 2
构造`BookVendor`的Mock类`BookVendorMock`, 通过控制`BookVendorMock`使`vendor`可以提供一个稳定的书籍列表.

完成测试`LibrarianSpec.ShouldStoreBooksWhichAreNotCurrentlyInLibraryFromVendor`并实现业务逻辑.

## Stage 3
对`BookVendorMock::pay`, 设置期望, 检验传入参数及调用次数.

完成测试`LibrarianSpec.ShouldPayVendorForTheStoredBooks`并实现业务逻辑.

## Reference
* [Google Mock For Dummies](https://code.google.com/p/googlemock/wiki/ForDummies)
* [Google Mock Cheat Sheet](https://code.google.com/p/googlemock/wiki/CheatSheet)
* [Google Mock Cook Book](https://code.google.com/p/googlemock/wiki/CookBook)
* [Google Mock FAQ](https://code.google.com/p/googlemock/wiki/FrequentlyAskedQuestions)

## Summary
* Google Mock
* Stubs & Mocks
* std::shared_ptr
