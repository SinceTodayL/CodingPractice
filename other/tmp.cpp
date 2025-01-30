#include<iostream>
#include<cstring>
#include<vector>
#include<array>
#include<initializer_list>
#include<stdexcept>
using namespace std;


template <size_t row, size_t column>
class Matrix {
private:
	array<array<float, column>, row> matrix;

public:
	Matrix() {
		memset(matrix, 0, sizeof(matrix));
	}

	Matrix(float first, ...) {
		va_list args;
		va_start(args, first);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				matrix[i][j] = va_arg(args, float); 

		va_end(args); 
	}

	Matrix(std::initializer_list<float> arguments) {   // can accepts 16(row*column) values as matrix elements

		if (arguments.size() > row * column)
			throw invalid_argument("Too many elements are passed in!");

		memset(matrix, 0, sizeof(matrix));

		// if arguments.size() < row * column, use 0 to fill
		int i = 0, j = 0;
		for (float value : arguments) {
			matrix[i][j++] = value;
			if (j >= column) {
				j = 0;
				i++;
			}
		}
	}

	Matrix(const array<float, row * column>& arguments) {  // accept an array of size 16(row)
		int i = 0, j = 0;
		for (float value : arguments) {
			matrix[i][j++] = value;
			if (j >= column) {
				j = 0;
				i++;
			}
		}
	}

	Matrix& operator=(Matrix& other) {
		if (other.row != row || other.column != column)
			throw invalid_argument("different size matrix can not use '='!");

		this->matrix = other.matrix;

		return *this;
	}

	Matrix& operator+(const Matrix& other) const {
		Matrix result = *this;
		
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < column; ++j)
				result.matrix[i][j] += other.matrix[i][j];

		return result;
	}

	Matrix& operator+=(const Matrix& other) {
		*this = *this + other;
		return *this;
	}

	Matrix operator*(const Matrix& other) {
		if (column != other.row)
			throw invalid_argument("invalid matrix multiply!");

		Matrix<row, other.column> result;
		for (int i = 0; i < row; ++i) 
			for (int j = 0; j < other.column; ++j) 
				for (int k = 0; k < column; ++k) {
					result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
				}

		return result;
	}

	float& operator()(int Row, int Col) {  // can be modified
		return this->matrix[Row - 1][Col - 1];
	}
	float operator()(int Row, int Col) const {  // only read
		return this->matrix[Row - 1][Col - 1];
	}

	void print_matrix() const {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				cout << this->matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend ostream& operator<<(ostream& os, const Matrix<row, column>& matrix_print);
};

template<size_t row, size_t column>
ostream& operator<<(ostream& os, Matrix<row, column>& matrix_print) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << matrix_print.matrix[i][j] << " ";
		}
		cout << endl;
	}
	return os;
}

void test_function() {
	Matrix<4, 4> m1 = { 3,4,5,6,7,8,5,6,4,6,5,4,3,4,5,6 };
	Matrix<4, 4> m2({ 3.0f, 5.0f, 2.0f, 5.0f, 2.0f, 5.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 3.0f, 2.0f, 1.0f, 3.0f, 3.0f });

	cout << m1 + m2 << endl;
	cout << m1 * m2 << endl;
	
}
