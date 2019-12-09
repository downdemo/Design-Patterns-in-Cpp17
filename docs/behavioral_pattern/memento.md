* 用一个备忘录保存源对象状态

```cpp
class Memento {
 public:
  Memento(std::int32_t n = 0) : value_(n) {}

  std::int32_t Value() const { return value_; }

 private:
  std::int32_t value_;
};
```

* 源对象状态的保存和恢复都通过备忘录来执行

```cpp
class Originator {
 public:
  Originator(std::int32_t n = 0) : value_(n) {}

  Memento ValueMemento() const { return Memento{value_}; }

  void Load(const Memento& m) { value_ = m.Value(); }

  void PrintValue() const { std::cout << value_ << '\n'; }

  void SetValue(std::int32_t n) { value_ = n; }

 private:
  std::int32_t value_;
};
```

* 负责人保存一系列备忘录，供源对象使用

```cpp
class Caretaker {
 public:
  Memento& State(const std::string& s) { return mementos_.at(s); }

  void SetState(const std::string& s, const Memento& m) {
    mementos_.try_emplace(s, m);
  }

 private:
  std::unordered_map<std::string, Memento> mementos_;
};

int main() {
  Caretaker caretaker;
  Originator originator(1);
  caretaker.SetState("one", originator.ValueMemento());
  originator.SetValue(2);
  caretaker.SetState("two", originator.ValueMemento());
  originator.SetValue(3);
  caretaker.SetState("three", originator.ValueMemento());

  originator.Load(caretaker.State("two"));
  originator.PrintValue();  // 2
  originator.Load(caretaker.State("one"));
  originator.PrintValue();  // 1
  originator.Load(caretaker.State("three"));
  originator.PrintValue();  // 3
}
```
