* 可访问元素为有限个，在访问者中定义访问所有元素的接口

```cpp
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
```

* 在可访问元素中提供接待接口，参数为访问者，接待方法调用访问者的访问方法

```cpp
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
```

* 最后提供一个保存所有可访问元素的对象

```cpp
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

int main() {
  std::shared_ptr<Element> a = std::make_shared<ElementA>();
  std::shared_ptr<Element> b = std::make_shared<ElementB>();

  ObjectStructure o;
  o.Append(a);
  o.Append(b);

  std::shared_ptr<Visitor> visitor = std::make_shared<ConcreteVisitor>();
  o.Accept(visitor);  // visit A\nvisit B\n
}
```
