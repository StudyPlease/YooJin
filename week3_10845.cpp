#include <iostream>
#include <string>
using namespace std;


int front_index;		//맨 앞으로 고정함 
int rear_index;			//맨 뒤로 변경 가능함 , 마지막 원소 -> rear_index-1 에 있는 원소로 설정함 

void push(int value, int queue[]);
void pop(int queue[]);
void size(int queue[]);
void empty(int queue[]);
void front(int queue[]);
void back(int queue[]);


int main(void)
{
	int N;
	cin >> N;
	int* queue = new int[N];
	string command;

	for (int i = 0; i < N; i++){		//입력받은 명령어 수만큼 반복 
		cin >> command;
		if (command == "push") {
			int value;
			cin >> value;
			push(value, queue);
		}
		else if (command == "pop") {
			pop(queue);
		}
		else if (command == "size") {
			size(queue);
		}
		else if (command == "empty") {
			empty(queue);
		}
		else if (command == "front") {
			front(queue);
		}
		else if (command == "back") {
			back(queue);
		}
	}

	return 0;
}

void push(int value, int queue[])
{
	queue[rear_index++] = value;		//젤 뒤에 삽입후 rear_index 1 증가 
}

void pop(int queue[])
{
	if (rear_index == 0) {		//rear_index==0 -> 아무 값도 삽입되어있지 않다는 뜻 
		cout << "-1" << endl;
	}
	else {		//원소가 있으면 
		cout << queue[front_index] << endl;		//맨 앞 원소 출력 
		for (int i = 0; i < rear_index-1 ; i++) {		//한칸씩 앞으로 땡김 
			queue[i] = queue[i + 1];
		}
		queue[rear_index - 1] = NULL;		//맨뒤의 값 = NULL -> 한칸씩 당겼기 때문에 
		rear_index--;		//rear_index값 하나 감소 
	}
}

void size(int queue[])
{
	cout << rear_index << endl;		
}

void empty(int queue[])
{
	if (rear_index == 0) {		//원소 존재 하지 않음 
		cout << "1" << endl;
	}
	else {		//존재 함 
		cout << "0" << endl;
	}
}

void front(int queue[])
{
	if (queue[front_index] == NULL) {		//맨 앞 원소가 없으면 -> 큐가 비어있으면 
		cout << "-1" << endl;
	}
	else {
		cout << queue[front_index] << endl;		//있으면 그 값 출력 
	}
}

void back(int queue[])
{
	if (queue[front_index] == NULL) {//큐가 비어있으면 
		cout << "-1" << endl;
	}
	else {
		cout << queue[rear_index - 1] << endl;		//큐 안에 값이 존재하면 그 중 맨 뒤의 값 출력 , rear_index에는 원소 X -> rear_index-1이 마지막 원소임 
	}
}