#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>

//Helping function created to make a tidiagonal matrix.
//Tridiag(a, d, e) of size N*N

arma::mat create_tridiagonal(int n, double a, double d, double e)
{
  // Start from identity matrix
  arma::mat A = arma::mat(n, n, arma::fill::eye);

  // Fill the first row (row index 0), e.g.
  A(0,0) = d;
  A(0,1) = e;

  // Loop that fills rows 2 to n-1 (row indices 1 to n-2)

  // Fill last row (row index n-1)

  return A;
}


//Creating a program that takes an NxN Matrix A filled with random numbers,
//and generate a symmentric matrix B, where the eigenval and eigenvec are the respective
//eigenvalues and eigenvectors of the matrix B.


int main()
{
  int N = 6;
  float h = 1/(N-1);
  float a = -1;
  float d = 2;

  arma::mat A = create_tridiagonal(N, a, d, a); //create matrix A from function
  arma::mat B = A.t()*A; //create symmetric matrix

  //arma::diagmat(arma::sum(A, 1)).print("B");


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
