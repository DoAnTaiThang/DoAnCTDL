#pragma once
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class Matrix
{
private:
	int _matrix[100][100];
	int _col;
	int _row;
public:
	void EchelonCompactMatrix(int);
	int Rank();
	void SystemOfLinearEquations();
	void Nhap();
	void Xuat();
};
int max(int a, int b);
