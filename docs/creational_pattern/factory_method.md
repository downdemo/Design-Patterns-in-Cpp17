* 在类中设置一系列工厂函数

```cpp
class Life {
 public:
  virtual std::unique_ptr<Door> MakeDoor() { return std::make_unique<Door>(); }

  virtual std::unique_ptr<Window> MakeWindow() {
    return std::make_unique<Window>();
  }

  virtual std::unique_ptr<House> MakeHouse() {
    return std::make_unique<House>();
  }

  std::unique_ptr<House> CreateHouse() {
    std::unique_ptr<Door> door = MakeDoor();
    std::unique_ptr<Window> window = MakeWindow();
    std::unique_ptr<House> house = MakeHouse();
    house->SetDoor(*door);
    house->SetWindow(*window);
    return house;
  }

  virtual ~Life() = default;
};
```

* 继承这个类重写不同的工厂函数

```cpp
class WoodHouse : public House {};
class WoodDoor : public Door {};
class WoodWindow : public Window {};

class MyLife : public Life {
 public:
  std::unique_ptr<House> MakeHouse() override {
    return std::make_unique<WoodHouse>();
  }

  std::unique_ptr<Door> MakeDoor() override {
    return std::make_unique<WoodDoor>();
  }

  std::unique_ptr<Window> MakeWindow() override {
    return std::make_unique<WoodWindow>();
  }
};

int main() {
  MyLife life;
  std::unique_ptr<House> house = life.CreateHouse();
}
```
