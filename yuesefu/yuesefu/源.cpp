#include <iostream>
using namespace std;

struct node {
	int number;
	int code;
	struct node *next;
};

node *init(int n, int array[]) {
	int i = 1;
	node *head;
	node *current;
	node *next;
	current = static_cast<node *>(malloc(sizeof(node)));
	current->number = i;
	current->code = array[i - 1];
	head = current;
	for (i = 2; i <= n; ++i) {
		next = static_cast<node *>(malloc(sizeof(node)));
		next->number = i;
		next->code = array[i - 1];
		current->next = next;
		current = next;
	}
	current->next = head;
	return head;
}

void function(node *head, int len, int code) {
	node *pre;
	node *next;
	node *temp;
	next = head;
	for (int i = 1; i < len; ++i) {
		pre = next->next;
		next = next->next;
	}
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j < code; ++j) {
			pre = pre->next;
		}
		temp = pre->next;
		next = temp->next;
		code = temp->code;
		cout << temp->number  << "\t";
		pre->next = next;
		free(temp);
	}
}

int main() {
	int len;
	cout << "enter length£º";
	cin >> len;
	int *array=new int[len];
	cout << "enter maximum m:";
	int m;
	cin >> m;
	cout << "enter code: " << endl;
	for (int i = 0; i < len; ++i) {
		cin >> array[i];
	}
	node *head = init(len, array);
	cout << "dying list:\n ";
	function(head, len, m);
	cout << endl;
	return 0;
}