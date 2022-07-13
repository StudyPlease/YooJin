#include <iostream>
#include <string>
using namespace std;


int front_index;		//�� ������ ������ 
int rear_index;			//�� �ڷ� ���� ������ , ������ ���� -> rear_index-1 �� �ִ� ���ҷ� ������ 

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

	for (int i = 0; i < N; i++){		//�Է¹��� ��ɾ� ����ŭ �ݺ� 
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
	queue[rear_index++] = value;		//�� �ڿ� ������ rear_index 1 ���� 
}

void pop(int queue[])
{
	if (rear_index == 0) {		//rear_index==0 -> �ƹ� ���� ���ԵǾ����� �ʴٴ� �� 
		cout << "-1" << endl;
	}
	else {		//���Ұ� ������ 
		cout << queue[front_index] << endl;		//�� �� ���� ��� 
		for (int i = 0; i < rear_index-1 ; i++) {		//��ĭ�� ������ ���� 
			queue[i] = queue[i + 1];
		}
		queue[rear_index - 1] = NULL;		//�ǵ��� �� = NULL -> ��ĭ�� ���� ������ 
		rear_index--;		//rear_index�� �ϳ� ���� 
	}
}

void size(int queue[])
{
	cout << rear_index << endl;		
}

void empty(int queue[])
{
	if (rear_index == 0) {		//���� ���� ���� ���� 
		cout << "1" << endl;
	}
	else {		//���� �� 
		cout << "0" << endl;
	}
}

void front(int queue[])
{
	if (queue[front_index] == NULL) {		//�� �� ���Ұ� ������ -> ť�� ��������� 
		cout << "-1" << endl;
	}
	else {
		cout << queue[front_index] << endl;		//������ �� �� ��� 
	}
}

void back(int queue[])
{
	if (queue[front_index] == NULL) {//ť�� ��������� 
		cout << "-1" << endl;
	}
	else {
		cout << queue[rear_index - 1] << endl;		//ť �ȿ� ���� �����ϸ� �� �� �� ���� �� ��� , rear_index���� ���� X -> rear_index-1�� ������ ������ 
	}
}