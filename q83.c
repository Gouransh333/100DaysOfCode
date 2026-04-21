The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]




typedef struct {
    int* maxHeap;
    int* minHeap;
    int maxSize;
    int minSize;
    int capacity;
} MedianFinder;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int* heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void minHeapifyUp(int* heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void maxHeapifyDown(int* heap, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapifyDown(heap, size, largest);
    }
}

void minHeapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapifyDown(heap, size, smallest);
    }
}
MedianFinder* medianFinderCreate() {
      MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->capacity = 10000;
    obj->maxHeap = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minHeap = (int*)malloc(sizeof(int) * obj->capacity);
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize++] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    } else {
        obj->minHeap[obj->minSize++] = num;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    }

    if (obj->maxSize > obj->minSize + 1) {
        obj->minHeap[obj->minSize++] = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    } else if (obj->minSize > obj->maxSize) {
        obj->maxHeap[obj->maxSize++] = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
     if (obj->maxSize > obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/