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

	if (a < b) {		//a가 항상 더 커야함 만약 b가 더 크면 둘이 숫자를 바꿈 
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

int find_GCD(int a, int b)		//최대 공약수 
{
	for (int i = a; i > 0; i--) {		//a에서부터 내려오면서 찾음 (최대 공약수이기 때문에 위에서 찾는게 좋을 듯)
		if (a % i == 0 && b % i == 0) {		//둘이 공통 적으로 나머지 없이 나눠지는 i를 찾음 
			return i;		//그게 최대 공약수 
		}
	}
}

int find_LCM(int a, int b)		//최소 공배수 
{
	int LCM;
	int c = b;		//c를 둘 중 작은 값으로 선택 
	while (1) {		//최소 공배수를 찾을 때 까지 반복-> break 만남 
		if (c % b == 0 && c % a == 0) {		//c를 a와 b로 나누었을 때 둘 다 나머지가 0 -> 공배수라는 뜻 
			LCM = c;		//그런 수가 있다면 저장 
			break;		//반복문 탈출 
		}
		c++;		//없다면 c의 값을 늘려 계속 찾음 
	}

	return LCM;
}