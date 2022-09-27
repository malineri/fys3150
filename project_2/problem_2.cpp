#include <iostream>
#include <vector>
#include <armadillo>



int main()
{
  int N = 6
  mat A(N, N, fill::randu);
  vec v = std::vector<int> v2(N);

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, B);

  }

  return 0;

}  
