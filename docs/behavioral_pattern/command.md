* 命令模式将请求封装成对象，解耦了调用者与处理者

```cpp
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <utility>

class Receiver {
 public:
  void Print() { std::cout << 1; }
};

// 处理者
class Command {
 public:
  virtual void Execute() = 0;
  virtual ~Command() = default;
};

template <typename T>
class CommandA : public Command {
 public:
  using Action = std::function<void(T&)>;

  CommandA(const std::shared_ptr<T>& p, Action a)
      : receiver_(p), action_(std::move(a)) {}

  void Execute() override {
    std::cout << "A";
    if (const auto p = receiver_.lock()) {
      action_(*p);
    }
  }

 private:
  std::weak_ptr<T> receiver_;
  Action action_;
};

template <typename T>
class CommandB : public Command {
 public:
  using Action = std::function<void(T&)>;

  CommandB(const std::shared_ptr<T>& p, Action a)
      : receiver_(p), action_(std::move(a)) {}

  void Execute() override {
    std::cout << "B";
    if (const auto p = receiver_.lock()) {
      action_(*p);
    }
  }

 private:
  std::weak_ptr<T> receiver_;
  Action action_;
};

// 调用者
class Invoker : public Command {
 public:
  void Append(const std::shared_ptr<Command>& c) { commands_.emplace_back(c); }

  void Remove(const std::shared_ptr<Command>& c) {
    commands_.remove_if(
        [&](std::weak_ptr<Command>& x) { return x.lock() == c; });
  }

  void Execute() override {
    for (auto&& x : commands_) {
      if (const auto p = x.lock()) {
        p->Execute();
      }
    }
  }

 private:
  std::list<std::weak_ptr<Command>> commands_;
};

int main() {
  auto receiver = std::make_shared<Receiver>();
  const std::shared_ptr<Command> commandA =
      std::make_shared<CommandA<Receiver>>(receiver, &Receiver::Print);
  const std::shared_ptr<Command> commandB =
      std::make_shared<CommandB<Receiver>>(receiver, &Receiver::Print);

  Invoker invoker;
  invoker.Append(commandA);
  invoker.Append(commandB);
  invoker.Execute();  // A1B1
}
```
