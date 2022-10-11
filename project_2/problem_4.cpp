#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <armadillo>





// creating NxN matrix A:
arma::mat create_tridiagonal(int n, double a, double d, double e)
{
  // Start from identity matrix
  arma::mat A = (n, n, arma::fill::eye)*d;
  A(0, 1) = a;
    for(int i = 1; i < n - 1; i++){
      A(i, i + 1) = a;
      A(i, i - 1) = e;
  }
  A(N, N - 1) = e;
  return A;
}







//creating function that finds the index of the biggest element:
double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){
  double m = INT_MIN;
  int k;
  int l;
  for (int k = 0; k < A.n_rows; k++){
    for (int l = 0; l < k; l++){
      if (abs(A(k, l)) > m){
        m = A(k, l);
      }
    }
  }
  return m;

}



//finding the indecies to the maximum value M
double max(double &M, int &k, int &l){
    k = 0; l = 1;
    return M+1;
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
void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged);
double tau{
  while (A(k, l) > eps){
    tau = (All - Akk)/(2*Akl)
    k++; l++;
    if (tau > 0){
      t = -tau + sqrt(1 + (tau*tau))
    } else {
      t = -tau - sqrt(1 + (tau*tau))
    }
  }
  c_1 = 1/(sqrt(1 + (t*t)));
  s_1 = c_1*t

  arma::mat s_m = arma::mat(A.n_rows, A.n_cols, arma::fill::eye);
  s_m(k, k) = c_1;
  s_m(k, l) = s_1;
  s_m(l, k) = -s_1;
  s_m(l, l) = c_1;

  arma::mat s_t = arma::mat(A.n_rows, A.n_cols, arma::fill::zeros);
  for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            s_t[i][j] = s_m[j][i];

  while (A(k, l) > eps){
    D = s_t*A(k,l)*s_m
    k++; l++;
  }
}









int main(){

  //values to determine the A matrix:
  N  = 6
  h = 1/(N - 1)
  double a = -1/(h*h)
  double d = 2/(h*h)
  double e = -1/(h*h)

  arma::mat A = arma::mat create_tridiagonal(N, a, d, e)
  arma::mat R = arma::mat(N, N, arma::fill::eye);

  //finding k and l value from max_val function:
  double max_val = max_offdiag_symmetric(A, N, N);
  int k; int l;
  double B = max(max_val, k, l);
  //std::cout << A << B << k << l << std::endl;


  double epsilon = pow(10, -8);
  arma::mat S = jacobi_rotate(A, R, k, l);
  arma::vec D = arma::vec(N, arma::fill::eye);



  //jacobi_eigensolver(A, epsilon, D, S, )



  return 0;

}
