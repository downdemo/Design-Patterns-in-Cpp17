#include <iostream>
#include <memory>

namespace jc {

class Graphic {
 public:
  virtual void Display() = 0;
  virtual ~Graphic() = default;
};

class Image : public Graphic {
 public:
  void Display() override { std::cout << 1; }
};

class Proxy : public Graphic {
 public:
  void Display() override { ImageProxy().Display(); }

 protected:
  Image &ImageProxy() {
    if (!p_) {
      p_ = std::make_unique<Image>();
    }
    return *p_;
  }

 private:
  std::unique_ptr<Image> p_;
};

}  // namespace jc

int main() {
  std::unique_ptr<jc::Graphic> proxy = std::make_unique<jc::Proxy>();
  proxy->Display();  // 1
}
