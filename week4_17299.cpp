#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int a[1000001];		//�Է� ���� �迭 
	int fre[1000001];		//�󵵼��� üũ�� �迭 
	int ngf[1000001];		//����ū�� 

	int N;
	cin >> N;		//�Է��� ������ ���� 

	for (int i = 0; i < N; i++) {		//���ڸ� �Է� ���� 
		cin >> a[i];	
		fre[a[i]]++;		//�ش� ������ �󵵼��� +1�� ���� 
	}

	stack<int> s;
	for (int j = N-1; j >= 0; j--) {		
		while (!s.empty() && fre[s.top()] <= fre[a[j]]) {		//������ ������� �ʰ�, ������ top�� �󵵼� ���� ���� ������ �󵵼��� �۰ų� ���� ��쿡 ��� �ݺ� -> �� ���� ��� ���� �ؾ��� 
			s.pop();		//pop
		}
		if (s.empty()) {		//���࿡ ������ ����ִٸ� 
			ngf[j] = -1;		//����ū���� -1�� ���� 
			s.push(a[j]);		//�ش� ���� ���ÿ� push �� 
		}
		else {		//������� ������ 
			ngf[j] = s.top();		//����ū���� ������ top������ ���� 
			s.push(a[j]);		//�ش� ���� ���ÿ� Ǫ�� 
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ngf[i] << ' ';		//��� 
	}

	return 0;
}