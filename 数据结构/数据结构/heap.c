#include <stdio.h>

struct heap_t {
	int arr[100];
	int size;
};
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t; 
}
void heap_move(int arr[], int root, int size) {
	for (int child = 2 * root + 1; child < size; child = 2 * child + 1) {
		if (child < size - 1 && arr[child + 1] > arr[child])
			child++;
		if (arr[root] >= arr[child])
			break;
		swap(&arr[root],&arr[child]);
		root = child;
	}
}

void heap_up(int arr[], int child) {
	for (int root = child / 2; root >=0 ; root = root / 2) {
		if (arr[root] >= arr[child])
			break;
		swap(&arr[root],&arr[child]);
		child = root;
	}
}

void heap_down(int arr[], int size) {
	heap_move(arr, 0, size);
}

void heap_push(struct heap_t *heap, int v){
	heap->arr[heap->size++] = v;
	heap_up(heap->arr, heap->size - 1);
}

int heap_pop(struct heap_t *heap){
	int v = heap->arr[0];
	heap->arr[0]=heap->arr[(heap->size--)-1];
	heap_down(heap->arr, heap->size);
	return v;
}

void heap_init(struct heap_t *heap, int arr[], int size) {
	for(int i=0;i<size;i++){
		heap->arr[i] =  arr[i];
	}
	heap->size = size;
	for (int i = (heap->size - 1 - 1) / 2; i >= 0; i--) {
		heap_move(heap->arr, i, size);
	}
}

void heap_print(struct heap_t *heap){
	for (int child = 0; child < heap->size; child = 2 * child + 1) {
		for (int j = child; j < 2 * child + 1 && j < heap->size; j++)
			printf("%4d", heap->arr[j]);
		printf("\n");
	}
}

int main() {
	int arr[] = {21, 37, 51, 45, 61, 22, 41, 5, 54, 21, 12, 38, 56};
	struct heap_t heap;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
	printf("\n");
	heap_init(&heap, arr, sizeof(arr) / sizeof(arr[0]));
	heap_print(&heap);
	heap_push(&heap, 55);
	heap_print(&heap);
	heap_pop(&heap);
	heap_print(&heap);
}
