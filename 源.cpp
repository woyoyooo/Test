
//			注意！！
//			仅适用于选手数为2^n的情况，但选手为2n不适用
//			可自行推导2n的情况
#include<iostream>

using namespace std;

const int maxSize = 10;

int table[maxSize][maxSize] = { 0 };

void merge(int size);
//递归创建表格，由2^n减至2^n-1
void createTable(int size) {
	if (size == 1) {
		table[1][1] = 1;
		return;
	}
	createTable(size / 2);
	//融合函数，根据2^n-1推导出2^n的表格
	merge(size);
}

void merge(int size) {
		int mid = size / 2;
		for (int i = 1; i <= mid; i++)
		for (int j = 1; j <= mid; j++) {
			//横向天数推导
			table[i][j + mid] = table[i][j] + mid;
			//纵向选手推导
			table[i + mid][j] = table[i][j + mid];
			//对角推导
			table[i + mid][j + mid] = table[i][j];
		}
	
}
//输出
void print(int size) {
	cout << "      ";
	for (int i = 1; i < size; i++)
		cout << " "<< i << "day" ;
	cout << endl;
	for (int i = 1; i <= size; i++) {
		cout << "选手" << i<<"    ";
		for (int j = 2; j <= size; j++)
			cout << table[i][j] << "    ";
		cout << endl;
	}
}
int main() {
	int n;
	cin >> n;
	createTable(n);
	print(n);
	return 0;
}
