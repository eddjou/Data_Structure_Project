#include<iostream>
#include<math.h>
using namespace std;

int n = 8;
int total = 0;
int *c = new int(n);

bool check(int line) {
	for (int j = 0; j != line; j++) {
		if (c[line] == c[j] || line - c[line] == j - c[j] || line + c[line] == j + c[j])
			return false;
	}
	return true;
}

void queen(int line) {
	if (line == n)
		total++;
	else
		for (int i = 0; i != n; i++) {
			c[line] = i;
			if (check(line))
				queen(line + 1);
		}
}

int main() {
	queen(0);
	cout << "total solution = ";
	cout << total << endl;
	return 0;
}