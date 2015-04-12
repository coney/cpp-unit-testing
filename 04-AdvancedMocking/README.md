Advanced Mocking
===========
## Preparation
* 通过git添加新的remote, 指向此repo: `git remote add source https://github.com/coney/cpp-unit-testing.git`
* 从此repo上pull最新代码: `git pull source master`, 合入当前主干
* 打开`04-AdvancedMocking.sln`, 确保现有代码能够正确地被编译和执行

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
    static BookList search(const BookStore &bookStore, const std::string &keyword);
};
```
推荐系统(RecommendEngine)接口声明:
``` c++
class RecommendEngine
{
public:
    virtual std::shared_ptr<Book> filter(const BookList &bookList) const = 0;

    // Engine Control Functions
    virtual const std::string &setEngineParameter(
        const std::string &key, const std::string &value) = 0;
    virtual const std::string &getEngineParameter(const std::string &key) const = 0;
    virtual const std::string &getEngineName() const = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reload() = 0;
    virtual void restart() = 0;
    virtual void loadConfig(const std::string &path) = 0;
};
```

## Stage 1
对`RecommendEngine`及`SearchEngine`进行mock, 并通过依赖注入的方式对`Librarian::recommend()`进行单元测试.

**要求: 不能修改`LibrarianIntegrationSpec.cpp`中的集成测试, 并且要保证该测试通过.**

## Reference
* [Google Mock Cheat Sheet](https://code.google.com/p/googlemock/wiki/CheatSheet)
* [Google Mock Cook Book](https://code.google.com/p/googlemock/wiki/CookBook)

## Summary
* Factory Method & Default Constuctor Parameters
* std::function & std::bind
* Extract Interface & SRP
* Mocking Template Class & std::auto_ptr
* Google Mock Parameter Matchers
* Advanced Google Mock Actions
* Google Mock Sequence
