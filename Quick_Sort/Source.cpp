#include<iostream>
using namespace std;

int partition(int *a, int p, int r) {
	int x, i, j, swap;
	x = a[r];				//Pivot
	i = p - 1;
	for (j = p;j <= r - 1;j++) {		//Less values at left side and Greater values from pivot at right side
		if (a[j] <= x) {
			i = i + 1;
			swap = a[j];
			a[j] = a[i];
			a[i] = swap;
		}
	}
	swap = a[i + 1];
	a[i + 1] = a[r];
	a[r] = swap;
	return i + 1;
}

void quicksort(int *a, int p, int r) {
	int q;
	if (p < r) {
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}



int main() {
	int a[8];
	cout << "Enter Array\n";
	for (int k = 0;k < 8;k++) {
		cin >>a[k];
	}
	int p = 0, r = 7;
	quicksort(a, p, r);
	for (int k = 0;k < 8;k++) {
		cout << "Quick_Sort :  " << a[k] << endl;
	}
	cin.get();
	system("pause");
}