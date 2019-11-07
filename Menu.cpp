#include"Menu.h"
#include"HePhuongTrinh.h"
#include"Matrix.h"
#include"Multiply.h"
#include"DinhThuc.h"
#include"Vector.h"
#include"Bool.h"
void Menu()
{
	string space = "                      ";
	cout << space << " ___________________________________________________________" << endl;
	cout << space << "| STT |                  CHUC NANG                          |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  1  | Tim tat cac cac cong thuc toi tieu cua ham Bool     |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  2  | Phep toan cong hai vector                           |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  3  | Phep toan nhan vector voi 1 so alpha                |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  4  | Tim dinh thuc cua ma tran                           |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  5  | Nghich dao ma tran                                  |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  6  | Tinh tich cua hai ma tran                           |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  7  | Tim hang cua ma tran                                |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  8  | He phuong trinh tuyen tinh                          |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	cout << space << "|  9  | Thoat chuong trinh                                  |" << endl;
	cout << space << "|_____|_____________________________________________________|" << endl;
	int choice;
	do
	{
		cout << "\nYour choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int i, j, y1, y2, y3, a, q;
			printf("\n Nhap so bien: ");
			cin >> x;
			printf("\n Nhap so hoi so cap: ");
			cin >> y;
			d = d1 = (int**)malloc(y * sizeof(int*));// d la bang goc, d1 la bang dung de thao tac
			for (i = 0; i < y; i++) d[i] = d1[i] = (int*)malloc((x + 1) * sizeof(int));// them 1 cot de danh dau
			create(x, y);
			y1 = y * (y + 1) / 2;
			d2 = (int**)malloc(y1 * sizeof(int*));// d2 la bang luu cac hoi so cap da duoc gian trong qua trinh chay, va luu ket qua thu gon cuoi cung khi chay xong
			for (i = 0; i < y1; i++) d2[i] = (int*)malloc((x + 1) * sizeof(int));// them 1 cot de danh dau
			y2 = staging(x, y);
			y3 = duplication(x, y2);
			printf("\n\nCong thuc da thuc toi thieu:\n\n");
			decode(x, y3);
			break;
		}
		case 2:
		{
			Vector a, b, d;
			cout << "\nEnter the first vector: " << endl;
			a.Nhap();
			cout << "\nThe entered vector: " << endl;
			a.Xuat();
			cout << "\nEnter the second vector: " << endl;
			b.Nhap();
			cout << "\nThe entered vector: " << endl;
			b.Xuat();
			d = a.Add(b);
			cout << "The sum of 2 vectors is: ";
			d.Xuat();
			break;
		}
		case 3:
		{
			Vector e;
			int alpha;
			cout << "\nEnter a vector: " << endl;
			e.Nhap();
			cout << "\nEnter a number: ";
			cin >> alpha;
			e = e.Multiplied(alpha);
			cout << "The result of multiplication of the matrix with " << alpha << " is" << endl;
			e.Xuat();
			break;
		}
		case 4:
		{
			int n;
			int matrix[10][10];
			Input(matrix, n);
			Output(matrix, n);
			cout << "Determinant of the matrix is: " << determinant(matrix, n);
			break;
		}
		case 5:
		{
			matrix* a = new matrix;
			cout << "\nEnter a matrix: " << endl;
			cin >> a;
			cout << "\nThe entered matrix is: " << endl;
			cout << a;
			matrix* b = new matrix;
			b = a->inverseMaxtrix();
			cout << "\nInverse matrix: " << endl;
			cout << b << endl;
			break;
		}
		case 6:
		{
			int a[10][10], b[10][10], r1, c1, r2, c2;
			MatrixMultiplication(a, b, r1, c1, r2, c2);
			break;
		}
		case 7:
		{
			matrix* a = new matrix;
			cout << "\nEnter a matrix: ";
			cin >> a;
			cout << "The entered matrix is:" << endl;
			cout << a;
			int c = 0;
			int d = 0;
			int count = a->matrixRankResult(d, c);
			cout << "\nRank of the entered matrix: ";
			cout << count;
			break;
		}
		case 8:
		{
			Matrix a;
			a.Nhap();
			a.Xuat();
			a.EchelonCompactMatrix(0);
			a.SystemOfLinearEquations();
			break;
		}
		case 9:
		{
			break;
		}
		}
	} while (choice != 9);
}