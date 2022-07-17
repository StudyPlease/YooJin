#include <iostream>

using namespace std;

int is_prime[1000001];
int prime_num[1000001];
int tem, a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= 1000000; i++) {		
		if (!is_prime[i]) {
			prime_num[tem++] = i;
			for (int j = i * 2; j <= 1000000; j += i) {
				is_prime[j] = 1;
			}
		}
	}

	while (true) {
		cin >> a;
		if (a == 0)
			break;
		for (int i = 1; i < 1000001; i++) {
			if (!is_prime[a - prime_num[i]]) {
				cout << a << " = " << prime_num[i] << " + " << a - prime_num[i] << "\n";
				break;
			}
		}
	}
}

//���� �ڵ带 ¥ �ôµ� ... 
//�ڲ� ������ �߰� ... �̰� ���� ®�µ��� .... �ڲ� ������ ��ϴ� .....
//��¥ ���� �������� �𸣰ھ �ϴ� ������ �ڵ� ���� �ø��ϴ� ...
//Ȥ�� ��� �����ߴ��� ���뵵 �ʿ��ϸ� ���� �ø��ڽ��ϴ� ... ���� �˼��մϴ� .......

