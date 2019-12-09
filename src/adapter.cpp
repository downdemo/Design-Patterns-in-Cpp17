#include <iostream>
#include <memory>

namespace jc {

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

class Adapter : public Target, public Adaptee {
 public:
  void Print() override { Adaptee::PrintImpl(); }
};

}  // namespace jc

int main() {
  std::unique_ptr<jc::Target> target = std::make_unique<jc::Adapter>();
  target->Print();  // 1
}
