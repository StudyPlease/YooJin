#include <iostream>
#include <string>
using namespace std;

void push(int a, int stack[]);
int pop(int stack[]);
void size(void);
void empty(void);
void top(int stack[]);

int top_num = -1;

int main(void)
{
	int* stack;		//���� 
	int N = 0;
	int value = 0;
	cin >> N;		//��ɾ� ���� 
	stack = new int[N];		//���� ���� �Ҵ� 
	string cmd;		//��ɾ� �Է¹��� ���� 

	for (int i = 0; i < N; i++) {		//��ɾ� ����ŭ �ݺ� 
		cin >> cmd;		//��ɾ� �Է� ���� 
		if (cmd == "push") {		//Ǫ�� 
			cin >> value;		//�� �� �޾Ƽ� 
			push(value, stack);		//�Լ� ȣ�� 
		}
		else if (cmd == "pop") {		//�� 
			int pop_num = pop(stack);		//pop�� ���� �޾Ƽ� 
			cout << pop_num << endl;		//��� 
		}
		else if (cmd == "size") {		//���ÿ� ������ ���ִ� ũ�� ��� 
			size();
		}
		else if (cmd == "empty") {		//������ ����ִ��� Ȯ�� 
			empty();
		}
		else if (cmd == "top") {		//���� ���� �ִ� ���� ��� 
			top(stack);
		}
	}

	delete []stack;		//�޸� ���� 

	return 0;
}

void push(int a, int stack[])
{
	stack[++top_num] = a;		//++top���ְ� �� �ε����� ���ÿ� �� ���� 
}

int pop(int stack[])
{
	if (top_num != -1) {		//���� ������� ������ 
		return stack[top_num--];		//�� ���� �ִ°� �����ϰ� top 1���� 
	}
	else {
		return -1;		//���� ��������� -1  ��� 
	}
}

void size(void)
{
	cout << top_num + 1 << endl;		//top+1 -> ������ ���ִ� ���� ex) top_num=0 -> stack[0]�� ������ -> 1���� ������ ���ÿ� ���� 
}

void empty(void)
{
	if (top_num == -1) {		//top�� -1 �� ��������� 
		cout << "1" << endl;		//1��� 
	}	
	else {		//top != -1 �� ���ÿ� ������ �����ϸ� 
		cout << "0" << endl;		//0��� 
	}
}

void top(int stack[])
{
	if (top_num != -1) {		//������ ������� ������ 
		cout << stack[top_num] << endl;		//���� �� ���� �� ��� 
	}
	else {		//������ ��������� 
		cout << "-1" << endl;		//-1 ��� 
	}
}