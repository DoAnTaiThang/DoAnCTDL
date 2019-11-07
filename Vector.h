#pragma once
#include<iostream>
#define max 50
using namespace std;
class Vector
{
private:
	float v[max];
	int n;
public:
	Vector();
	void Nhap();
	void Xuat();
	Vector Add(Vector b);
	Vector Multiplied(float a);
};
