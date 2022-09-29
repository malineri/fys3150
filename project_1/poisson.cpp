// Using program from error_analysis to find the second derivative of
// u(x) = 1 - (1 - exp(-10))x - exp(-10x) ~ exp(2x) at a single point x, using different stepsizes h
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//
// Useful functions
//

// Example function: u(x) = exp(2x)
std::vector<double> calc_u(std::vector<double> x){
  std::vector<double> u;
  for (double i; i <x.size(); i++){
     u.push_back(1 - (1 - exp(-10))*x[i] - exp(-10*x[i]));
  }
  return u;
}


int main()
{
    // Parameters for output formatting


    std::vector<double> x;
    int n = 10;
    int h = 1/(n-1);

    for (int h; h <= n; h++)
      x.push_back(0.1*h);

    for (double i; i <x.size(); i++)
        std::cout << i << " ";
    std::cout << std::endl;

    std::vector<double> u = calc_u(x);
    int width = 15;
    int prec = 3;

    // Output a header
    std::cout << "#" << std::setw(width-1) << "x"
              << std::setw(width) << "u"
              << std::endl;

      // Output to screen
      for (double i; i <x.size(); i++){
        std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
        << std::setw(width) << std::setprecision(prec) << std::scientific << u[i]
        << std::endl;
      }


    return 0;
}
