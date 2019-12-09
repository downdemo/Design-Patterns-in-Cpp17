#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

namespace jc {

class Shape {
 public:
  virtual void Display() = 0;
  virtual void Append(const std::shared_ptr<Shape>&) {}
  virtual void Remove(const std::shared_ptr<Shape>&) {}

  virtual std::shared_ptr<Shape> Child(std::size_t) { return nullptr; }

  virtual ~Shape() = default;
};

class Line : public Shape {
 public:
  void Display() override { std::cout << 1; }
};

class Rect : public Shape {
 public:
  void Display() override { std::cout << 2; }
};

class Picture : public Shape {
 public:
  void Display() override {
    for (auto&& x : shapes_) {
      x->Display();
    }
  }

  void Append(const std::shared_ptr<Shape>& s) override {
    shapes_.emplace_back(s);
  }

  void Remove(const std::shared_ptr<Shape>& s) override {
    if (const auto it = std::find(std::begin(shapes_), std::end(shapes_), s);
        it != std::end(shapes_)) {
      shapes_.erase(it);
    }
  }

  std::shared_ptr<Shape> Child(std::size_t n) override { return shapes_.at(n); }

 private:
  std::vector<std::shared_ptr<Shape>> shapes_;
};

}  // namespace jc

int main() {
  std::unique_ptr<jc::Shape> picture = std::make_unique<jc::Picture>();
  const auto line = std::make_shared<jc::Line>();
  const auto rect = std::make_shared<jc::Rect>();

  picture->Append(line);
  picture->Append(rect);
  picture->Display();  // 12

  picture->Remove(line);
  picture->Display();  // 2
}
