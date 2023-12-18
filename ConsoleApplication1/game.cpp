#include<iostream>
#include"thuvien.h"
using namespace std;
int sl = 5;
#define MAX 100
void khoi_tao_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void them(int a[], int x);
void xoa(int a[], int vt);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void xuly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua);
bool kt_rancan(int toadox[], int toadoy[]);
bool kt_ran(int x0, int y0);
bool ktr_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran12(int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
void ve_tuong_tren() {
	int x = 10, y = 1;
	while (x < 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_duoi() {
	int x = 10, y = 26;
	while (x < 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_phai() {
	int x = 100, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong_trai() {
	int x = 10, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong() {
	SetColor(5);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	SetColor(7);
}
void khoi_tao_ran(int toadox[], int toadoy[]) {
	int x = 50, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[]) {
	for (int i = 0; i < sl; i++) {
		int y = rand() % (15) + 1;
		SetColor(y);
		gotoXY(toadox[i], toadoy[i]);

		if (i == 0)cout << "0";
		else cout << "o";
	}
}
void them(int a[], int x) {
	for (int i = sl; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt) {
	for (int i = vt; i < sl; i++) {
		a[i] = a[i + 1];
	}
	sl--;
}
void xoa_du_lieu_cu(int toadox[], int toadoy[]) {
	for (int i = 0; i < sl; i++) {
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}

}
void xuly_ran(int toadox[], int toadoy[], int x, int y,int &xqua,int &yqua) {
	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(xqua,yqua,toadox[0],toadoy[0])==false) {
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);

	}
	else {
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	
	ve_ran(toadox, toadoy);
	
}
bool kt_ran_tuong(int x0, int y0) {
	if (y0 == 1 && (x0 >= 10 && x0 <= 100)) {
		return true;
	}
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26)) {
		return true;
	}
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26)) {
		return true;
	}
	return false;
}
bool kt_rancan(int toadox[], int toadoy[]) {
	for (int i = 1; i < sl; i++) {
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i])) {
			return true;
		}
	}
	return false;
}
bool kt_ran12(int toadox[], int toadoy[]) {
	
	bool kt2  = kt_rancan(toadox, toadoy);
	bool kt1 = kt_ran_tuong(toadox[0], toadoy[0]);
	if (kt1 == true || kt2 == true)
		return true;
	return false;
}
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]) {
	
	do {
		xqua = rand() % (99 - 11 + 1) + 11;
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (ktr_ran_de_qua(xqua, yqua, toadox, toadoy)==true);
	int i = rand() % (15) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "@"; SetColor(7);
}
bool ktr_ran_de_qua(int xqua,int yqua, int toadox[], int toadoy[]) {
	for (int i = 0; i < sl; i++) {
		if (xqua == toadox[i] && yqua == toadoy[i])
			return true;
	}
	return false;
}
bool kt_ran_an_qua(int xqua,int yqua,int x0,int y0) {
	if ((x0 == xqua) && (y0 == yqua)) {
		return true;
	}
	return false;
}

void main() {
	
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while (gameover == false)
	{
		//system("cls");
		xoa_du_lieu_cu(toadox, toadoy);
		
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72 && check !=0) {
					check = 1;
				}
				else if (kitu == 80&&check !=1) {
					check = 0;
				}
				else if (kitu == 77&&check!=3) {
					check = 2;
				}
				else if (kitu == 75 && check != 2) {
					check = 3;
				}
			}
		}
		if (check == 0) {
			y++;
		}
		else if (check == 1) {
			y--;
		}
		else if (check == 2) {
			x++;

		}
		else if (check == 3) {
			x--;
		}
		
		xuly_ran(toadox, toadoy, x, y,xqua,yqua);
		gameover = kt_ran12(toadox, toadoy);
	
		
		
		Sleep(150);
	}
	
	_getch();
	
}