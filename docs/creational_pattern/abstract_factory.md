* 抽象工厂能生成一系列相关的局部产品

```cpp
class Door {
 public:
  virtual ~Door() = default;
};

class Window {
 public:
  virtual ~Window() = default;
};

class House {
 public:
  virtual void SetDoor(const Door&) {}
  virtual void SetWindow(const Window&) {}
  virtual ~House() = default;
};

class HouseFactory {
 public:
  virtual std::unique_ptr<Door> MakeDoor() { return std::make_unique<Door>(); }

  virtual std::unique_ptr<Window> MakeWindow() {
    return std::make_unique<Window>();
  }

  virtual std::unique_ptr<House> MakeHouse() {
    return std::make_unique<House>();
  }

  virtual ~HouseFactory() = default;
};
```

* 用这个抽象工厂生成的局部产品即可组合成一个完整的产品

```cpp
class Life {
 public:
  std::unique_ptr<House> CreateHouse(HouseFactory& factory) {
    std::unique_ptr<Door> door = factory.MakeDoor();
    std::unique_ptr<Window> window = factory.MakeWindow();
    std::unique_ptr<House> house = factory.MakeHouse();
    house->SetDoor(*door);
    house->SetWindow(*window);
    return house;
  }
};

int main() {
  Life life;
  HouseFactory factory;
  std::unique_ptr<House> house = life.CreateHouse(factory);
}
```

* 继承这个抽象工厂，即可对局部产品进行修改

```cpp
class WoodDoor : public Door {};
class WoodWindow : public Window {};
class WoodHouse : public House {};

class WoodHouseFactory : public HouseFactory {
 public:
  std::unique_ptr<Door> MakeDoor() override {
    return std::make_unique<WoodDoor>();
  }

  std::unique_ptr<Window> MakeWindow() override {
    return std::make_unique<WoodWindow>();
  }

  std::unique_ptr<House> MakeHouse() override {
    return std::make_unique<WoodHouse>();
  }
};

int main() {
  Life life;
  WoodHouseFactory factory;

  std::unique_ptr<House> house = life.CreateHouse(factory);
}
```
