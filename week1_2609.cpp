#include <iostream>
#include <string>
using namespace std;

int find_GCD(int a, int b);
int find_LCM(int a, int b);

int main(void)
{
	int a = 0, b = 0;
	int GCD = 0, LCM = 0;
	cin >> a >> b;

	if (a < b) {		//a�� �׻� �� Ŀ���� ���� b�� �� ũ�� ���� ���ڸ� �ٲ� 
		int temp = a;
		a = b;
		b = temp;
	}

	GCD = find_GCD(a, b);
	LCM = find_LCM(a, b);

	cout << GCD << endl;
	cout << LCM << endl;

	return 0;
}

int find_GCD(int a, int b)		//�ִ� ����� 
{
	for (int i = a; i > 0; i--) {		//a�������� �������鼭 ã�� (�ִ� ������̱� ������ ������ ã�°� ���� ��)
		if (a % i == 0 && b % i == 0) {		//���� ���� ������ ������ ���� �������� i�� ã�� 
			return i;		//�װ� �ִ� ����� 
		}
	}
}

int find_LCM(int a, int b)		//�ּ� ����� 
{
	int LCM;
	int c = b;		//c�� �� �� ���� ������ ���� 
	while (1) {		//�ּ� ������� ã�� �� ���� �ݺ�-> break ���� 
		if (c % b == 0 && c % a == 0) {		//c�� a�� b�� �������� �� �� �� �������� 0 -> �������� �� 
			LCM = c;		//�׷� ���� �ִٸ� ���� 
			break;		//�ݺ��� Ż�� 
		}
		c++;		//���ٸ� c�� ���� �÷� ��� ã�� 
	}

	return LCM;
}