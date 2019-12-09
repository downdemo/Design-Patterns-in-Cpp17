#include <iostream>

namespace jc {

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

}  // namespace jc

int main() {
  jc::Compiler compiler;
  compiler.Run();
}
