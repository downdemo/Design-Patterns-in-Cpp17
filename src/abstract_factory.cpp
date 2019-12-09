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

}  // namespace jc

int main() {
  jc::Life life;
  jc::WoodHouseFactory factory;

  std::unique_ptr<jc::House> house = life.CreateHouse(factory);
}
