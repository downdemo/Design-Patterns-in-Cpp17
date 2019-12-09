#include <cassert>
#include <memory>

namespace jc {

class Prototype {
 public:
  virtual std::unique_ptr<Prototype> Clone() = 0;
  virtual ~Prototype() = default;
};

class A : public Prototype {
 public:
  std::unique_ptr<Prototype> Clone() override {
    return std::make_unique<A>(*this);
  }
};

}  // namespace jc

int main() {
  std::unique_ptr<jc::Prototype> p = std::make_unique<jc::A>();
  std::unique_ptr<jc::Prototype> q = p->Clone();
  assert(p != q);
}
