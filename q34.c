Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


int maxSubArray(int* nums, int numsSize) {
        int maxSoFar = nums[0];   
    int currentSum = nums[0];    

    for (int i = 1; i < numsSize; i++) {
        if (currentSum + nums[i] > nums[i]) {
            currentSum = currentSum + nums[i];
        } else {
            currentSum = nums[i];
        }
        if (currentSum > maxSoFar) {
            maxSoFar = currentSum;
        }
    }
    return maxSoFar;
}

