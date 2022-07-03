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
	int* stack;		//스택 
	int N = 0;
	int value = 0;
	cin >> N;		//명령어 개수 
	stack = new int[N];		//스택 동적 할당 
	string cmd;		//명령어 입력받을 변수 

	for (int i = 0; i < N; i++) {		//명령어 수만큼 반복 
		cin >> cmd;		//명령어 입력 받음 
		if (cmd == "push") {		//푸쉬 
			cin >> value;		//할 값 받아서 
			push(value, stack);		//함수 호출 
		}
		else if (cmd == "pop") {		//팝 
			int pop_num = pop(stack);		//pop한 변수 받아서 
			cout << pop_num << endl;		//출력 
		}
		else if (cmd == "size") {		//스택에 정수가 차있는 크기 출력 
			size();
		}
		else if (cmd == "empty") {		//스택이 비어있는지 확인 
			empty();
		}
		else if (cmd == "top") {		//제일 위에 있는 정수 출력 
			top(stack);
		}
	}

	delete []stack;		//메모리 해제 

	return 0;
}

void push(int a, int stack[])
{
	stack[++top_num] = a;		//++top해주고 그 인덱스의 스택에 값 삽입 
}

int pop(int stack[])
{
	if (top_num != -1) {		//스택 비어있지 않으면 
		return stack[top_num--];		//맨 위에 있는값 리턴하고 top 1감소 
	}
	else {
		return -1;		//스택 비어있으면 -1  출력 
	}
}

void size(void)
{
	cout << top_num + 1 << endl;		//top+1 -> 정수가 차있는 개수 ex) top_num=0 -> stack[0]만 차있음 -> 1개의 정수만 스택에 존재 
}

void empty(void)
{
	if (top_num == -1) {		//top이 -1 즉 비어있으면 
		cout << "1" << endl;		//1출력 
	}	
	else {		//top != -1 즉 스택에 정수가 존재하면 
		cout << "0" << endl;		//0출력 
	}
}

void top(int stack[])
{
	if (top_num != -1) {		//스택이 비어있지 않으면 
		cout << stack[top_num] << endl;		//스택 맨 위의 값 출력 
	}
	else {		//스택이 비어있으면 
		cout << "-1" << endl;		//-1 출력 
	}
}