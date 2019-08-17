//数组中的第K个最大元素
//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

struct heap_t {
	int *arr;
	int size;
};

void heap_move(int arr[], int root, int size) {
    register int t = arr[root];
	for (register int child = 2 * root + 1; child < size; child = 2 * child + 1) {
		if (child < size - 1 && arr[child + 1] < arr[child])
			child++;
		if (t <= arr[child])
			break;
		arr[root] = arr[child];
		root = child;
	}
    arr[root] = t;
}

void heap_push(struct heap_t *heap, int v){
	if(heap->arr[0] >= v) return;
	heap->arr[0] = v;
	heap_move(heap->arr, 0, heap->size);
}

void heap_init(struct heap_t *heap, int arr[], int size) {
	heap->arr =  arr;
	heap->size = size;
	for (register int i = (heap->size - 1 - 1) / 2; i >= 0; i--) {
		heap_move(heap->arr, i, size);
	}
}

struct heap_t heap;
int findKthLargest(int* nums, int numsSize, int k){
    heap_init(&heap, nums, k);
    for(register int i = k; i < numsSize; i++){
        heap_push(&heap, nums[i]);
    }     
    return heap.arr[0];
}
