#include<iostream>
using namespace std;
#define Element rectype
const int defaultsize = 100;
typedef struct RecType {
	int key;
	int info;
}rectype;
class recordlist {
private:
	Element *R;
	int maxsize;
	int currentsize;
public:
	recordlist(int maxsz = defaultsize)
	{
		R = new Element[maxsz];
		maxsize = maxsz;
		currentsize = 0;
	}
	void init(int a[], int b[], int size) {
		for (int i = 0; i < size; i++)
		{
			R[i].key = a[i];
			R[i].info = b[i];
		}
		currentsize = size;
	}
	void print() {
		cout << "key" << "\t" << "info" << endl;
		for (int i = 0; i < currentsize; i++) {
			cout << R[i].key << "\t" << R[i].info << endl;
		}
	}
	void InsertSort();
	void InsertSort(RecType R[], int n);
	void ShellSort();
	~recordlist() { delete[]R; }
};
void recordlist::InsertSort() {
	for (int i = 1; i < currentsize; i++)
	{
		Element temp = R[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (temp.key < R[j].key)
				R[j + 1] = R[j];
			else {
				R[j + 1] = temp;
				break;
			}
			if (j == 0)R[0] = temp;
		}
	}
}
void recordlist::InsertSort(RecType P[], int n) {
	if (n > 1) {
		int i, j;
		for (i = 1; i < n; i++)
		{
			Element temp = P[i];
			for (int j = i - 1; j >= 0; j--)
			{
				if (temp.key < P[j].key)
					P[j + 1] = P[j];
				else {
					P[j + 1] = temp;
					break;
				}
				if (j == 0)P[0] = temp;
			}
		}
	}

}
void recordlist::ShellSort() {
	int h = 1;//gap
	while (3 * h + 1 < currentsize)
	{
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (int i = 0; i < h; i++) {
			int r = (currentsize - i - 1) / h + 1;//elem num of per group
			Element *Q = new Element[r];
			for (int j = 0; j < r; j++) {
				Q[j] = R[i + j*h];
			}
			InsertSort(Q, r);
			for (int j = 0; j < r; j++) {
				R[i + j*h] = Q[j];
			}
			delete[]Q;
		}
		h = (h - 1) / 3;
	}
}
void main() {
	recordlist L(15);
	int a[7] = { 1,5,4,7,2,3,6 };
	int b[7] = { 100,500,400,700,200,300,600 };
	cout << "origin:" << endl;
	int n = sizeof(a) / 4;
	L.init(a, b, n);
	L.print();
	cout << "\nafter:" << endl;
	L.ShellSort();
	L.print();
}