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

//제가 코드를 짜 봤는데 ... 
//자꾸 에러가 뜨고 ... 이걸 보고 짰는데도 .... 자꾸 오류가 뜹니다 .....
//진짜 뭐가 문제인지 모르겠어서 일단 참고한 코드 먼저 올립니다 ...
//혹시 어떻게 이해했는지 내용도 필요하면 따로 올리겠습니다 ... 정말 죄송합니다 .......

