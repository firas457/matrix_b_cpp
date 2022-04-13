#include <iostream>
#include <vector>
#include "Matrix.hpp"

 using namespace zich;


//this function is used in operator>> imple

std::vector<std::string> split(std::string str, const std::string &sub_st)
{
    std::vector<std::string> ans;

    while (!str.empty())
    {
        
        size_t index = str.find(sub_st);

       
        if (index == std::string::npos)
        {
            ans.push_back(str);
            break;
        }

        ans.push_back(str.substr(0, index));
        str = str.substr(index + sub_st.size(), str.size());
    }

    return ans;
}


//detructor
Matrix::~Matrix() {}



//add scalar to a matrix
//return a new matrix
Matrix Matrix::operator+(const double &scalar) const
{
    std::vector<double> temp_vec;

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            temp_vec.push_back(this->mat[i][j] + scalar);
        }
    } 

Matrix mat(temp_vec, this->R, this->C);

    return mat;
}



Matrix Matrix::operator+() const { 
    return *this; 
}

// scalar + matrix
// return new_matrix = scalar + matrix
Matrix zich::operator+(const double &scalar, const Matrix &mat) { 

    std::vector<double> temp_vec;

        for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; ++j)
        {

           temp_vec.push_back(mat.mat[i][j] + scalar);
        }
    }

Matrix mata(temp_vec,mat.R,mat.C);

    return mata;

    }


// add scalar to a given matrix
// return the same matrix with scalar added
//iterate throuth the whole matrix
// for mat[i][j] add a the given scalar(number)
Matrix &Matrix::operator+=(const double &scalar)
{
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            this->mat[i][j] += scalar;
        }
    }

    return *this;
}


//add two matrixes
// return a new matrix that is equal to the sum of the two matrixes
Matrix Matrix::operator+(const Matrix &mat) const
{
    
    if (this->R != mat.R )
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }
    
    std::vector<double> temp_vec;

    for (size_t i = 0; i < this->mat.size(); i++)
    {
        for (size_t j = 0; j < this->mat[i].size(); j++)
        {
            temp_vec.push_back(this->mat[i][j] + mat.mat[i][j]);
        }
    }

     Matrix mata(temp_vec, this->R, this->C);

     return mata;
}


//add two matrixes
//put the outputsum in the matrix behind the operator+=
Matrix &Matrix::operator+=(const Matrix &mat)
{
    
      if (this->R != mat.R)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            this->mat[i][j] += mat.mat[i][j];
        }
    }

    return *this;
}


//matrix - sclar
//puth the output in the matrix
Matrix Matrix::operator-(const double &scalar) const {

std::vector<double> temp_vec;

        for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {

           temp_vec.push_back(this->mat[i][j] - scalar);
        }
    }

Matrix mat(temp_vec,this->R,this->C);

    return *this;
     }


// subset a scalar to a given matrix
// return the same matrix  minus the given scalar 
//iterate throuth the whole matrix
// for mat[i][j] minus the given scalar(number)
Matrix &Matrix::operator-=(const double &scalar)
{

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {

            this->mat[i][j] -= scalar;
        }
    }


    return *this;
}


// - matrix
// -1 multiplyed for every [i][j] in the matrix
// multiply the matrix with -1
Matrix Matrix::operator-() const
{

    std::vector<double> temp_vec;

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            temp_vec.push_back(-this->mat[i][j]);
        }
    }

    Matrix mata(temp_vec, this->R, this->C);

    return mata;
}


// scalar - matrix
// first multiply the matrix with -1
// then add scalar to it
// scalar + (-matrix)
// return the output as new matrix
Matrix zich::operator-(const double &scalar, const Matrix &mat) {

      std::vector<double> temp_vec;

    for (size_t i = 0; i <mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; ++j)
        {
            temp_vec.push_back(-mat.mat[i][j] + scalar);
        }
    }

    Matrix mata(temp_vec, mat.R, mat.C);

    return mata;

     }


// matrix1 - matrix2
// matrix1(behind the operator) will be added to (-matrix2)
// matrix1 + (-matrix2)
Matrix Matrix::operator-(const Matrix &mat) const {

     return *this + (-mat); 

     }


