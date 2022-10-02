#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Vectors a, b, c and g are const. They will not be modified
// by the function. Vector v (the solution vector) is non-const
// and thus will be calculated and updated by the function.
void thomas_algorithm(const std::vector<double>& a,
                      const std::vector<double>& b,
                      const std::vector<double>& c,
                      const std::vector<double>& g,
                      std::vector<double>& v) {
  size_t N = g.size();

  // Create the temporary vectors
  // Note that this is inefficient as it is possible to call
  // this function many times. A better implementation would
  // pass these temporary matrices by non-const reference to
  // save excess allocation and deallocation
  std::vector<double> b_tilde(N, 0.0);
  std::vector<double> g_tilde(N, 0.0);

  // This updates the coefficients in the first row
  // Note that we should be checking for division by zero here
  b_tilde[0] = b[0];
  g_tilde[0] = g[0];

  // Create the b_tilde and g_tilde coefficients in the forward sweep
  for (int i=1; i<N; i++) {
    double m = (a[i]/b_tilde[i - 1]);
    b_tilde[i] = b[i] - (m*c[i - 1]);
    g_tilde[i] = g[i] - (m*g_tilde[i - 1]);
  }

  // This is the reverse sweep, used to update the solution vector v
  for (int i=N-1; i-- > 0; ) {
    v[i] = (g_tilde[i] - (c[i] * v[i+1]))/(b_tilde[i]);
  }
}



//Our special case function f(x) = 100e^{-10x}
std::vector<double> calc_f(std::vector<double> x){
  std::vector<double> f;
  for (double i = 1; i <x.size(); i++){
     f.push_back(100*exp(-10*x[i]));
  }
  return f;
}






int main()
{

  //Declearing variables:
  int N = 10;
  int h = 1/(N - 1);

  //double g0 = (h**2)*f1*v[0]

  std::vector<double> a(N - 1, -1);
  std::vector<double> b(N, 2);
  std::vector<double> c(N - 1, -1);
  std::vector<double> g(N, 0.0);
  std::vector<double> v(N, 0.0);



  //Declare values of x:
  std::vector<double> x;
  for (int h; h <= N; h++)
    x.push_back(0.1*h);


  //create function for our special case:
  std::vector<double> f = calc_f(x);

  // Fill in the current time step vector g
  for (int i=1; i<N; i++) {
    g[i] = (h^2)*f[i];
  }

  // Now we solve the tridiagonal system
  thomas_algorithm(a, b, c, g, v);
  int width = 15;
  int prec = 3;



  // Finally we output the solution vector f
   std::cout << "v = (";
   for (int i=0; i<N; i++) {
     std::cout << v[i]/100;
     if (i < N-1) {
       std:: cout << ", ";
     }
   }
   std::cout << ")" << std::endl;

   // Fill in the current time step initial value
   // vector using three peaks with various amplitudes
   x[0] = 0; v[0] = 0;
   v[N] = 0.;

  // Output a header
  std::cout << " " << std::setw(width-1) << "x"
            << std::setw(width) << "v(x)"
            << std::endl;

  // Output to screen
  for (double i; i <= N ; i++){
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
    << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]/100
    << std::endl;
  }




  return 0;
}
