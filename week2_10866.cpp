#include <iostream>
#include <string>
using namespace std;

int front_index;
int back_index;
int total_index;
int N;
int deque[10001];

void push_front(int value);
void push_back(int value);
void pop_front(void);
void pop_back(void);
void size(void);
int empty(void);
int front(void);
void back(void);

int main(void)
{
	cin >> N;		//��ɾ� ���� �Է� ���� 
	cin.ignore();
	for (int i = 0; i < N; i++) {		//��ó�� �Է��� ��ɾ� ������ŭ �ݺ� 
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string command;
		cin >> command;		//��ɾ� �Է� 

		//��ɾ� �Է½� 
		if (command == "push_front") {
			int value;
			cin >> value;
			push_front(value);
		}
		else if (command == "push_back") {
			int value;
			cin >> value;
			push_back(value);
		}
		else if (command == "pop_front") {
			pop_front();
		}
		else if (command == "pop_back") {
			pop_back();
		}
		else if (command == "size") {
			size();
		}
		else if (command == "empty") {
			if (empty() == 1) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (command == "front") {
			front();
		}
		else if (command == "back") {
			back();
		}
	}

	return 0;
}

void push_front(int value)		//�տ� ���� 
{
	deque[front_index--] = value;		//�Ǿտ� �ְ� �ε��� �ϳ� -�� 
	total_index++;		//�� ������ 1���� 
	if (front_index < 0) {		//���� �ʰ� -> ���� 
		front_index = 10000;
	}
}

void push_back(int value)		//�ڿ� ���� 
{
	back_index++;		//���� 1 ���� ��Ŵ 
	total_index++;		//�� ũ�� 1 ���� 
	if (back_index > 10000) {		//���� �ʰ� -> ���� 
		back_index = 0;
	}
	deque[back_index] = value;		//���� �ʰ��ϴ� �� ���� �˻��ϰ� ���� ������� 
}

void pop_front(void)		//�տ� �� ��� , pop 
{
	if (empty() == 1) {		//��������� 
		cout << "-1" << endl;		//-1 ��� 
	}
	else {
		front_index++;		//���� + �ϰ� 
		total_index--;		//�� ũ�� 1 ���� 
		if (front_index > 10000) {		//�˻� 
			front_index = 0;
		}
		cout << deque[front_index] << endl;		//�˻� �Ŀ� ��� 
	}


}

void pop_back(void)		//�ڿ� �� ��� , pop 
{
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		int temp = deque[back_index--];		//�� �����س��� �� -�� 
		total_index--;		//�� ũ�� 1���� 
		if (back_index < 0) {
			back_index = 10000;
		}
		cout << temp << endl;
	}
}

void size(void)		//���� ũ�� -> ����ִ� ���� ���� ��� 
{
	cout << total_index << endl;
}

int empty(void)
{
	if (total_index == 0) {		//����ִ��� ���� 
		return 1;
	}
	else {
		return 0;
	}
}

int front(void)		//�� ���� �� ��� 
{
	if (empty() == 1) {		//��������� -1 ��� 
		cout << "-1" << endl;
	}
	else {
		if (front_index + 1 > 10000) {		//���� �ʰ� �� -> 0�� �� ��� 
			cout << deque[0] << endl;
			return 0;
		}
		cout << deque[front_index + 1] << endl;		//�ʰ� ���ϸ� �״�� ��� 
	}
	return 0;
}
	
void back(void)		//�� �ڿ� �� ��� 
{
	if (empty() == 1) {		//��������� -1 ��� 
		cout << "-1" << endl;
	}
	else {
		cout << deque[back_index] << endl;		//���� ������ ��� 
	}
}
