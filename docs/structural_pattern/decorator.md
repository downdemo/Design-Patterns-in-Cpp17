* 装饰器可以不改变定义地扩展功能

```cpp
// 定义接口的 Component
class Shape {
 public:
  virtual void Display() = 0;
  virtual ~Shape() = default;
};

// 定义实现的 ConcreteComponent
class Line : public Shape {
 public:
  void Display() override { std::cout << "line\n"; }
};

// 持有一个 Component 指针的 Decorator，它提供与 Component 一致的接口
class Decorator : public Shape {
 public:
  Decorator(std::unique_ptr<Shape> p) : shape_(std::move(p)) {}

  void Display() override { shape_->Display(); }

 private:
  std::unique_ptr<Shape> shape_;
};

// 扩展接口功能的 ConcreteDecorator
class ColorDecorator : public Decorator {
 public:
  using Decorator::Decorator;

  void Display() override {
    std::cout << "red ";
    Decorator::Display();
  }
};

int main() {
  std::unique_ptr<Shape> colorDecorator =
      std::make_unique<ColorDecorator>(std::make_unique<Line>());
  colorDecorator->Display();  // red line
}
```

* 用模板实现装饰器

```cpp
class Shape {
 public:
  virtual void Display() = 0;
  virtual ~Shape() = default;
};

template <typename... T>
class Line : public Shape, public T... {
 public:
  void Display() override {
    std::apply([](auto&&... x) { (x.Display(), ...); },
               std::forward_as_tuple(T()...));
    std::cout << "line\n";
  }
};

class ColorDecorator {
 public:
  void Display() { std::cout << "red "; }
};

class WeightDecorator {
 public:
  void Display() { std::cout << "bold "; }
};

int main() {
  Line line1;
  Line<ColorDecorator> line2;
  Line<WeightDecorator> line3;
  Line<ColorDecorator, WeightDecorator> line4;

  line1.Display();  // line
  line2.Display();  // red line
  line3.Display();  // bold line
  line4.Display();  // red bold line
}
```

* 结合 CRTP

```cpp
class Shape {
 public:
  virtual void Display() = 0;
  virtual ~Shape() = default;
};

template <template <typename> class... T>
class Line : public Shape, public T<Line<>>... {
 public:
  void Display() override {
    std::apply([](auto&&... x) { (x.Display(), ...); },
               std::forward_as_tuple(T<Line<>>()...));
    std::cout << "line\n";
  }
};

template <template <typename> class... T>
class Text : public Shape, public T<Text<>>... {
 public:
  void Display() override {
    std::apply([](auto&&... x) { (x.Display(), ...); },
               std::forward_as_tuple(T<Text<>>()...));
    std::cout << "text\n";
  }
};

template <typename T>
class ColorDecorator {
 public:
  void Display() {
    if constexpr (std::is_constructible_v<Line<>*, T*>) {
      std::cout << "red ";
    } else {
      std::cout << "black ";
    }
  }
};

template <typename T>
class WeightDecorator {
 public:
  void Display() {
    if constexpr (std::is_constructible_v<Line<>*, T*>) {
      std::cout << "bold ";
    } else {
      std::cout << "normal ";
    }
  }
};

int main() {
  Line line1;
  Line<ColorDecorator> line2;
  Line<WeightDecorator> line3;
  Line<ColorDecorator, WeightDecorator> line4;

  line1.Display();  // line
  line2.Display();  // red line
  line3.Display();  // bold line
  line4.Display();  // red bold line

  Text text1;
  Text<ColorDecorator> text2;
  Text<WeightDecorator> text3;
  Text<ColorDecorator, WeightDecorator> text4;

  text1.Display();  // text
  text2.Display();  // black text
  text3.Display();  // normal text
  text4.Display();  // black normal text
}
```
