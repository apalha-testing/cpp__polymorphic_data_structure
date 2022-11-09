
#include <vector>
#include <memory>
#include <iostream>

#include "eos.hpp"

// Initializes two objects and just uses them, to show how they work individually
void eos_simple_test(){
  std::cout << "\n-- Simple test -----------------------------------------------" << "\n";

  // Let us initialize the objects and see if they work as intended
  apalha::eos_A my_A_eos;
  apalha::eos_B my_B_eos;

  my_A_eos.evaluate();
  my_B_eos.evaluate();

  std::cout << "\n--------------------------------------------------------------" << "\n";
}


// Naive implementation of polymorphism with std::vector
std::vector<apalha::eos_base *> eos_polymorphism_naive(){
  std::cout << "\n-- Naive polymorphism test -----------------------------------" << "\n";

  // Let us initialize the objects and see if they work as intended
  apalha::eos_A my_A_eos;
  apalha::eos_B my_B_eos;

  // Declare the vector
  std::vector<apalha::eos_base *> my_eos_vector;

  // Now add the objects to it
  my_eos_vector.push_back(&my_A_eos);
  my_eos_vector.push_back(&my_B_eos);

  // Check if we can still use them
  my_eos_vector[0]->evaluate();  // evaluate my_A_eos
  my_eos_vector[1]->evaluate();  // evaluate my_B_eos

  // All seems ok, but once we return the vector, then we have problems...

  std::cout << "\n--------------------------------------------------------------" << "\n";

  return my_eos_vector;
}


// One step forward implementation of polymorphism with std::vector
std::vector<apalha::eos_base *> eos_polymorphism_one_step_forward(){
  std::cout << "\n-- Naive polymorphism test -----------------------------------" << "\n";

  // Let us initialize the objects and see if they work as intended
  apalha::eos_A *my_A_eos = new apalha::eos_A;
  apalha::eos_B *my_B_eos = new apalha::eos_B;

  // Declare the vector
  std::vector<apalha::eos_base *> my_eos_vector;

  // Now add the objects to it
  my_eos_vector.push_back(my_A_eos);
  my_eos_vector.push_back(my_B_eos);

  // Check if we can still use them
  my_eos_vector[0]->evaluate();  // evaluate my_A_eos
  my_eos_vector[1]->evaluate();  // evaluate my_B_eos

  // All seems ok, but once we return the vector, then we have problems...

  std::cout << "\n--------------------------------------------------------------" << "\n";

  return my_eos_vector;
}


// Recommended way of implementing polymorphism with std::vector
std::vector<std::unique_ptr<apalha::eos_base>> eos_polymorphism_recommended(){
  std::cout << "\n-- Recommended polymorphism test -----------------------------" << "\n";

  // Let us initialize the objects and see if they work as intended

  // If using c++14 and newer
  // std::unique_ptr<apalha::eos_base> my_A_eos = std::make_unique<apalha::eos_A>;
  // std::unique_ptr<apalha::eos_base> my_B_eos = std::make_unique<apalha::eos_B>;

  // Declare the vector
  std::vector<std::unique_ptr<apalha::eos_base>> my_eos_vector;

  // Now add the objects to it
  my_eos_vector.emplace_back(new apalha::eos_A);
  my_eos_vector.emplace_back(new apalha::eos_B);

  // Check if we can still use them
  my_eos_vector[0]->evaluate();  // evaluate my_A_eos
  my_eos_vector[1]->evaluate();  // evaluate my_B_eos

  // All seems ok, but once we return the vector, then we have problems...

  std::cout << "\n--------------------------------------------------------------" << "\n";

  return my_eos_vector;
}


int main(){

  // Simple test
  eos_simple_test();


  // Naive test (with issues)
  std::vector<apalha::eos_base *> my_returned_naive_eos_vector;
  my_returned_naive_eos_vector = eos_polymorphism_naive();

  // This does not work, you need to comment this part for the code to pass this,
  // since it will give a segmentation fault.
  // Why? The reason is that your my_A_eos and my_B_eos you created inside the
  // function eos_polymorphism_naive will no longer be in scope once you leave the
  // function, therefore they are destroyed. To recap, they are constructed inside
  // the function, then you get the pointers to them and add these pointers to the
  // vector. This works fine as long as you use the vector inside the function.
  // Once you leave the function the objects my_A_eos and my_B_eos are destroyed
  // and the vector will contain pointers to a location in memory that no longer
  // contains meaningful objects. Because of this you get the segmentation fault.
  // std::cout << "\n-- Naive polymorphism test (now in main) ---------------------" << "\n";
  // for(apalha::eos_base *eos_object : my_returned_naive_eos_vector)
  //   eos_object->evaluate();
  // std::cout << "\n--------------------------------------------------------------" << "\n";

  // Slightly advanced test (still with issues)
  std::vector<apalha::eos_base *> my_returned_one_step_forward_eos_vector;
  my_returned_one_step_forward_eos_vector = eos_polymorphism_one_step_forward();

  std::cout << "\n-- Naive polymorphism test (now in main) ---------------------" << "\n";
  for(apalha::eos_base *eos_object : my_returned_one_step_forward_eos_vector)
    eos_object->evaluate();
  std::cout << "\n--------------------------------------------------------------" << "\n";

  // This works, but you need to explicitly delete the objects created and stored
  // in the vector
  std::cout << "\n-- Naive polymorphism test (delete the objects) --------------" << "\n";
  for(apalha::eos_base *eos_object : my_returned_one_step_forward_eos_vector){
    delete eos_object;
    std::cout << "\nDeleted object!" << "\n";
  }
  std::cout << "\n--------------------------------------------------------------" << "\n";

  // Recommended advanced test
  std::vector<std::unique_ptr<apalha::eos_base>> my_returned_recommended_eos_vector;
  my_returned_recommended_eos_vector = eos_polymorphism_recommended();

  std::cout << "\n-- Recommended polymorphism test (now in main) ---------------" << "\n";
  // We now need to access the elements of the vector in this way, because
  // we cannot make copies
  for(int eos_idx = 0; eos_idx < my_returned_recommended_eos_vector.size(); eos_idx++)
    my_returned_recommended_eos_vector[eos_idx]->evaluate();
  std::cout << "\n--------------------------------------------------------------" << "\n";
}
