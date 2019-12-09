#include <iostream>
#include <list>
#include <memory>

namespace jc {

class Element;

class Visitor {
 public:
  virtual void VisitA(const Element&) = 0;
  virtual void VisitB(const Element&) = 0;
  virtual ~Visitor() = default;
};

class ConcreteVisitor : public Visitor {
 public:
  void VisitA(const Element&) override { std::cout << "visit A\n"; }

  void VisitB(const Element&) override { std::cout << "visit B\n"; }
};

class Element {
 public:
  virtual void Accept(const std::shared_ptr<Visitor>& vistor) = 0;
  virtual ~Element() = default;
};

class ElementA : public Element {
 public:
  void Accept(const std::shared_ptr<Visitor>& vistor) override {
    vistor->VisitA(*this);
  }
};

class ElementB : public Element {
 public:
  void Accept(const std::shared_ptr<Visitor>& vistor) override {
    vistor->VisitB(*this);
  }
};

class ObjectStructure {
 public:
  void Append(const std::shared_ptr<Element>& element) {
    elements_.emplace_back(element);
  }

  void Remove(const std::shared_ptr<Element>& element) {
    elements_.remove(element);
  }

  void Accept(const std::shared_ptr<Visitor>& visitor) {
    for (auto&& x : elements_) {
      x->Accept(visitor);
    }
  }

 private:
  std::list<std::shared_ptr<Element>> elements_;
};

}  // namespace jc

int main() {
  std::shared_ptr<jc::Element> a = std::make_shared<jc::ElementA>();
  std::shared_ptr<jc::Element> b = std::make_shared<jc::ElementB>();

  jc::ObjectStructure o;
  o.Append(a);
  o.Append(b);

  std::shared_ptr<jc::Visitor> visitor =
      std::make_shared<jc::ConcreteVisitor>();
  o.Accept(visitor);  // visit A\nvisit B\n
}
