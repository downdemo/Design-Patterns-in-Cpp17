#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

namespace jc {

template <typename T>
class List;

template <typename T>
class Iterator {
 public:
  Iterator(List<T>& list) : list_(list) {}

  void operator++() { ++index_; }

  bool IsDone() { return index_ >= list_.Size(); }

  T& operator*() { return list_[index_]; }

 private:
  List<T>& list_;
  std::size_t index_ = 0;
};

template <typename T>
class List {
 public:
  Iterator<T> Begin() { return Iterator<T>{*this}; }

  void Append(T&& x) { data_.emplace_back(std::forward<T>(x)); }

  std::size_t Size() { return std::size(data_); }

  T& operator[](std::size_t n) { return data_.at(n); }

 private:
  std::vector<T> data_;
};

}  // namespace jc

int main() {
  jc::List<std::int32_t> list;
  list.Append(2);
  list.Append(3);
  list.Append(1);

  for (auto it = list.Begin(); !it.IsDone(); ++it) {
    std::cout << *it;  // 231
  }
}
