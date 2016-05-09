#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
char a[1000][1000] = {32};
int n;
void r(int n, int x, int y) {
 	if (n == 1) a[x][y]='X';
	else {
		int m=pow(3,n-2);
		r(n - 1, x, y);
		r(n - 1, x, y + 2*m);//
		r(n - 1, x + m, y + m);//
		r(n - 1, x + 2 * m, y);
		r(n - 1, x + 2 * m, y + 2 * m);//
	}
}
int main() {
	while (cin >> n, n > -1) {
		const int size = (int)pow(3, n - 1);
		/*
		a = new char*[size];
		for (int i = 0; i < size; i++)
			a[i] = new char[size];
			*/
		memset(a, 0, sizeof(a));
		r(n, 0, 0);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
					if(a[i][j]=='X') cout << a[i][j];
					else cout << ' ';
			}putchar('\n');
		}
		cout << '-' << endl;
	}
	//system("PAUSE");
	return 0;
}