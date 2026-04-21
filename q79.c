Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    // Initialize answer array with 0
    for (int i = 0; i < temperaturesSize; i++) {
        answer[i] = 0;
    }

    for (int i = 0; i < temperaturesSize; i++) {
        // Check for warmer temperature
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int index = stack[top--];
            answer[index] = i - index;
        }
        // Push current index to stack
        stack[++top] = i;
    }

    free(stack);
    *returnSize = temperaturesSize;
    return answer;
}