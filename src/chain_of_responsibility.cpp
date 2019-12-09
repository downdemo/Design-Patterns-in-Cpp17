#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>

namespace jc {

class Handler {
 public:
  virtual void Process(std::int32_t i) {
    if (p_) {
      p_->Process(i);
    } else {
      std::cout << i << "can't be processed\n";
    }
  }

  void SetNext(std::shared_ptr<Handler> p) { p_ = std::move(p); }

  virtual ~Handler() = default;

 private:
  std::shared_ptr<Handler> p_;
};

class A : public Handler {
 public:
  void Process(std::int32_t i) override {
    if (i < 10) {
      std::cout << i << " processed by A\n";
    } else {
      Handler::Process(i);
    }
  }
};

class B : public Handler {
 public:
  void Process(std::int32_t i) override {
    if (i < 100) {
      std::cout << i << " processed by B\n";
    } else {
      Handler::Process(i);
    }
  }
};

class C : public Handler {
 public:
  void Process(std::int32_t i) override {
    if (i < 1000) {
      std::cout << i << " processed by C\n";
    } else {
      Handler::Process(i);
    }
  }
};

}  // namespace jc

int main() {
  auto a = std::make_shared<jc::A>();
  auto b = std::make_shared<jc::B>();
  auto c = std::make_shared<jc::C>();

  a->SetNext(b);
  b->SetNext(c);

  a->Process(9);     // 9 processed by A
  a->Process(999);   // 999 processed by C
  a->Process(99);    // 99 processed by B
  a->Process(9999);  // 9999 can't be processed
}
