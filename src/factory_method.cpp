#include <memory>

namespace jc {

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

}  // namespace jc

int main() {
  jc::MyLife life;
  std::unique_ptr<jc::House> house = life.CreateHouse();
}
