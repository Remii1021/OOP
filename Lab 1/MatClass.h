#pragma once
#include <vector>
#include <iostream>
#include <fstream>


class Matrix
{
private:
	int Rows;
	int Cols;
	std::vector<std::vector<double>> pMatrix;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(int size);
	Matrix(const Matrix& Matrix);
	~Matrix();
	Matrix MatMulti(double num);
	Matrix MatMulti( Matrix& matrix,  Matrix& matrix2);
	Matrix MatTrans(const Matrix& matrix);
	double det(const Matrix& matrix = Matrix());
	Matrix FindMinor(int IRow, int ICol);
	Matrix MatAdj(const Matrix& matrix = Matrix());
	Matrix MatInv(const Matrix& matrix);
	Matrix operator=(const Matrix& matrix);
	Matrix operator/(double num);
	Matrix& operator/=(double num);
	Matrix operator*(double num);
	Matrix& operator*= (double num);
	friend std::istream& operator>> (std::istream& s, Matrix& matrix);
	friend std::ostream& operator<< (std::ostream& s, const Matrix& matrix);
};
