#include <cstdint>
#include <iostream>
#include <unordered_map>

namespace jc {

class Memento {
 public:
  Memento(std::int32_t n = 0) : value_(n) {}

  std::int32_t Value() const { return value_; }

 private:
  std::int32_t value_;
};

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

class Caretaker {
 public:
  Memento& State(const std::string& s) { return mementos_.at(s); }

  void SetState(const std::string& s, const Memento& m) {
    mementos_.try_emplace(s, m);
  }

 private:
  std::unordered_map<std::string, Memento> mementos_;
};

}  // namespace jc

int main() {
  jc::Caretaker caretaker;
  jc::Originator originator(1);
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
