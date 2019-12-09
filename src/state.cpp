#include <iostream>
#include <memory>

namespace jc {

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

}  // namespace jc

int main() {
  jc::Connection connection{std::make_unique<jc::StateA>()};
  connection.Open();   // open in stateA
  connection.Close();  // close in stateA

  connection.ChangeState(std::make_unique<jc::StateB>());
  connection.Open();   // open in stateB
  connection.Close();  // close in stateB
}
