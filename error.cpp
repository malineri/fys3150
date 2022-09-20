#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

std::vector<double> relative(std::vector<double> u, std::vector<double> v){
  std::vector<double> w;
  for (double i; i <u.size(); i++){
    w.push_back(abs((u[i] - v[i])/(u[i])));
  }
  return w;
}



int main()
{
  // Parameters for output formatting
  int width = 18;
  int prec  = 10;

  std::vector<double> u;
  u.push_back(0.0);
  u.push_back(0.66);
  u.push_back(0.58);
  u.push_back(0.40);
  u.push_back(0.20);
  u.push_back(5.89*pow(10, -18));

  std::vector<double> v;
  v.push_back(0.0);
  v.push_back(0.68);
  v.push_back(0.82);
  v.push_back(0.89);
  v.push_back(0.94);
  v.push_back(0.0);

  std::vector<double> w = relative(u, v);


  // Output a header
  std::cout << "#" << std::setw(width-1) << "u"
            << "#" << std::setw(width-1) << "v"
            << std::setw(width) << "w"
            << std::endl;

    // Output to screen
    for (double i; i <u.size(); i++){
      std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << u[i]
      << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
      << std::setw(width) << std::setprecision(prec) << std::scientific << w[i]
      << std::endl;
    }

  return 0;

}
