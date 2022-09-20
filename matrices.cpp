
#include <iostream>
#include <vector>
#include <armadillo>



int main()
{
  int n = 4
  int m = 4
  arma::vec v = arma::vec(n);
  arma::vec g = arma::vec(m);

  //creating the matrix A
  arma::mat A = arma::mat(n, m);

  //adding elements to the matrix A
  A(1,1)= 2; //Assign element (i,j) of the matrix A to A_ij.

  std::cout << "#" << std::setw(width-1) << "A"
            << std::endl;

  for (double i; i <x.size(); i++){
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << A
              << std::endl;
  }



return 0;
}
