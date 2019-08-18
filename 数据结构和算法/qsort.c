#include <stdio.h>

void quicksort(int a[], int l, int h) {
	int i = l, j = h , key;
	if (l >= h)
		return;
	key = a[i];
	while (i < j) {
		while (i < j && a[j] > key)j--;
		if (i < j) a[i++] = a[j];
		while (i < j && a[i] < key)i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, h);
}

void print(int a[],int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int i, n =10;
	int a[10] = {32,54,75,25,62,13,34,23,55,31};
	print(a,n);
	quicksort(a, 0, 9);
	print(a,n);
	return 0;
}

