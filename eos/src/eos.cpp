#include <iostream>

#include "eos.hpp"

namespace apalha{
  // Base class EOS
  eos_base::eos_base(){
    this->type = 0;  // base class
    std::cout << "\nConstructing eos_base oject...\n";
  }

  // Type A EOS
  eos_A::eos_A(){
    this->type = 1;  // type A
    std::cout << "\nConstructing eos_A oject...\n";
  }

  void eos_A::evaluate(){
    std::cout << "\nEvaluating A type EOS: " << this->type << "\n";
  }

  // Type B EOS
  eos_B::eos_B(){
    this->type = 2;  // type B
    std::cout << "\nConstructing eos_B oject...\n";
  }

  void eos_B::evaluate(){
    std::cout << "\nEvaluating B type EOS: " << this->type << "\n";
  }

}
