* 外观模式为一组子系统提供了一个高层接口，用户无需了解各个子系统的内部联系，只需要使用此高层接口

```cpp
class Scanner {
 public:
  void Scan() { std::cout << "generate token\n"; }
};

class Parser {
 public:
  void Parse() { std::cout << "build syntax tree\n"; }
};

class CodeGenerator {
 public:
  void GenerateCode() { std::cout << "generate machine code\n"; }
};

// 提供高层接口的 Facade 类
class Compiler {
 public:
  void Run() {
    Scanner s;
    s.Scan();

    Parser p;
    p.Parse();

    CodeGenerator c;
    c.GenerateCode();
  }
};

int main() {
  Compiler compiler;
  compiler.Run();
}
```
