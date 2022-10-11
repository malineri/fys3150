#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>

//creating function that changes the biggest offdiag element
double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  double m = INT_MIN;
  for (int k = 0; k < A.n_rows; k++){
    for (int l = 0; l < k; l++){
      if (abs(A(k, l)) > m){
        m = A(k, l);
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

  arma::mat B = abs(A);


  double max_value = max_offdiag_symmetric(B, N, N);


  std::cout<< max_value;




  return 0;


}
