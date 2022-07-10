#include<iostream> 
#include<string>
using namespace std;

int main(void)
{
	string str;
	int T;
	cin >> T; 
	getline(cin, str);
	for (T; T > 0; T--) {		//T의 수만큼 반복한다 
		getline(cin, str);		//문장 입력 
		int ind = -1;		
		int str_len = str.size();		//문장의 길이 
		for (int i = 0; i < str_len; i++) {		//문장의 길이만큼 반복 
			if (str[i] == ' ') {		//공백 발견 
				for (int index = i - 1; index > ind; index--) {		//현재 공백의 인덱스 -1 ~ 바로 전에 나온 공백의 인덱스 + 1까지 역순으로 출력 
					cout << str[index];
				}
				cout << " ";		//공백 
				ind = i;		//다음 단어 시작 인덱스 번호 리셋 
			}
			else if (i == str_len - 1) {		//공백이 없는 문장 
				for (int index = i; index > ind; index--) {
					cout << str[index];		//뒤에서부터 그냥 출력 
				}
			}
		}
		cout << endl;
	}
	return 0;
}