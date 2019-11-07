#include"Bool.h"
int** d1, ** d2, x, y, ** d;
void create(int x, int y)
{
	int i, j, a;
	for (i = 0; i < y; i++) {
		cout << endl;
		cout << "Nhap hoi so cap thu " << i << "(nhap dang nhi phan cua tung bien): " << endl;
		for (j = 0; j < x; j++)
		{
			cin >> d[i][j];
			d1[i][j] = d[i][j];
		}
		d[i][x] = d1[i][x] = 8;
	}
}



int staging(int x, int y)// bat dau thuc hien cac phep dan
{
	int i1, j1, k1, t1, i2, j2, t2, c; i2 = 0; c = 0;
	for (i1 = 0; i1 < (y - 1); i1++) {
		for (j1 = i1 + 1; j1 < y; j1++) {
			t1 = 0;
			for (k1 = 0; k1 < x; k1++) {
				if (d1[i1][k1] != d1[j1][k1]) {
					t1++;
					t2 = k1;
				}
			}
			if (t1 == 1) {
				for (j2 = 0; j2 < t2; j2++)
					d2[i2][j2] = d1[i1][j2];
				d2[i2][t2] = 3;
				for (j2 = t2 + 1; j2 < y; j2++)
					d2[i2][j2] = d1[i1][j2];
				d2[i2][x] = 8;
				d1[i1][x] = 9;
				d1[j1][x] = 9;
				i2++;
			}
		}
	}
	for (i1 = 0; i1 < y; i1++) {
		if (d1[i1][x] == 8) {
			for (j1 = 0; j1 <= x; j1++)
				d2[i2][j1] = d1[i1][j1];
			i2++;
		}
	}
	for (j1 = 0; j1 < x; j1++) {
		if (d1[0][j1] == d2[0][j1]) c++;
	}
	if (c < x) {
		d1 = (int**)malloc(i2 * sizeof(int*));
		for (i1 = 0; i1 < i2; i1++) d1[i1] = (int*)malloc((x + 1) * sizeof(int));
		for (i1 = 0; i1 < i2; i1++) {
			for (j1 = 0; j1 <= x; j1++) d1[i1][j1] = d2[i1][j1];// tra ket qua ve bang d1
		}
		staging(x, i2);
	}
	else return(i2);
}

int duplication(int x, int y)// kiem tra o bang cuoi ket qua nao bi trung
{
	int i1, i2, j, c, t; t = 0;
	for (i1 = 0; i1 < (y - 1); i1++) {
		for (i2 = i1 + 1; i2 < y; i2++) {
			c = 0;
			for (j = 0; j < x; j++) {
				if (d1[i1][j] == d1[i2][j]) c++;
			}
			if (c == x) d1[i2][x] = 9;
		}
	}
	for (i1 = 0; i1 < y; i1++) {
		if (d1[i1][x] == 9) t++;
	}
	i2 = y - t;
	d2 = (int**)malloc(i2 * sizeof(int*));
	for (j = 0; j < i2; j++) d2[j] = (int*)malloc((x + 1) * sizeof(int));
	i2 = 0;
	for (i1 = 0; i1 < y; i1++)// loai bo cac hoi bi trung, chep ket qua sau khi loai sang bang d2 lai
		if (d1[i1][x] == 8) {
			for (j = 0; j <= x; j++) d2[i2][j] = d1[i1][j];
			i2++;
		}
	return(i2);
}




void decode(int x, int y3)
{
	for (int m = 0; m < y3; m++)
	{
		for (int n = 0; n < x; n++)
		{
			if (d2[m][n] == 0)
			{
				cout << "a[" << n << "]'";
			}
			if (d2[m][n] == 1)
			{
				cout << "a[" << n << "]";
			}
		}
		cout << " v ";
	}
}