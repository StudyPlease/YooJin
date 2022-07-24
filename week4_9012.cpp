#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string par_str);

int main(void)
{
	int T;		//�Է��� ���ڿ��� ���� 
	string par_str;		//�Է� ���� ���ڿ� 
	cin >> T;
	cin.ignore();
	
	for (int i = 0; i < T; i++) {		//�Է��� ���ڿ��� ������ŭ �ݺ� 
		cin >> par_str;		//��ȣ�� �̷���� ���ڿ� �Է� 
		if (check(par_str)) {		//VPS�� �´��� Ȯ���� 
			cout << "YES" << endl;		//������ ���� ��� 
		}
		else {		//�ƴϸ� �� ��� 
			cout << "NO" << endl;
		}
	}

	return 0;
}

bool check(string par_str)
{
	int str_len = par_str.size();		//���ڿ��� ���� ��� 
	stack<char> str;		//���� 

	for (int i = 0; i < str_len; i++) {		//���ڿ��� ���� ��ŭ �ݺ� 
		char par = par_str[i];		//par�� ���ڿ��� ó������ ���� 

		if (par == '(') {		//���࿡ par�� ���� ��ȣ�� 
			str.push(par);		//���ÿ� ���� 
		}
		else {		//������ȣ�� �ƴ� �� 
			if (!str.empty()) {		//������ ������� ������ 
				str.pop();		//pop 
			}
			else {
				return false;		//���࿡ ������ȣ�� �ƴϰ� ������ ��������� false 
			}
		}
	}
	return str.empty();		//�ݺ����� ������ ���ÿ� ��ȣ�� �����־ false 	
}