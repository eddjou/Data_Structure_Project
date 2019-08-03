#include<iostream>
using namespace std;
class stack
{
private:
	int maxsize;
	int top;
	int a[1000];
	int currsize;
public:
	stack(int mxsize)
	{
		top = 0;//above current element
		maxsize = mxsize;
		currsize = 0;
		for (int i = 0; i < mxsize; i++) {
			a[i] = 0;
		}
	};
	~stack() {};
	int pop()
	{
		if (top > 0) {
			currsize--;
			top--;
			return a[top];
		}
	}
	int push(int n) {
		a[top] = n;
		top++;
		currsize++;
		return a[top - 1];
	}
	void print() {
		for (int i = 0; i < currsize; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
};

int main()
{
	stack stk(10);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.pop();
	stk.push(5);
	stk.print();
	return 0;
}