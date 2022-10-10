#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>

//creating function that changes the biggest offdiag element
double max_offdiag_symmetric(const arma::mat& A){
  double m = 0;
  for (int i = 0; i < A.n_rows; i++){
    for (int j = 0; j < i; j++){
      if (A(i, j) > 0){
        m = A(i, j);
      }
    }
  }
  return m;
}



int main (){
  int N = 4;
  arma::mat A = arma::mat(N, N, arma::fill::eye);
  A(0, 3) = 0.5;
  A(1, 2) = -0.7;
  A(2, 1) = -0.7;
  A(3, 0) = 0.5;

  double max_value = max_offdiag_symmetric(A);

  std::cout<< max_value;


  return 0;


}
