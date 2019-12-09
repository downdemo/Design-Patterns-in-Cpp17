#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <utility>

namespace jc {

class Context {
 public:
  void SetMessage(std::string_view s) { s_ = s; }

  std::string_view Message() const { return s_; }

 private:
  std::string s_;
};

class Expression {
 public:
  virtual bool Interpret(const Context&) = 0;
  virtual ~Expression() = default;
};

class TerminalExpression : public Expression {
 public:
  TerminalExpression(std::string_view s) : s_(s) {}

  bool Interpret(const Context& context) override {
    return context.Message().find(s_) == std::string_view::npos;
  }

 private:
  std::string s_;
};

class AndExpression : public Expression {
 public:
  AndExpression(std::shared_ptr<Expression> p, std::shared_ptr<Expression> q)
      : p_(std::move(p)), q_(std::move(q)) {}

  bool Interpret(const Context& context) override {
    return p_->Interpret(context) && q_->Interpret(context);
  }

 private:
  std::shared_ptr<Expression> p_;
  std::shared_ptr<Expression> q_;
};

}  // namespace jc

int main() {
  std::shared_ptr<jc::Expression> a =
      std::make_shared<jc::TerminalExpression>("sb");
  std::shared_ptr<jc::Expression> b =
      std::make_shared<jc::TerminalExpression>("fk");
  std::shared_ptr<jc::Expression> expression =
      std::make_shared<jc::AndExpression>(a, b);

  jc::Context context;
  context.SetMessage("hello world");

  if (expression->Interpret(context)) {
    std::cout << context.Message();
  } else {
    std::cout << "sensitive words";
  }
}
