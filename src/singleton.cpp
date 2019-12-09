#include <cassert>

namespace jc {

template <typename T>
class Singleton {
 public:
  static T& Instance();
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 private:
  Singleton() = default;
  ~Singleton() = default;
};

template <typename T>
T& Singleton<T>::Instance() {
  static T instance;
  return instance;
}

}  // namespace jc

class A {};

int main() {
  auto& a = jc::Singleton<A>::Instance();
  auto& b = jc::Singleton<A>::Instance();
  assert(&a == &b);
}
