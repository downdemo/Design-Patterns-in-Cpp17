* 在基类定义一个包含多个操作的方法，每个操作在派生类中实现，基类的这个方法就是模板方法。在 C++ 中这种手法称为 NVI（non-virtual interface），模板方法是一个非虚函数，其中的操作为虚函数，并且作为私有成员不暴露给外部

```cpp
class Abstract {
 public:
  void TemplateMethod() {
    FunctionA();
    FunctionB();
    FunctionC();
  }

  virtual ~Abstract() = default;

 private:
  virtual void FunctionA() = 0;
  virtual void FunctionB() = 0;
  virtual void FunctionC() = 0;
};

class A : public Abstract {
 private:
  void FunctionA() override { std::cout << 1; }
  void FunctionB() override { std::cout << 2; }
  void FunctionC() override { std::cout << 3; }
};

class B : public Abstract {
 private:
  void FunctionA() override { std::cout << 4; }
  void FunctionB() override { std::cout << 5; }
  void FunctionC() override { std::cout << 6; }
};

int main() {
  std::unique_ptr<Abstract> a = std::make_unique<A>();
  std::unique_ptr<Abstract> b = std::make_unique<B>();

  a->TemplateMethod();  // 123
  b->TemplateMethod();  // 456
}
```
