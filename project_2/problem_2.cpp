#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>

//Creating a program that takes an NxN Matrix A filled with random numbers,
//and generate a symmentric matrix B, where the eigenval and eigenvec are the respective
//eigenvalues and eigenvectors of the matrix B.

int main()
{
  int N = 6;

  arma::mat A(N, N).fill(0.); //create NxN matrix with zeros
  arma::mat B = A.t()*A; //create symmetric matrix

  arma::diagmat(arma::sum(A, 1)).print("B");


  arma::vec eigval;
  arma::mat eigvec;

  arma::eig_sym(eigval, eigvec, B);

  std::cout<<B
           <<std::endl;






  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  //output Eigenvectors and Eigenvalues
  std::cout << "#" << std::setw(width-1) << "Eigenvectors"
            << std::endl;


  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << eigvec
            << std::endl;



  std::cout << std::setw(width - 1) << "Eigenvalues"
            << std::endl;

  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << eigval
            << std::endl;







  return 0;

}
