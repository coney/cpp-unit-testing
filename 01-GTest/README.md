Introduction To Google Test
===========
## Preparation
* 安装Visual Studio 2012以上版本(最好配套安装Visual Assist)
* 安装git客户端, Git教程请参考 [Git Tutorial](https://www.gitbook.com/book/lvwzhen/git-tutorial/)
* fork此repo至个人账号下, 并通过git客户端clone代码到本地
* 打开`01-GTest.sln`, 确保现有代码能够正确地被编译和执行(请忽略失败的测试用例)

## Problem
某图书馆有一名图书管理员(Librarian), 他能够帮助图书馆进行存书(Store), 并且向我们提供借书服务(borrow):

1. 当管理员存书后, 他会告诉我们当前图书馆的现存图书数量
2. 当向管理员借书后, 他会告诉我们当前图书馆的剩余图书数量
3. 当向管理员借书时, 如果馆内没有这本书, 则抛出异常

管理员(Librarian)的声明为:
``` c++
class Librarian {
public:
	unsigned int store(const std::string &name);
	unsigned int borrow(const std::string &name);
};
```

## Stage 1
阅读代码逻辑和测试用例, 实现`Librarian::borrow`, 使用例`LibrarianSpec.ShouldIncreaseBookCountOnStore`通过

## Stage 2
* 编写测试用例`LibrarianSpec.ShouldThrowExceptionWhenNoBookIsAvailable`, 覆盖需求点3
* 编译并运行用例, 确保没有编译错误并且用例为失败状态
* 完善`Librarian::borrow`, 使刚刚编写的测试用例通过

## Stage 3
* 通过继承`testing::Test`, 创建Fixture `LibrarianSpec`
* 将准备数据的`Librarian::store`代码放入`LibrarianSpec::SetUp`中
* 通过`TEST_F`重构所有测试用例

## Reference
* [Google Test Primer](https://code.google.com/p/googletest/wiki/Primer)
* [Google Test Advanced Guide](https://code.google.com/p/googletest/wiki/AdvancedGuide)
* [Google Test FAQ](https://code.google.com/p/googletest/wiki/FAQ)


## Summary
* Google Test
* Test Assertions
* TDD
* Test Fixture
