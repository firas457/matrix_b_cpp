#include <iostream>
#include <vector>

namespace zich
{
	class Matrix;
	Matrix operator+(const double &scalar, const Matrix &mat);
	Matrix operator-(const double &scalar, const Matrix &mat);
	Matrix operator*(const double &scalar, const Matrix &mat);
	Matrix operator*(double const &scalar, Matrix &mat);
	std::ostream &operator<<(std::ostream &out, const Matrix &mat);
	std::istream &operator>>(std::istream &in, Matrix &mat);

} 

class zich::Matrix
{

private:
	std::vector<std::vector<double>> mat;
	int R;
	int C;

public:
	Matrix(std::vector<double> vec, int R, int C) : mat(std::vector<std::vector<double>>((size_t)R, std::vector<double>((size_t)C, 0.0))), R(R), C(C)
	{
		
		if (R * C != vec.size())
		{
			throw std::invalid_argument("R * C should be equal to vector size\n");
		}

		
		for (size_t i = 0; i < R; ++i)
		{
			for (size_t j = 0; j < C; ++j)
			{
				mat[i][j] = vec.at((i * (size_t)C) + j);
			}
		}
	}
	Matrix() : R(2), C(2) {}
	Matrix(const Matrix& matrix) : mat(matrix.mat), R(matrix.R), C(matrix.C) {} 
	~Matrix();
	Matrix operator+(const double &scalar) const;
	Matrix &operator+=(const double &scalar);
	Matrix operator+() const;
	friend Matrix operator+(const double &scalar, const Matrix &mat);
	Matrix operator+(const Matrix &mat) const;
	Matrix &operator+=(const Matrix &mat);
	Matrix operator-(const double &scalar) const;
	Matrix &operator-=(const double &scalar);
	Matrix operator-() const;
	friend Matrix operator-(const double &scalar, const Matrix &mat);
	Matrix operator-(const Matrix &mat) const;
	Matrix &operator-=(const Matrix &mat);
	Matrix operator*(const double &scalar) const;
	Matrix &operator*=(const double &scalar);
	friend Matrix operator*(const double &scalar, const Matrix &mat);
	friend Matrix operator*(double const &scalar, Matrix &mat);
	Matrix operator*(const Matrix &mat) const;
	Matrix &operator*=(const Matrix &mat);
	bool operator<(const Matrix &mat) const;
	bool operator>(const Matrix &mat) const;
	bool operator<=(const Matrix &mat) const;
	bool operator>=(const Matrix &mat) const;
	bool operator==(const Matrix &mat) const;
	bool operator!=(const Matrix &mat) const;
	Matrix &operator++();	 
	Matrix operator++(int); 
	Matrix &operator--();	 
	Matrix operator--(int); 
	friend std::ostream &zich::operator<<(std::ostream &out, const zich::Matrix &mat);
	friend std::istream &operator>>(std::istream &in, Matrix &mat);

};