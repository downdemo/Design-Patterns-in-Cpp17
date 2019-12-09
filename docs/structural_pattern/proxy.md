* 打开一个文档时，如果一次性创建所有图形对象，将带来巨大开销，因此应该根据需要创建可见部分。这可以通过提供一个图像代理来实现，代理在需要时才实例化图像对象

```cpp
// 定义接口的 Subject
class Graphic {
 public:
  virtual void Display() = 0;
  virtual ~Graphic() = default;
};

// 定义实现的 RealSubject
class Image : public Graphic {
 public:
  void Display() override { std::cout << 1; }
};

// RealSubject 的代理
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

int main() {
  std::unique_ptr<Graphic> proxy = std::make_unique<Proxy>();
  proxy->Display();  // 1
}
```
