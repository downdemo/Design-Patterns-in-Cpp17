#include <iostream>
#include <memory>

namespace jc {

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

}  // namespace jc

int main() {
  jc::Context a{std::make_unique<jc::StrategyA>()};
  jc::Context b{std::make_unique<jc::StrategyB>()};

  a.Print();  // StrategyA
  b.Print();  // StrategyB
}
