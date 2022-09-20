#include <iostream>
#include <vector>
#include <string>

int main ()
{

// Create a vector<double> with startingpoint 0, endpoint 1, with 11 steps
 //std::vector<int> v3(5);
  std::vector<double> v1;
  v1.push_back(0.0);
  v1.push_back(0.2);
  v1.push_back(0.4);
  v1.push_back(0.6);
  v1.push_back(0.8);
  v1.push_back(1.0);



  std::cout << "v1: ";
  for (size_t i = 0; i < v1.size(); i++)
  {
    std::cout << " " << v1[i];
  }
  std::cout << std::endl;


  return 0;
}
