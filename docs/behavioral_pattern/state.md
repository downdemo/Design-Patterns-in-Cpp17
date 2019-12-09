* 目标对象执行相同操作时，如果状态不同，则执行结果也不同。让目标对象持有一个状态对象的指针，目标的操作都转发给状态对象，改变目标的状态即可相应地改变目标操作，看起来就像整个类都被修改了

```cpp
class Connection;

class State {
 public:
  virtual void Open(const Connection&) const = 0;
  virtual void Close(const Connection&) const = 0;
  virtual ~State() = default;
};

class Connection {
 public:
  Connection(std::unique_ptr<State> p) : p_(std::move(p)) {}

  void ChangeState(std::unique_ptr<State> p) { p_ = std::move(p); }

  void Open() const { p_->Open(*this); }

  void Close() const { p_->Close(*this); }

 private:
  std::unique_ptr<State> p_;
};

class StateA : public State {
 public:
  void Open(const Connection&) const override {
    std::cout << "open in stateA\n";
  }

  void Close(const Connection&) const override {
    std::cout << "close in stateA\n";
  }
};

class StateB : public State {
 public:
  void Open(const Connection&) const override {
    std::cout << "open in stateB\n";
  }

  void Close(const Connection&) const override {
    std::cout << "close in stateB\n";
  }
};

int main() {
  Connection connection{std::make_unique<StateA>()};
  connection.Open();   // open in stateA
  connection.Close();  // close in stateA

  connection.ChangeState(std::make_unique<StateB>());
  connection.Open();   // open in stateB
  connection.Close();  // close in stateB
}
```
