Dependency Injection & Decoupling
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
阅读代码, 了解`SearchEngine`, `RecommendEngine`原理及`Librarian`对查询推荐系统的使用方式.

修改`RecommendEngine`的推荐算法, 选择最便宜的书进行推荐.

## Stage 2
重构代码, 将`RecommendEngine`通过构造函数注入到`Librarian`中.

编写并使用`RecommendEngineMock`测试`Librarian::recommend()`.

## Stage 3
重构代码, 通过Adapter注入`SearchEngine`, 并使用`SearchEngineMock`测试`Librarian::recommend()`

## Reference
* [Inversion of Control Containers and the Dependency Injection pattern](http://www.martinfowler.com/articles/injection.html)
* [深度理解依赖注入](http://www.cnblogs.com/xingyukun/archive/2007/10/20/931331.html)

## Summary
* Dependency Injection
* Decoupling & Refactoring
* Testable Design
