* 策略模式和状态模式的实现几乎一样：目标对象持有一个策略对象的指针，并把操作转发给策略对象。区别在于，策略由用户提供，针对单个操作，目标不可切换策略，而状态由内部提供，可以切换，并且会改变目标的所有操作

```cpp
class Strategy {
 public:
  virtual void Print() = 0;
  virtual ~Strategy() = default;
};

class StrategyA : public Strategy {
 public:
  void Print() override { std::cout << "StrategyA\n"; }
};

class StrategyB : public Strategy {
 public:
  void Print() override { std::cout << "StrategyB\n"; }
};

class Context {
 public:
  Context(std::unique_ptr<Strategy> p) : p_(std::move(p)) {}

  void Print() const { p_->Print(); }

 private:
  std::unique_ptr<Strategy> p_;
};

int main() {
  Context a{std::make_unique<StrategyA>()};
  Context b{std::make_unique<StrategyB>()};

  a.Print();  // StrategyA
  b.Print();  // StrategyB
}
```
