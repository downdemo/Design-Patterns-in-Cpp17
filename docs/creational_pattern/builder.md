* 建造者本身只定义接口，由不同实现定义实现类

```cpp
// 提供接口的 Builder
class GameDevice {
 public:
  virtual void BuildMouse() = 0;
  virtual void BuildKeyboard() = 0;
  virtual void BuildHeadphone() = 0;
  virtual DeviceSuite& Device() const = 0;
  virtual ~GameDevice() = default;
};

// 定义一个实现类
class LOLGameDevice : public GameDevice {
 public:
  LOLGameDevice() : device_(std::make_unique<DeviceSuite>()) {}

  void BuildMouse() override { device_->SetMouse("Logitech"); }

  void BuildKeyboard() override { device_->SetKeyboard("Filco"); }

  void BuildHeadphone() override { device_->SetHeadphone("Sennheiser"); }

  DeviceSuite& Device() const override { return *device_; }

 private:
  std::unique_ptr<DeviceSuite> device_;
};

// 还可以继续定义其他实现类，根据需要可以有任意数量种实现
class DNFGameDevice : public GameDevice {
 public:
  DNFGameDevice() : device_(std::make_unique<DeviceSuite>()) {}

  void BuildMouse() override { device_->SetMouse("Razer"); }

  void BuildKeyboard() override { device_->SetKeyboard("Cherry"); }

  void BuildHeadphone() override { device_->SetHeadphone("Beyerdynamic"); }

  DeviceSuite& Device() const override { return *device_; }

 private:
  std::unique_ptr<DeviceSuite> device_;
};
```

* 用实现类构建一个完整产品

```cpp
class Life {
 public:
  DeviceSuite& CreateDevice(GameDevice& builder) {
    builder.BuildMouse();
    builder.BuildKeyboard();
    builder.BuildHeadphone();
    return builder.Device();
  }
};

int main() {
  Life life;
  LOLGameDevice LOLBuilder;
  DNFGameDevice DNFBuilder;

  DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);
  DeviceSuite DNFDevice = life.CreateDevice(DNFBuilder);
}
```
