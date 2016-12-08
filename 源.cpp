
//			ע�⣡��
//			��������ѡ����Ϊ2^n���������ѡ��Ϊ2n������
//			�������Ƶ�2n�����
#include<iostream>

using namespace std;

const int maxSize = 10;

int table[maxSize][maxSize] = { 0 };

void merge(int size);
//�ݹ鴴�������2^n����2^n-1
void createTable(int size) {
	if (size == 1) {
		table[1][1] = 1;
		return;
	}
	createTable(size / 2);
	//�ںϺ���������2^n-1�Ƶ���2^n�ı��
	merge(size);
}

void merge(int size) {
		int mid = size / 2;
		for (int i = 1; i <= mid; i++)
		for (int j = 1; j <= mid; j++) {
			//���������Ƶ�
			table[i][j + mid] = table[i][j] + mid;
			//����ѡ���Ƶ�
			table[i + mid][j] = table[i][j + mid];
			//�Խ��Ƶ�
			table[i + mid][j + mid] = table[i][j];
		}
	
}
//���
void print(int size) {
	cout << "      ";
	for (int i = 1; i < size; i++)
		cout << " "<< i << "day" ;
	cout << endl;
	for (int i = 1; i <= size; i++) {
		cout << "ѡ��" << i<<"    ";
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
