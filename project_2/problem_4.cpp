#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>

//creating function that finds the index of the biggest element:
double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  double m = INT_MIN;
  for (int k = 0; k < A.n_rows; k++){
    for (int l = 0; l < k; l++){
      if (abs(A(k, l)) > m){
        break;
      }
    }
  }
  return k;

}


//create function that does the rotation on the matrix:
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l){
  double s;
  double c;

  double Akk = A[k][k];
  double All = A[l][l];
  double Akl = A[k][l];

  double Ail;
  double Aik;
  double vik;
  double vil;

  //rotation constants:
  if (Akl != 0){
    double tau = (All - Akk)/(2*Akl);
    double t;

    if (tau >= 0){
      t = 1/(tau + sqrt(1 + tau*tau));
    } else {
      t = -1/(-tau + sqrt(1 + tau*tau));
    }
    c = 1/sqrt(1 + t*t);
    s = c*t;
  } else {
    c = 1;
    s = 0;
  }
    }
  }


  //rotating matrix:
  A[k][k] = c*c*Akk - 2*Akl*c*s + All*s*s;
  A[l][l] = Akk*s*s + 2*Akl*c*s + All*c*c;
  A[k][l] = 0;
  A[l][k] = 0;

  for (int i = 0; i < A.n_rows; i++){
    if i != k && i != l){
      Aik = A[i][k]
      Ail = A[i][l]
      A[i][k] = Aik*c - Ail*s;
      A[k][i] = Aik*c - Ail*s;
      A[i][l] = Ail*c + Aik*s;
      A[l][i] = Ail*c + Aik*s;
    }
    // Rotating vectors
    vik = v[i][k];
    vil = v[i][l];

    v[i][k] = c*vik - s*vil;
    v[i][l] = c*vil + s*vik;
  }

}

//create function that solves the jacobi rotation method:
void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors,
                        const int maxiter, int& iterations, bool& converged);




int main(){
  N  = 6
  arma::mat A = arma::mat(N, N, arma::fill:random);
  arma::mat R = arma::mat(N, N, arma::fill::eye);
  arma::mat S = jacobi_rotate(A, R, k, l);
  arma::vec D = arma::vec(N, arma::fill::zeros);


  double epsilon = pow(10, -8);
  int k = max_offdiag_symmetric(A, N, N)
  int l = k + 1


  jacobi_eigensolver(A, epsilon, D, S)








  return 0;

}
