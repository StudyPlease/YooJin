#include<iostream> 
#include<string>
using namespace std;

int main(void)
{
	string str;
	int T;
	cin >> T; 
	getline(cin, str);
	for (T; T > 0; T--) {		//T�� ����ŭ �ݺ��Ѵ� 
		getline(cin, str);		//���� �Է� 
		int ind = -1;		
		int str_len = str.size();		//������ ���� 
		for (int i = 0; i < str_len; i++) {		//������ ���̸�ŭ �ݺ� 
			if (str[i] == ' ') {		//���� �߰� 
				for (int index = i - 1; index > ind; index--) {		//���� ������ �ε��� -1 ~ �ٷ� ���� ���� ������ �ε��� + 1���� �������� ��� 
					cout << str[index];
				}
				cout << " ";		//���� 
				ind = i;		//���� �ܾ� ���� �ε��� ��ȣ ���� 
			}
			else if (i == str_len - 1) {		//������ ���� ���� 
				for (int index = i; index > ind; index--) {
					cout << str[index];		//�ڿ������� �׳� ��� 
				}
			}
		}
		cout << endl;
	}
	return 0;
}