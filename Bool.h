#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 


using namespace std;

extern int** d1, ** d2, x, y, ** d;

void create(int x, int y);// nhap input
int staging(int x, int y);// bat dau thuc hien phuong phap Quine-McCluskey
int duplication(int x, int y);// loai bo cac dong bi trung
void decode(int x, int y3);// in ra man hinh ket qua