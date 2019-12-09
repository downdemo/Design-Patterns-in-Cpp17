#include <iostream>
#include <memory>

namespace jc {

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

}  // namespace jc

int main() {
  std::unique_ptr<jc::Abstract> a = std::make_unique<jc::A>();
  std::unique_ptr<jc::Abstract> b = std::make_unique<jc::B>();

  a->TemplateMethod();  // 123
  b->TemplateMethod();  // 456
}
