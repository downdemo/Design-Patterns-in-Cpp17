* 适配器提供了源接口到目标接口的转换

```cpp
class Target {  // 提供给用户的类
 public:
  virtual void Print() = 0;
  virtual ~Target() = default;
};

class Adaptee {  // 提供实际功能的类
 public:
  virtual void PrintImpl() { std::cout << 1; }
  virtual ~Adaptee() = default;
};

class Adapter : public Target, public Adaptee {  // 适配器
 public:
  void Print() override { Adaptee::PrintImpl(); }
};

int main() {
  std::unique_ptr<Target> target = std::make_unique<Adapter>();
  target->Print();  // 1
}
```

* 上述采用多继承的形式称为类适配器，另一种采用组合的形式称为对象适配器

```cpp
class Target {
 public:
  virtual void Print() = 0;
  virtual ~Target() = default;
};

class Adaptee {
 public:
  virtual void PrintImpl() { std::cout << 1; }
  virtual ~Adaptee() = default;
};

class Adapter : public Target {
 public:
  Adapter() : p_(std::make_unique<Adaptee>()) {}
  void Print() override { p_->PrintImpl(); }

 private:
  std::unique_ptr<Adaptee> p_;
};

int main() {
  std::unique_ptr<Target> target = std::make_unique<Adapter>();
  target->Print();  // 1
}
```
