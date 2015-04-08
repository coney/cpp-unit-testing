Stubs & Mocks
===========
## Preparation
* 通过git添加新的remote, 指向此repo: `git remote add source https://github.com/coney/cpp-unit-testing.git`
* 从此repo上pull最新代码: `git pull source master`, 合入当前主干
* 打开`03-Decoupling.sln`, 确保现有代码能够正确地被编译和执行

## Problem
为了更好的服务读者, 图书馆引进了图书查询(SearchEngine)和推荐系统(RecommendEngine):

1. 管理员会使用查询和推荐系统根据读者提供的关键字推荐一本书
2. 查询系统会查询并返回所有包含指定关键字的书籍
3. 推荐系统会选择并返回查询结果中最流行的一本书

推荐系统(SearchEngine)接口声明:
``` c++
class SearchEngine
{
public:
    static BookList search(
			const BookStore &bookStore,
			const std::string &keyword);
};
```
推荐系统(RecommendEngine)接口声明:
``` c++
class RecommendEngine
{
public:
    virtual std::shared_ptr<Book> filter(
			const BookList &bookList) const;
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
