#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include "MatClass.h"



Matrix::Matrix()
{
	Rows = 0;
	Cols = 0;
}
Matrix::Matrix(int rows, int cols)
{
	Rows = rows;
	Cols = cols;
	pMatrix = std::vector<std::vector<double>>(Rows, std::vector<double>(Cols));
}

Matrix::Matrix(int size)
{
	Rows = size;
	Cols = size;
	pMatrix = std::vector<std::vector<double>>(Rows, std::vector<double>(Cols));
}

Matrix::Matrix(const Matrix& matrix)
{
	Rows = matrix.Rows;
	Cols = matrix.Cols;
	pMatrix = std::vector<std::vector<double>>(Rows, std::vector<double>(Cols));
}
Matrix::~Matrix()
{

}
Matrix Matrix::MatMulti(double num)
{
	Matrix result(Rows, Cols);
	result = *this;
	for (int i = 0; i < result.Rows; i++)
	{
		for (int j = 0; j < result.Cols; j++)
		{
			result.pMatrix[i][j] *= num;
		}
	}
	return result;
}
Matrix Matrix::MatTrans(const Matrix& matrix)
{
	Matrix transposed(matrix.Cols, matrix.Rows);

	for (int i = 0; i < matrix.Rows; ++i) {
		for (int j = 0; j < matrix.Cols; ++j) {
			transposed.pMatrix[j][i] = matrix.pMatrix[i][j];
		}
	}
	return transposed;
}
Matrix Matrix::FindMinor(int IRow, int ICol)
{
	Matrix minor(Rows - 1, Cols - 1);
	int minorRow = 0;
	for (int i = 0; i < Rows; i++)
	{
		if (i == IRow)
		{
			continue;
		}
		int minorCol = 0;
		for (int j = 0; j < Cols; j++)
		{
			if (j == ICol)
			{
				continue;
			}
			minor.pMatrix[minorRow][minorCol] = pMatrix[i][j];
			minorCol++;
		}
		minorRow++;
	}
	return minor;
}

double Matrix::det(const Matrix& matrix)
{
	const Matrix& mat = (matrix.Rows != 0) ? matrix : *this;
	double det = 0;
	if (mat.Rows != mat.Cols)
	{
		std::cerr << "Error while finding det: Matrix must be square!" << std::endl;
		return 0;
	}
	if (mat.Rows == 1)
	{
		return mat.pMatrix[0][0];
	}
	else if (mat.Rows == 2)
	{
		det = (mat.pMatrix[0][0] * mat.pMatrix[1][1] - mat.pMatrix[0][1] * mat.pMatrix[1][0]);
		return det;
	}
	else
	{
		for (int p = 0; p < mat.Rows; p++)
		{
			int sign = (p % 2 == 0) ? 1 : -1;
			Matrix tempminor(mat.Rows - 1, mat.Cols - 1);
			tempminor = FindMinor(p, 0);
			det += mat.pMatrix[p][0] * sign * tempminor.det();
		}
		return det;
	}
}
Matrix Matrix::MatAdj(const Matrix& matrix)
{
	const Matrix& mat = (matrix.Rows != 0) ? matrix : *this;
	Matrix MoM(mat.Rows, mat.Cols);
	for (int i = 0; i < mat.Rows; i++)
	{
		for (int j = 0; j < mat.Cols; j++)
		{
			int sign = ((i + j) % 2 == 0) ? 1 : -1;

			MoM.pMatrix[i][j] = sign * det(FindMinor(i, j));
		}
	}
	MoM.MatTrans(MoM);
	return(MoM);
}

Matrix Matrix::MatInv(const Matrix& matrix)
{
	double determinant = det();
	if (determinant == 0)
	{
		std::cerr << "Inverse does not exist!" << std::endl;
	}
	Matrix adjugate(matrix.Rows, matrix.Cols);
	adjugate = MatAdj(matrix);
	std::cout << adjugate << std::endl;
	adjugate /= determinant;
	return adjugate;
}
Matrix Matrix::MatMulti( Matrix& matrix,  Matrix& matrix2)
{
	
	if (matrix.Cols == matrix2.Rows)
	{
		
		Matrix result(matrix.Cols, matrix2.Rows);
		for (int i = 0; i < result.Rows; i++)
		{
			
			for (int j = 0; j < result.Cols; j++)
			{
				for (int k = 0; k < matrix.Cols; k++)
				{
					result.pMatrix[i][j] += (matrix.pMatrix[i][k] * matrix2.pMatrix[k][j]);
				}
			}
		}
		std::cout << result << std::endl;
		return result;
	}
	else
	{
		std::cout << "Cannot be multiplied!" << std::endl;
		return *this;
	}
}

Matrix Matrix::operator/(double num)
{
	if (num == 0)
	{
		std::cerr << "Division by 0 is not permissible!!!" << std::endl;
		return Matrix();
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			pMatrix[i][j] /= num;
		}
	}
	std::cout << *this << std::endl;
	return *this;
}

Matrix Matrix::operator=(const Matrix& matrix)
{
	if (this != &matrix)
	{
		pMatrix.clear();
		Rows = matrix.Rows;
		Cols = matrix.Cols;
		pMatrix.resize(Rows, std::vector<double>(Cols));

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				pMatrix[i][j] = matrix.pMatrix[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator/=(double num)
{
	if (num == 0)
	{
		std::cerr << "Division by 0 is not permissible!!!" << std::endl;
		return *this;
	}

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			pMatrix[i][j] /= num;
		}
	}

	return *this;
}

Matrix Matrix::operator*(double num)
{
	Matrix result(Rows, Cols);
	for (int i = 0; i < Rows; ++i) {
		for (int j = 0; j < Cols; ++j) {
			result.pMatrix[i][j] = pMatrix[i][j] * num;
		}
	}
	return result;
}


Matrix& Matrix::operator*=(double num) 
{
	for (int i = 0; i < Rows; ++i) {
		for (int j = 0; j < Cols; ++j) {
			pMatrix[i][j] *= num;
		}
	}
	return *this;
}



std::istream& operator>> (std::istream& s, Matrix& matrix)
{
	for (int i = 0; i < matrix.Rows; i++)
	{
		for (int j = 0; j < matrix.Cols; j++)
		{
			s >> matrix.pMatrix[i][j];
		}
	}
	return s;
}

std::ostream& operator<< (std::ostream& s, const Matrix& matrix)
{
	for (int i = 0; i < matrix.Rows; i++)
	{
		for (int j = 0; j < matrix.Cols; j++)
		{
			s << matrix.pMatrix[i][j];
			if (j < matrix.Cols - 1)
				s << ",";
		}
		s << "\n";
	}
	return s;
}





