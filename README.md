![Supported Platforms](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20Mac%20OS-green.svg)
[![Build Status](https://travis-ci.org/downdemo/Design-Patterns-in-Cpp17.svg?branch=master)](https://travis-ci.org/downdemo/Design-Patterns-in-Cpp17)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/LICENSE)

## Build

* [C++17 is required](https://en.cppreference.com/w/cpp/17), Windows, Mac OS and Linux are supported, build by [CMake](https://cmake.org/download/)

```
git clone git@github.com:downdemo/Design-Patterns-in-Cpp17.git
cd Design-Patterns-in-Cpp17
cmake . -Bbuild
cd build
cmake --build .
```

## 设计模式简介

* 设计模式的概念最初源自建筑行业，建筑师 Christopher Alexander 曾这样解释过模式的概念：“总会有一类问题在我们身边反复出现，模式就是针对这一类问题的通用解法。当问题反复出现时，直接套用这个解法即可，而不需要去重新解决问题。”

> Each pattern describes a problem which occurs over and over again in our environment, and then describes the core of the solution to that problem, in such a way that you can use this solution a million times over, without ever doing it the same way twice.

* 后来，模式的思想也被引入了软件工程领域，[软件工程](https://book.douban.com/subject/6047742/)中提出了以下设计原则，设计模式也遵循了这些原则
  * 开闭原则（The Open-Closed Principle，OCP）：对扩展开放，对修改关闭。修改程序时，不需要修改类内部代码就可以扩展类的功能，如[装饰器模式](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/decorator.cpp)
  * Liskov 替换原则（Liskov Substitution Principle，LSP）：任何基类出现的地方，都可以用派生类替换
  * 依赖倒置原则（Dependency Inversion Principle，DIP）：针对接口（纯虚函数）编程，而非针对实现编程
  * 接口分离原则（Interface Segregation Principle，ISP）：接口功能的粒度应该尽可能小，多个功能分离的小接口、单个合并了这些功能的大接口，前者是更好的做法，因为这样降低了依赖，耦合度更低
  * 发布复用等价性原则（Release Reuse Equivalency Principle，REP）：复用的粒度就是发布的粒度。第三方库的作者需要维护每个版本，作者可以修改代码，但是用户不需要了解源码的变化，而可以自由选择使用哪个版本的库，因此库作者应该将可复用的类打包成包，以包为单位来更新，而不是更新每个类，比如 [Boost](https://www.boost.org/) 有一个版本号，而其中的每个子部分（如 [Boost.Asio](https://www.boost.org/doc/libs/1_79_0/doc/html/boost_asio.html)）又有各自独立的版本号
  * 共同封装原则（Common Closure Principle，CCP）：一同变更的类应该合在一起，如果一些类处理相同的功能或行为域，那么这些类应该根据内聚性分到一组打包，这样需要修改某个域的功能时，只需要修改这个包中的代码
  * 共同复用原则（Common Reuse Principle，CRP）：不能一起被复用的类不能被分到一组。当包中的类变化时，包的版本号也会变化，如果不相关的类被分到一组，就会导致本来无必要的包的版本升级，为此又需要进行本来无必要的集成和测试
* 设计模式是从已有的软件设计中，针对重复出现的问题提取出的一套经验论，其概念源自 [*Design Patterns: Elements of Reusable Object-Oriented Software*](https://www.oreilly.com/library/view/design-patterns-elements/0201633612/)，此书由四人合著，因此简称 GoF（Gang of Four）。GoF 总结归纳了 23 种设计模式，分为创建型（Creational）、结构型（Structural）、行为型（Behavioral）三类。设计模式的思想在编程世界中很常见，如 [C#](https://docs.microsoft.com/en-us/dotnet/csharp/) 的委托与事件、[Qt](https://doc.qt.io/) 的信号槽、[RxJS](https://github.com/ReactiveX/rxjs) 的响应式编程本质都是[观察者模式](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/observer.cpp)

|创建型模式|中文名|说明|实现|
|:-|:-|:-|:-|
|Abstract Factory/Kit|抽象工厂模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/creational_pattern/abstract_factory.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/abstract_factory.cpp)|
|Builder|建造者模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/creational_pattern/builder.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/builder.cpp)|
|Factory Method/Virutal Contructor|工厂方法模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/creational_pattern/factory_method.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/factory_method.cpp)|
|Prototype|原型模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/creational_pattern/prototype.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/prototype.cpp)|
|Singleton|单例模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/creational_pattern/singleton.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/singleton.cpp)|

|结构型模式|中文名|说明|实现|
|:-|:-|:-|:-|
|Adapter/Wrapper|适配器模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/adapter.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/adapter.cpp)|
|Bridge/Handle/Body|桥接模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/bridge.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/bridge.cpp)|
|Composite|组合模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/composite.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/composite.cpp)|
|Decorator/Wrapper|装饰器模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/decorator.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/decorator.cpp)|
|Facade|外观模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/facade.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/facade.cpp)|
|Flyweight|享元模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/flyweight.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/flyweight.cpp)|
|Proxy/Surrogate|代理模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/structural_pattern/proxy.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/proxy.cpp)|

