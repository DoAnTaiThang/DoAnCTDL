#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class matrix
{
	int _row;
	int _column;
	float** arr = new float* [_row];
public:
	int hang() { return _row; }
	int cot() { return _column; }

	matrix() {
		_row = 3;
		_column = 3;
		this->arr = new float* [_row];
	}
public:
	matrix* inverseMaxtrix();
	string ToString() const;
	friend void nghichdao(matrix* matran, int d);
	void matrixRank(int& d, int& c);
	int matrixRankResult(int d, int c);
public:
	friend istream& operator>>(istream& in, matrix* matran);
	friend ostream& operator<<(ostream& out, const matrix* matran);
};
