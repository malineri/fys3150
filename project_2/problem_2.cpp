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
  //for (double i; i <A.size(); i++){
  //  A(i, i).push_back(d);
  //  A(i, i + 1).push_back(a);
  //  A(i + 1, i).push_back(e);
  //}

  //Manually writing in the diagonal
  A(0, 0) = d;
  A(1, 1) = d;
  A(2, 2) = d;
  A(3, 3) = d;
  A(4, 4) = d;
  A(5, 5) = d;

  //Manually writing in the upper diagonal
  A(0, 1) = a;
  A(1, 2) = a;
  A(2, 3) = a;
  A(3, 4) = a;
  A(4, 5) = a;


  //Manually writing in the lower diagonal
  A(1, 0) = e;
  A(2, 1) = e;
  A(3, 2) = e;
  A(4, 3) = e;
  A(5, 4) = e;



  // Loop that fills rows 2 to n-1 (row indices 1 to n-2)

  // Fill last row (row index n-1)

  return A;
}



std::vector<double> eigenvalue(double d, double a, int n){
  std::vector<double> l;
  for (double i; i < n; i++){
     l.push_back(d + (2*a*cos((i*M_PI)/(n + 1))));
  }
  return l;

}

std::vector<double> eigenvec(double d, double a, int n){
  std::vector<double> v;
  for (double i; i < n; i++){
    for (double j; j < n; j++){
      v.push_back(sin(((n*j)*M_PI)/(n + 1)));
  }}
  return v;

}





//Creating a program that takes an NxN Matrix A filled with random numbers,
//and generate a symmentric matrix B, where the eigenval and eigenvec are the respective
//eigenvalues and eigenvectors of the matrix B.


int main()
{
  int N = 6.;
  float h = 1;
  float a = (-1.)/(h*h);
  float d = (2.)/(h*h);

  arma::mat A = create_tridiagonal(N, a, d, a); //create matrix A from function
  //arma::mat B = A.t()*A; //create symmetric matrix

  //arma::diagmat(arma::sum(A, 1)).print("B");


  arma::vec eigval;
  arma::mat eigvec;

  arma::eig_sym(eigval, eigvec, A);







  // Parameters for output formatting
  int width = 18;
  int prec  = 10;


  //output Eigenvectors and Eigenvalues
  std::cout << "#" << std::setw(width-1) << "Matrix A"
            << std::endl;


  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << A
            << std::endl;

  std::cout << "#" << std::setw(width-1) << "Eigenvectors"
            << std::endl;


  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << eigvec
            << std::endl;



  std::cout << std::setw(width - 1) << "Eigenvalues"
            << std::endl;

  std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << eigval
            << std::endl;





  arma::vec Eigenvalue = eigenvalue(d, a, N);
  arma::vec Eigenvector = eigenvec(d, a, N);


  std::cout << "#" << std::setw(width-1) << "Eigenvectors analytical"
            << std::endl;
  for (double i; i < N + 1; i++){
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << Eigenvector[i]
              << std::endl;
  }


  std::cout << "#" << std::setw(width - 1) << "Eigenvalues analytical"
            << std::endl;
  for (double i; i < N + 1 ; i++){
    std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << Eigenvalue[i]
              << std::endl;
  }




  return 0;

}