|行为型模式|中文名|说明|实现|
|:-|:-|:-|:-|
|Chain of Responsibility|责任链模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/chain_of_responsibility.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/chain_of_responsibility.cpp)|
|Command/Action/Transaction|命令模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/command.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/command.cpp)|
|Interpreter|解释器模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/interpreter.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/interpreter.cpp)|
|Iterator/Cursor|迭代器模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/iterator.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/iterator.cpp)|
|Mediator|中介者模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/mediator.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/mediator.cpp)|
|Memento/Token|备忘录模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/memento.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/memento.cpp)|
|Observer/Dependents/Publish-Subscribe|观察者模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/observer.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/observer.cpp)|
|State/Objects for States|状态模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/state.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/state.cpp)|
|Strategy/Policy|策略模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/strategy.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/strategy.cpp)|
|Template Method|模板方法模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/template_method.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/template_method.cpp)|
|Visitor|访问者模式|[README](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/docs/behavioral_pattern/visitor.md)|[C++](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/visitor.cpp)|

## C++ 中的设计模式

* 设计模式并非十全十美，一些模式本质就意味着高耦合（如[观察者模式](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/observer.cpp)），用 C++ 实现时要注意正确管理资源生命周期，避免内存泄漏
* C++11 引入了 [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr)、[std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)、[std::weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr) 三种智能指针来解决原始指针生命周期管理困难的痛点，此项目通过使用它们来避免内存泄漏，以深入理解三者的使用场景及其区别。需要注意的是，实际工程可能需要考虑更多问题（如线程安全、智能指针的额外开销、代码可读性），应当避免滥用智能指针（同理也应当避免滥用设计模式）
* 使用智能指针并不意味着一定没有内存泄漏，比如循环引用的情况（实现[观察者模式](https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/observer.cpp)时容易写出类似代码）

```cpp
class B;

class A {
 public:
  std::shared_ptr<B> b;
  ~A() { std::cout << "Destroy A\n"; }
};

class B {
 public:
  std::shared_ptr<A> a;
  ~B() { std::cout << "Destroy B\n"; }
};

int main() {
  {
    auto p = std::make_shared<A>();
    p->b = std::make_shared<B>();
    p->b->a = p;
    assert(p.use_count() == 2);
  }  // p 的引用计数由 2 减为 1，不会析构
     // 于是 p->b 也不会析构，导致两次内存泄漏
}
```

* 分析 [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr) 的生命周期，适当使用 [std::weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr) 即可避免此类情况

```cpp
class B;

class A {
 public:
  std::shared_ptr<B> b;
  ~A() { std::cout << "Destroy A\n"; }
};

class B {
 public:
  std::weak_ptr<A> a;
  ~B() { std::cout << "Destroy B\n"; }
};

int main() {
  {
    auto p = std::make_shared<A>();
    p->b = std::make_shared<B>();
    p->b->a = p;  // weak_ptr 不增加 shared_ptr 的引用计数
    assert(p.use_count() == 1);
  }  // Destroy A
     // Destroy B
}
```