// matrix1 -= matrix2
// make matrix1 - matrix2
// put the output in matrix1
Matrix &Matrix::operator-=(const Matrix &mat)
{
    
      if (this->R != mat.R )
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            this->mat[i][j] -= mat.mat[i][j];
        }
    }

    return *this;
}


//matrix * scalar
// return a new matrix multiplied by a scalar
Matrix Matrix::operator*(const double &scalar) const
{
    std::vector<double> temp_vec;

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            temp_vec.push_back(this->mat[i][j] * scalar);
        }
    }

Matrix mata(temp_vec, this->R, this->C);

    return mata;

}


//matrix * scalar
// return matrix multiplied by scalar(the same matrix)

Matrix &Matrix::operator*=(const double &scalar)
{
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; ++j)
        {
            this->mat[i][j] *= scalar;
        }
    }

    return *this;
}


//scalar * matrix
// return a new matrix that is equal to the 
//multipication between scalar and matrix
// matrix is const
Matrix zich::operator*(const double &scalar, const Matrix &mat) {
         std::vector<double> temp_vec;

    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; ++j)
        {
            temp_vec.push_back(mat.mat[i][j] * scalar);
        }
    }

Matrix mata(temp_vec, mat.R, mat.C);

    return mata;

     }



//scalar * matrix
// return a new matrix that is equal to the 
//multipication between scalar and matrix
// matrix isn't const

Matrix zich::operator*(double const &scalar, Matrix &mat) { 
       std::vector<double> temp_vec;

    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; ++j)
        {
            temp_vec.push_back(mat.mat[i][j] * scalar);
        }
    }

Matrix mata(temp_vec, mat.R, mat.C);

    return mata;

    }


//matrix * matrix
// return new_matrix= matrix * matrix
Matrix Matrix::operator*(const Matrix &mat) const
{
    
    if (this->C != mat.R)
    {
        throw std::invalid_argument("diffirent dimensions col2 != row1\n");
    }

   
    std::vector<double> temp_vec;

    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < mat.C; ++j)
        {
            double sum = 0;

            
            for (size_t k = 0; k < this->C; ++k)
            {
                sum += this->mat[i][k] * mat.mat[k][j];
            }

            temp_vec.push_back(sum);
        }
    }

     Matrix mata(temp_vec, this->R, mat.C);
     return mata;
}


//matrix1 *= matrix2
//the output will be returned as the matrix1 
Matrix &Matrix::operator*=(const Matrix &mat)
{
    
    Matrix final_mat = *this * mat;

    this->mat = final_mat.mat;
    this->R = final_mat.R;
    this->C = final_mat.C;

    return *this;
}


//check if matrix1 > matrix2
// dimensions should be equal n * m
bool Matrix::operator>(const Matrix &mat) const
{
  
    if (this->R != mat.R )
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    bool ans=true;

    double first_sum = 0;
    double sec_sum = 0;

    
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; j++)
        {
            first_sum += this->mat[i][j];
        }
    }

    
    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; j++)
        {
            sec_sum += mat.mat[i][j];
        }
    }

     if(first_sum <= sec_sum){
         ans=false;
        return ans;
    }


    return ans;

}


//check if matrix1 < matrix2
// dimensions should be equal n * m
bool Matrix::operator<(const Matrix &mat) const { 

    return (*this <= mat) && *this != mat; 

    }

bool Matrix::operator<=(const Matrix &mat) const { 

    
    if (this->R != mat.R )
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    bool ans=true;

    double first_sum = 0;
    double sec_sum = 0;

    
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; j++)
        {
            first_sum += this->mat[i][j];
        }
    }

    
    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; j++)
        {
            sec_sum += mat.mat[i][j];
        }
    }

     if(first_sum > sec_sum){
         ans=false;
        return ans;
    }


    return ans;

    }


// check if matrix1 >=matrix2
// dimensions should be equal n * m
bool Matrix::operator>=(const Matrix &mat) const { 

   
    if (this->R != mat.R || this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    bool ans=true;

    double first_sum = 0;
    double sec_sum = 0;

    
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; j++)
        {
            first_sum += this->mat[i][j];
        }
    }

    
    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; j++)
        {
            sec_sum += mat.mat[i][j];
        }
    }

     if(first_sum < sec_sum){
         ans=false;
        return ans;
    }


    return ans;

     }


