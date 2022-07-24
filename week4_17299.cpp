#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int a[1000001];		//입력 받을 배열 
	int fre[1000001];		//빈도수를 체크할 배열 
	int ngf[1000001];		//오등큰수 

	int N;
	cin >> N;		//입력할 숫자의 개수 

	for (int i = 0; i < N; i++) {		//숫자를 입력 받음 
		cin >> a[i];	
		fre[a[i]]++;		//해당 숫자의 빈도수를 +1씩 해줌 
	}

	stack<int> s;
	for (int j = N-1; j >= 0; j--) {		
		while (!s.empty() && fre[s.top()] <= fre[a[j]]) {		//스택이 비어있지 않고, 스택의 top의 빈도수 보다 현재 숫자의 빈도수가 작거나 같을 경우에 계속 반복 -> 두 조건 모두 만족 해야함 
			s.pop();		//pop
		}
		if (s.empty()) {		//만약에 스택이 비어있다면 
			ngf[j] = -1;		//오등큰수를 -1로 해줌 
			s.push(a[j]);		//해당 수를 스택에 push 함 
		}
		else {		//비어있지 않으면 
			ngf[j] = s.top();		//오등큰수를 스택의 top값으로 설정 
			s.push(a[j]);		//해당 수를 스택에 푸시 
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ngf[i] << ' ';		//출력 
	}

	return 0;
}