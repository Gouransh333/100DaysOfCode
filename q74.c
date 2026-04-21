ou are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8




typedef struct {
    int *heap;      
    int size;      
    int capacity;   
    int k; 
} KthLargest;

int kthLargestAdd(KthLargest* obj, int val);
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
     KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->size = 0;
    obj->capacity = k;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;

}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size++] = val;
        // bubble up
        int i = obj->size - 1;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (obj->heap[parent] <= obj->heap[i]) break;
            int tmp = obj->heap[parent];
            obj->heap[parent] = obj->heap[i];
            obj->heap[i] = tmp;
            i = parent;
        }
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        // heapify down
        int i = 0;
        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < obj->size && obj->heap[left] < obj->heap[smallest]) smallest = left;
            if (right < obj->size && obj->heap[right] < obj->heap[smallest]) smallest = right;
            if (smallest == i) break;
            int tmp = obj->heap[i];
            obj->heap[i] = obj->heap[smallest];
            obj->heap[smallest] = tmp;
            i = smallest;
        }
    }
    return obj->heap[0];

}

void kthLargestFree(KthLargest* obj) {
     free(obj->heap);
    free(obj);

}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/

