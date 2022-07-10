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
	cin >> N;		//명령어 개수 입력 받음 
	cin.ignore();
	for (int i = 0; i < N; i++) {		//맨처음 입력한 명령어 개수만큼 반복 
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string command;
		cin >> command;		//명령어 입력 

		//명령어 입력시 
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

void push_front(int value)		//앞에 삽입 
{
	deque[front_index--] = value;		//맨앞에 넣고 인덱스 하나 -함 
	total_index++;		//총 사이즈 1증가 
	if (front_index < 0) {		//하한 초과 -> 상한 
		front_index = 10000;
	}
}

void push_back(int value)		//뒤에 삽입 
{
	back_index++;		//먼저 1 증가 시킴 
	total_index++;		//총 크기 1 증가 
	if (back_index > 10000) {		//하한 초과 -> 상한 
		back_index = 0;
	}
	deque[back_index] = value;		//하한 초과하는 지 먼저 검사하고 값을 집어넣음 
}

void pop_front(void)		//앞에 값 출력 , pop 
{
	if (empty() == 1) {		//비어있으면 
		cout << "-1" << endl;		//-1 출력 
	}
	else {
		front_index++;		//먼저 + 하고 
		total_index--;		//총 크기 1 감소 
		if (front_index > 10000) {		//검사 
			front_index = 0;
		}
		cout << deque[front_index] << endl;		//검사 후에 출력 
	}


}

void pop_back(void)		//뒤에 값 출력 , pop 
{
	if (empty() == 1) {
		cout << "-1" << endl;
	}
	else {
		int temp = deque[back_index--];		//값 저장해놓은 후 -함 
		total_index--;		//총 크기 1감소 
		if (back_index < 0) {
			back_index = 10000;
		}
		cout << temp << endl;
	}
}

void size(void)		//덱의 크기 -> 들어있는 정수 개수 출력 
{
	cout << total_index << endl;
}

int empty(void)
{
	if (total_index == 0) {		//비어있는지 유무 
		return 1;
	}
	else {
		return 0;
	}
}

int front(void)		//맨 앞의 값 출력 
{
	if (empty() == 1) {		//비어있으면 -1 출력 
		cout << "-1" << endl;
	}
	else {
		if (front_index + 1 > 10000) {		//하한 초과 시 -> 0의 값 출력 
			cout << deque[0] << endl;
			return 0;
		}
		cout << deque[front_index + 1] << endl;		//초과 안하면 그대로 출력 
	}
	return 0;
}
	
void back(void)		//맨 뒤에 값 출력 
{
	if (empty() == 1) {		//비어있으면 -1 출력 
		cout << "-1" << endl;
	}
	else {
		cout << deque[back_index] << endl;		//값이 있으면 출력 
	}
}
