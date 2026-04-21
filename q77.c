Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    typedef struct {
        int key;
        int freq;
    } Node;

    // Comparator for qsort (descending by frequency)
    int cmp(const void* a, const void* b) {
        const Node* n1 = (const Node*)a;
        const Node* n2 = (const Node*)b;
        return n2->freq - n1->freq;
    }

    Node* map = (Node*)malloc(numsSize * sizeof(Node));
    int mapSize = 0;

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].key == nums[i]) {
                map[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            map[mapSize].key = nums[i];
            map[mapSize].freq = 1;
            mapSize++;
        }
    }

    // Sort by frequency
    qsort(map, mapSize, sizeof(Node), cmp);

    // Collect top k elements
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = map[i].key;
    }

    *returnSize = k;
    free(map);
    return result;

}