#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string par_str);

int main(void)
{
	int T;		//입력할 문자열의 개수 
	string par_str;		//입력 받을 문자열 
	cin >> T;
	cin.ignore();
	
	for (int i = 0; i < T; i++) {		//입력할 문자열의 개수만큼 반복 
		cin >> par_str;		//괄호로 이루어진 문자열 입력 
		if (check(par_str)) {		//VPS가 맞는지 확인함 
			cout << "YES" << endl;		//맞으면 예스 출력 
		}
		else {		//아니면 노 출력 
			cout << "NO" << endl;
		}
	}

	return 0;
}

bool check(string par_str)
{
	int str_len = par_str.size();		//문자열의 길이 계산 
	stack<char> str;		//스택 

	for (int i = 0; i < str_len; i++) {		//문자열의 길이 만큼 반복 
		char par = par_str[i];		//par에 문자열의 처음부터 넣음 

		if (par == '(') {		//만약에 par가 열린 괄호면 
			str.push(par);		//스택에 넣음 
		}
		else {		//열린괄호가 아닐 때 
			if (!str.empty()) {		//스택이 비어있지 않으면 
				str.pop();		//pop 
			}
			else {
				return false;		//만약에 열린괄호도 아니고 스택이 비어있으면 false 
			}
		}
	}
	return str.empty();		//반복문이 끝나고 스택에 괄호가 남아있어도 false 	
}