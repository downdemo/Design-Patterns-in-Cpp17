* 单例模式保证一个类只有一个实例

```cpp
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

class A {};

int main() {
  auto& a = Singleton<A>::Instance();
  auto& b = Singleton<A>::Instance();
  assert(&a == &b);
}
```