// check if matrix1 == matrix2
// dimensions should be equal n * m
bool Matrix::operator==(const Matrix &mat) const
{

    if (this->R != mat.R)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }


    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; j++)
        {
            if (this->mat[i][j] != mat.mat[i][j])
            {
                return false;
            }
        }
    }

    return true;
}


// check if matrix1 != matrix2
// dimensions should be equal n * m
bool Matrix::operator!=(const Matrix &mat) const {

     
    if (this->R != mat.R )
    {
        throw std::invalid_argument("differint dimensions\n");
    }

     if (this->C != mat.C)
    {
        throw std::invalid_argument("differint dimensions\n");
    }

    bool ans=true;

    double first_sum = 0;
    double sec_sum = 0;

    
    for (size_t i = 0; i < this->R; ++i)
    {
        for (size_t j = 0; j < this->C; j++)
        {
            first_sum += this->mat[i][j];
        }
    }

    
    for (size_t i = 0; i < mat.R; ++i)
    {
        for (size_t j = 0; j < mat.C; j++)
        {
            sec_sum += mat.mat[i][j];
        }
    }

     if(first_sum == sec_sum){
         ans=false;
        return ans;
    }


    return ans;
     
     }


// ++matrix
// add 1 to the whole matrix
// add 1 then return the matrix
Matrix &Matrix::operator++() {
    
    
    for (size_t i = 0; i < this->mat.size(); i++)
    {
         for (size_t j = 0; j < this->mat[i].size(); j++)
    {
        this->mat[i][j] += 1;
    }

    }
    return *this;
     
      } 




// matrix++
//return the matrix then add 1
Matrix Matrix::operator++(int) 
{
    Matrix temp = *this;
    ++*this;
    return temp;
}



// --matrix
// minus 1 then return the matrix
Matrix &Matrix::operator--() { 

      for (size_t i = 0; i < this->mat.size(); i++)
    {
         for (size_t j = 0; j < this->mat[i].size(); j++)
    {
        this->mat[i][j] -= 1;
    }

    }
    return *this;
     
    
     }


// matrix--
//return the matrix then minus 1
Matrix Matrix::operator--(int) 
{

    Matrix temp = *this;
    --*this;
    return temp;

}

// std::cin >> matrix << endl
// input a matrix as a valid string(matrix image)
std::istream &zich::operator>>(std::istream &in, Matrix &mat)
{
    //input 
    std::string str;
    getline(in, str);

    // split "," from the input and
    //store it in a string vector

    std::vector<std::string> bar = split(str, ", ");

   
    //for each row delete [
    bar[0] = bar[0].substr(1, bar[0].size() - 2);

    for (size_t i = 1; i < bar.size(); ++i)
    {
        bar[i] = bar[i].substr(1, bar[i].size() - 2);
    }

    // check if bar is a  valid matrix
    size_t row_length = bar[0].size();

    for (size_t i = 1; i < bar.size(); ++i)
    {
        if (bar[i].size() != row_length)
        {
            throw std::invalid_argument(" Rows should be with same length!\n");
        }
    }

    // convert string vec to double vec
    for (size_t i = 0; i < bar.size(); ++i)
    {
        std::vector<std::string> R = split(bar[i], " ");
        std::vector<double> temp_vec;

        for (size_t j = 0; j < R.size(); ++j)
        {
            temp_vec.push_back(std::stod(R.at(j)));
        }
        mat.mat.push_back(temp_vec);
    }

    return in;
}


// std::cout << matrix << endl
// will print the matrix
std::ostream  &zich::operator<<(std::ostream &out, const zich::Matrix &mat){    
            for (size_t i = 0; i < mat.R; i++){  
                out << "[";
                for (size_t j = 0; j < mat.C; j++){
                    if (j==mat.C-1){
                        out << mat.mat[i][j];
                    }
                   
                    else{out << mat.mat[i][j] << " ";
                    }
                }
            if (i==mat.R-1){

                out << "]";

                    }
                   
            else{ out << "]\n";

                    }

                }    

            return out;

        }