### 检测内存泄漏的方法

* 开发环境使用 [Visual Studio](https://visualstudio.microsoft.com/zh-hans/?rr=https%3A%2F%2Fcn.bing.com%2F)
* 在程序结束点调用 [_CrtDumpMemoryLeaks()](https://docs.microsoft.com/zh-cn/previous-versions/d41t22sb(v=vs.120)?redirectedfrom=MSDN)

```cpp
#include <crtdbg.h>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main() {
  int* p = new int(42);
  _CrtDumpMemoryLeaks();
}
```

* 调试时将提示第 9 行产生 4 字节的内存泄漏

```
Detected memory leaks!
Dumping objects ->
xxx.cpp(9) : {88} normal block at 0x008C92D0, 4 bytes long.
 Data: <*   > 2A 00 00 00 
Object dump complete.
```

* 这种方法的原理是，在执行此函数时，检查所有未回收的内存，因此存在析构函数还未执行而误报的情况

```cpp
#include <crtdbg.h>

#include <memory>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main() {
  auto p = std::make_shared<int>(42);
  _CrtDumpMemoryLeaks();  // 此时 std::shared_ptr 还未析构，因此报告内存泄漏
}
```

* 更好的方法是在开始点使用 [_CrtSetDbgFlag()](https://docs.microsoft.com/zh-cn/previous-versions/5at7yxcs(v=vs.120)?redirectedfrom=MSDN)，它在程序退出时调用 [_CrtDumpMemoryLeaks()](https://docs.microsoft.com/zh-cn/previous-versions/d41t22sb(v=vs.120)?redirectedfrom=MSDN)

```cpp
#include <crtdbg.h>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main() {
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
  int* p = new int(42);
}
```

* 该项目中的源码使用上述方式检测均无内存泄漏
* 为了尽可能简单，所有代码均以单个源文件的形式实现
* 源码中未使用平台相关 API，因此在任何支持 C++17 标准的平台均可通过编译

### 智能指针的传参方式选择

* 以下两种传参方式，应该如何选择？

```cpp
void f(std::shared_ptr<A> p);         // 按值传递
void f(const std::shared_ptr<A>& p);  // 按 const 引用传递
```

* 不同的传参方式表达了不同的语义，通常情况下，按 const 引用传递是最稳妥且没有心智负担的

```cpp
void f(A&);  // 仅使用对象，不涉及对象资源所有权的管理
void f(A*);  // 仅使用对象，不涉及对象资源所有权的管理

void f(std::unique_ptr<A>);  // 用于转移唯一所有权（用 std::move 传入）
void f(std::unique_ptr<A>&);        // 用于重置内部对象
void f(const std::unique_ptr<A>&);  // 不如直接传引用或原始指针

void f(std::shared_ptr<A>);   // 引用计数共享
                              // 可用 std::move 传入 std::unique_ptr 实参
void f(std::shared_ptr<A>&);  // 引用计数不变，用于重置内部对象
                              // 不可接受 std::unique_ptr 实参
void f(const std::shared_ptr<A>&);  // 引用计数不变，不可重置内部对象
                                    // 可用 std::move 传入 std::unique_ptr 实参
```

* 对于按值传递，只在之后一定会对其拷贝的场景才可能考虑使用

```cpp
void f(const std::shared_ptr<A>& p) {
  auto q = p;  // 拷贝 p
  // ...
}
```
* 如果按值传递，拷贝可以改用移动，比起传引用后使用拷贝，只多出一次移动操作，如果移动开销很小，这种做法简化了代码，是一个很好的选择

```cpp
void f(std::shared_ptr<A> p) {  // 拷贝一次
  auto q = std::move(p);        // 移动一次
  // ...
}
```

* 这种情况常见于构造函数中

```cpp
class X {
 public:
  explicit X(std::shared_ptr<A> p) : p_(std::move(p)) {}

 private:
  std::shared_ptr<A> p_;
};
```
