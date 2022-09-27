#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>



// Creating function:
double max_offdiag_symmetric(const arma::mat& A, int& k, int &l);




int main()
{
  int N = 6
  arma::mat A = arma::mat(N, N, arma::fill::eye);

  arma::uvec A_sort_indices = arma::sort_index(A);
