#include<iostream>
#include"Matrix.hpp"
#include"doctest.h"
#include <vector>

using namespace std;
using namespace zich;

TEST_CASE("check all the operators that are applied on two Matrixs"){

std::vector<double> mat1={ 1, 0, 0, 
                           0, 1, 0,
                           0, 0, 1};

std::vector<double> mat2={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1,
                           1, 1, 1};

Matrix ma1(mat1,3,3);
Matrix ma2(mat2,4,3);

////////////////  multiply   ///////////////////

//multiply matrix (3*3) *(4*3)
CHECK_THROWS(ma1 * ma2);

//multiply matrix (4*3) * (3*3) 
CHECK_NOTHROW(ma2 * ma1);

//multiply matrix (4*3) * (4*3)
CHECK_THROWS(ma2 * ma2);

//multiply matrix (3*3) * (3*3)
CHECK_NOTHROW(ma1 * ma1);




////////////////  operator *=   ///////////////////

//multiply matrix (3*3) *= (4*3)
CHECK_THROWS(ma1 *= ma2);

//multiply matrix (4*3) *= (3*3) 
CHECK_NOTHROW(ma2 *= ma1);

//multiply matrix (4*3) *= (4*3)
CHECK_THROWS(ma2 * ma2);

//multiply matrix (3*3) *= (3*3)
CHECK_NOTHROW(ma1 *= ma1);









////////////////  add   ///////////////////

//add two matrixs (3*3) + (4*3)
CHECK_THROWS(ma1 + ma2);

//add two matrixs (4*3) + (3*3)
CHECK_THROWS(ma2 + ma1);

//add two matrixs (4*3) + (4*3)
CHECK_NOTHROW(ma2 + ma2);

//add two matrixs (3*3) + (3*3)
CHECK_NOTHROW(ma1 + ma1);


////////////////  minus   ///////////////////

//add two matrixs (3*3) + (3*3)
CHECK_THROWS(ma1-ma2);

//add two matrixs (3*3) + (3*3)
CHECK_THROWS(ma2-ma1);

//add two matrixs (3*3) + (3*3)
CHECK_NOTHROW(ma2-ma2);

//add two matrixs (3*3) + (3*3)
CHECK_NOTHROW(ma1-ma1);




////////////////  minus equal (-=)   ///////////////////

//add two matrixs (3*3) -= (4*3)
CHECK_THROWS(ma1-=ma2);

//add two matrixs (4*3) -= (3*3)
CHECK_THROWS(ma2-=ma1);

//add two matrixs (4*3) -= (4*3)
CHECK_NOTHROW(ma2-=ma2);

//add two matrixs (3*3) -= (3*3)
CHECK_NOTHROW(ma1-=ma1);




////////////////  operator <   ///////////////////
std::vector<double> matt={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1};

Matrix mat_1(matt,3,3);

//mat_1 is bigger than ma1 ----> TRUE
CHECK_FALSE(!(ma1 < mat_1));

//mat_1 is bigger than mat_1 ----> FALSE
CHECK_FALSE(mat_1 < mat_1);


//ma1 is bigger than mat_1 ----> FALSE
CHECK_FALSE(mat_1 < ma1);


//ma2 is bigger than ma2 ----> FALSE
CHECK_FALSE(ma2 < ma2);


//ma1 is bigger than ma1 ----> FALSE  

CHECK_FALSE(ma1<ma1);








////////////////     operator >   ///////////////////
std::vector<double> mattt={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1};

Matrix mat_2(mattt,3,3);

// ma1
//                          { 1, 0, 0, 
//                           0, 1, 0,
//                           0, 0, 1};


//ma1 is bigger than mat_2 ----> FALSE
CHECK_FALSE(!(ma1 > mat_2));

//mat_2 is bigger than ma1 ----> TRUE
CHECK_FALSE(!(mat_2 > ma1));


//mat_1 is bigger than mat_2 ----> FALSE
CHECK_FALSE(mat_1 > mat_2);


//ma2 is bigger than ma2 ----> FALSE
CHECK_FALSE(ma2 > ma2);


//ma1 is bigger than ma1 ----> FALSE  

CHECK_FALSE(ma1>ma1);









//////////////     operator >=   ///////////////////
std::vector<double> mat_tmp1={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1};

std::vector<double> mat_tmp2={ 2, 2, 2,
                           1, 2, 2 
                          ,1, 2, 1};                          

Matrix mat_t1(mat_tmp1,3,3);
Matrix mat_t2(mat_tmp2,3,3);

// ma1
//                          { 1, 0, 0, 
//                           0, 1, 0,
//                           0, 0, 1};

//ma1 is bigger or equal than ma1 ----> TRUE
CHECK_FALSE(!(ma1 >= ma1));


//ma2 is bigger or equal than ma2 ----> TRUE
CHECK_FALSE(!(ma2 >= ma2));


//ma1 is bigger or equal than ma1 ----> TRUE  
CHECK_FALSE(!(ma2 >= ma2));

//mat_t1 is bigger or equal than mat_t2 ----> Flase  
CHECK_FALSE(mat_t1 >= mat_t2);

//mat_t2 is bigger or equal than mat_t1 ----> true 
CHECK_FALSE(!(mat_t2 >= mat_t1));


//mat_t2 is bigger or equal than mat_t2 ----> true 
CHECK_FALSE(!(mat_t2 >= mat_t2));

//mat_t1 is bigger or equal than mat_t1 ----> true 
CHECK_FALSE(!(mat_t1 >= mat_t1));



// ////////////////     operator <=   ///////////////////

std::vector<double> mat_tmp3={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1};

std::vector<double> mat_tmp4={ 2, 2, 2,
                           1, 2, 2 
                          ,1, 2, 1};                          

Matrix mat_t3(mat_tmp3,3,3);
Matrix mat_t4(mat_tmp4,3,3);

// ma1
//                          { 1, 0, 0, 
//                           0, 1, 0,
//                           0, 0, 1};


//ma1 is less than or equal than ma1 ----> TRUE
CHECK_FALSE(!(ma1 <= ma1));


//ma2 is less than or equal  ma2 ----> TRUE
CHECK_FALSE(!(ma2 <= ma2));


//ma1 is less than or equal ma1 ----> TRUE  
CHECK_FALSE(!(mat_t3 <= mat_t3));


//mat_t3 is less than or equal mat_t4 ----> TRUE 
CHECK_FALSE(!(mat_t3 <= mat_t4));

//mat_t4 is less than or equal mat_t3 ----> false
CHECK_FALSE(mat_t4 <= mat_t3);


//ma2 is less than or equal ma1 ----> false 
CHECK_FALSE(ma2 <= ma1);






////////////////     operator ==   ///////////////////

// //ma1 is equal to ma2 ----> different matrix dimensions
// CHECK_THROWS(ma1 == ma2);


//ma2 is equal to ma2 ----> TRUE
CHECK_FALSE(!(ma2 == ma2));


//ma1 is equal to ma1 ----> TRUE  

CHECK_FALSE(!(ma1==ma1));


//mat_t3 is equal to mat_t4 ----> False
CHECK_FALSE(mat_t3 == mat_t4);

//mat_t3 is equal to ma1 ----> False
CHECK_FALSE(mat_t3 == ma1);


//ma1 is equal to ma1 ----> TRUE  

CHECK_FALSE(!(ma1==ma1));



// //ma2 is equal to ma1 ----> different matrix dimensions
// CHECK_THROWS(ma2==ma1);





////////////////     operator !=   ///////////////////

// //ma1 is not equal to ma2 ----> different matrix dimensions
// CHECK_THROWS(ma1 != ma2);


//ma2 is not equal to ma2 ----> FALSE
CHECK_FALSE(ma2 != ma2);


//ma1 is not equal to ma1 ----> FALSE  

CHECK_FALSE(mat_t2!=mat_t2);

//ma2 is not equal to ma2 ----> false
CHECK_FALSE(ma2 != ma2);


//ma1 is not equal to ma1 ----> false  

CHECK_FALSE(ma1!=ma1);


//mat_t3 is not equal to mat_t4 ----> true
CHECK_FALSE(!(mat_t3 != mat_t4));

//mat_t3 is not equal to ma1 ----> true
CHECK_FALSE(!(mat_t3 != ma1));



// //ma2 is not equal to ma1 ----> different matrix dimensions

// CHECK_THROWS(ma2!=ma1);


}





 TEST_CASE("oprators that we can apply on one single Matrix"){

std::vector<double> mat1={ 1, 2, 0, 
                           2, 1, 0,
                           0, 2, 1};



// mat2=mat1 * 2
std::vector<double> mat2={ 2, 4, 0, 
                           4, 2, 0,
                           0, 4, 2};

// sum_mat=mat1 + mat2
std::vector<double> sum_mat={ 3, 6, 0, 
                           6, 3, 0,
                           0, 6, 3};


Matrix ma1(mat1,3,3);

Matrix ma2(mat2,3,3);


Matrix sum_ma(sum_mat,3,3);

////////////////  operator  +  ///////////////////

std::vector<double> mat_ch={ 1, 1, 1,
                           1, 1, 1 
                          ,1, 1, 1,
                           1, 1, 1};
  Matrix mat_tmp(mat_ch,4,3);

//ma1 + ma2 = sum_ma  ----> true
//!(true)=false
CHECK_FALSE( !( sum_ma==(ma1 + ma2) ) );


//ma1 + ma2 = ma1  ----> False
CHECK_FALSE(ma1==(ma1 + ma2));


//ma1 + ma2 = ma2  ----> False
CHECK_FALSE(ma2==(ma1 + ma2));



//ma1 + ma1 = ma2  ----> TRUE
CHECK_FALSE(!(ma2==(ma1 + ma1)));



////////////////  operator  +=  ///////////////////
// ma1  =
//                            { 1, 2, 0, 
//                            2, 1, 0,
//                            0, 2, 1};

//  ma2 =                     { 2, 4, 0, 
//                            4, 2, 0,
//                            0, 4, 2};

// sum_mat =                 { 3, 6, 0, 
//                            6, 3, 0,
//                            0, 6, 3};


//ma1 += ma1 ---->  NORTHROW
//!(true)=false
CHECK_NOTHROW(ma1+=ma1);


//ma1 += ma2 ----> NOTHROW
CHECK_NOTHROW(ma1 += ma2);


//mat_tmp += ma1 ----> THROW --- different dimensions
CHECK_THROWS(mat_tmp+=ma1);


//ma1 += mat_tmp ----> THROW --- different dimensions
CHECK_THROWS(ma1+=mat_tmp);



//////////////  operator  *  ///////////////////

std::vector<double> zero_mat={ 0, 0, 0,
                           0, 0, 0 
                          ,0, 0, 0};
//
  Matrix mat_zero(zero_mat,3,3);


  std::vector<double> a_mat={ 1, 1, 1,
                           0, 0, 0 
                          ,1, 1, 1};
//                         
  Matrix a1_mat(a_mat,3,3);


  std::vector<double> b_mat={ 2, 2, 2,
                           0, 0, 0 
                          ,2, 2, 2};
//                         
  Matrix b1_mat(b_mat,3,3);

//a1_mat * 2 = b1_mat ---->  TRUE
//!(true)=false
CHECK_FALSE(a1_mat* 2==b1_mat);

//mat_zero * 3 = mat_zero ---->  TRUE
CHECK_FALSE(!(mat_zero * 3 == mat_zero));

//a1_mat * 0 = mat_zero ---->  TRUE

CHECK_FALSE(!(a1_mat* 0==mat_zero));


//b1_mat * 0 = mat_Zero ---->  TRUE

CHECK_FALSE(!(b1_mat* 0==mat_zero));




////////////////  operator  ++  ///////////////////
std::vector<double> _mat={ 1, 1, 0,
                           0, 2, 0 
                          ,0, 2, 0};
//
  Matrix mat_beforeplus(_mat,3,3);


std::vector<double> plus_mat={ 2, 2, 1,
                           1, 3, 1 
                          ,1, 3, 1};
//
  Matrix mat_after(plus_mat,3,3);



mat_beforeplus++;

//should be equal after one added to matrix
CHECK_FALSE(!(mat_beforeplus==mat_after));



mat_beforeplus++;
mat_after++;

//should be equal after one added to each matrix
CHECK_FALSE(!(mat_beforeplus==mat_after));




 }