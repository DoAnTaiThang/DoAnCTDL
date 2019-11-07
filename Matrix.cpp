#include "Matrix.h"

istream& operator>>(istream& reader, matrix* matran)
{
	cout << "Nhap so hang: ";
	reader >> matran->_row;
	cout << "Nhap so cot: ";
	reader >> matran->_column;
	for (int i = 0; i < matran->_row; i++)
	{
		matran->arr[i] = new float[matran->_column];
	}
	for (int i = 0; i < matran->_row; i++)
	{
		for (int j = 0; j < matran->_column; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "]:  ";
			reader >> matran->arr[i][j];
		}
		cout << endl;
	}
	return reader;
}

void nghichdao(matrix* matran, int d)
{
	int i, j;
	float factor = matran->arr[d][d];
	for (i = 0; i < matran->_column; i++) {
		matran->arr[d][i] /= factor;
	}

	for (i = 0; i < matran->_row; i++) {
		if (i != d) {
			factor = matran->arr[i][d];
			for (j = 0; j < matran->_column; j++) {
				matran->arr[i][j] = matran->arr[i][j] - matran->arr[d][j] * factor;
			}
		}
	}
}

matrix* matrix::inverseMaxtrix()
{
	// Tao ma tran b bao gom ma tran goc va ma tran don vi
	matrix* b = new matrix;
	b->_row = _row;
	b->_column = _column * 2;

	for (int i = 0; i < _row; i++)
	{
		b->arr[i] = new float[b->_column];
	}
	for (int i = 0; i < b->_row; i++)
	{
		for (int j = 0; j < b->_column; j++)
		{
			if (j < _column) b->arr[i][j] = this->arr[i][j];
			else {
				if (j == (i + _column)) b->arr[i][j] = 1;
				else b->arr[i][j] = 0;
			}
		}
	}
	for (int d = 0; d < b->_row; d++)
	{
		nghichdao(b, d);
	}
	matrix* invMatrix = new matrix;
	invMatrix->_row = _row;
	invMatrix->_column = _column;
	for (int i = 0; i < _row; i++)
	{
		invMatrix->arr[i] = new float[_column];

	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _column; j++)
		{
			invMatrix->arr[i][j] = b->arr[i][j + _column];
		}
	}
	return invMatrix;
}



void matrix::matrixRank(int& d, int& c)
{
	if (d == _row - 1 || c == _column - 1) return;
	if (this->arr[d][c] != 0)
	{
		for (int i = d + 1; i < _row; i++)
		{
			float factor = this->arr[i][c] / this->arr[d][c];
			for (int j = 0; j < _column; j++)
			{
				this->arr[i][j] = this->arr[i][j] - this->arr[d][j] * factor;
			}
		}
		c++;
		d++;
		this->matrixRank(d, c);
	}
	else
	{
		for (int i = d + 1; i < _row; i++)
		{
			if (this->arr[i][c] != 0)
			{
				for (int j = 0; j < _column; j++)
				{
					swap(this->arr[i][j], this->arr[d][j]);
				}
				break;
			}
			else
			{
				c++;
				break;
			}
		}
		this->matrixRank(d, c);
	}
}

int matrix::matrixRankResult(int d, int c)
{
	matrixRank(d, c);
	int count = 0;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _column; j++)
		{
			if (this->arr[i][j] != 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}



string matrix::ToString() const
{
	stringstream writer;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _column; j++)
		{
			writer << "   " << arr[i][j] << "   ";
		}
		writer << endl;
	}
	return writer.str();
}

ostream& operator<<(ostream& writer, const matrix* matran)
{
	writer << matran->ToString();
	return writer;
}
