* Flyweight 意指轻量，享元意指共享对象。存在大量细粒度对象的系统中，使用享元模式可以减少对相同对象的创建。比如文本编辑器的字符显示，如果为每个字符创建一个对象则会导致大量开销，而实际上大部分字符会重复出现，只需要创建一次即可

```cpp
class Flyweight {
 public:
  virtual void Print() = 0;
  virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight {
 public:
  explicit ConcreteFlyweight(char key) : key_(key) {}

  void Print() override { std::cout << key_; }

 private:
  char key_;
};

class FlyweightFactory {
 public:
  std::unique_ptr<Flyweight>& FlyweightPtr(char c) {
    if (const auto it = m_.find(c); it != std::end(m_)) {
      std::cout << "existing key: ";
      return it->second;
    }
    std::unique_ptr<Flyweight> p = std::make_unique<ConcreteFlyweight>(c);
    m_.emplace(c, std::move(p));
    return m_.at(c);
  }

 private:
  std::unordered_map<char, std::unique_ptr<Flyweight>> m_;
};

int main() {
  FlyweightFactory factory;
  factory.FlyweightPtr('a')->Print();  // a
  factory.FlyweightPtr('a')->Print();  // existing key: a
  factory.FlyweightPtr('b')->Print();  // b
  factory.FlyweightPtr('b')->Print();  // existing key: a
}
```
