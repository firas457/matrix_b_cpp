#include<vector>
#include<iostream>
#include "sources/Matrix.hpp"
using namespace std;
using namespace zich;

int main(){



std::vector<double> mat1={ 1, 0, 0, 
                           0, 1, 0,
                           0, 0, 1
                          ,3, 2, 1};

std::vector<double> mat2={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1,
                           1, 1, 1};

zich::Matrix  ma1{mat1,3,3};
zich::Matrix  ma2(mat2,4,3);



  cout << ma1 << endl;

std::cout << "//////////////////////////////////////" << endl;

  cout << -ma1 << endl;

std::cout << "//////////////////////////////////////" << endl;

  cout << ma1 + ma2 << endl;

  std::cout << "//////////////////////////////////////" << endl;

  cout << ma1 - ma2 << endl;

  std::cout << "//////////////////////////////////////" << endl;

  cout << ma2 << endl;

  std::cout << "//////////////////////////////////////" << endl;

  cout << 4 + ma1 << endl;

  std::cout << "//////////////////////////////////////" << endl;

  cout << ma1 * ma2 << endl;
  

  std::cout << "//////////////////////////////////////" << endl;

  cout << ma1 * 5 << endl;

  std::cout << "//////////////////////////////////////" << endl;

  cout << ma2 * 2 << endl;

  
}

