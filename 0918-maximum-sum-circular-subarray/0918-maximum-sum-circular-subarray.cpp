class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currmax = 0;
        int currmin = 0;
        int minSum = nums[0];
        int maxSum = nums[0];
        int totalSum = 0;
        int circleMax = 0;
        int n = nums.size() - 1;
        for(int i = 0; i <= n; i++){
            totalSum += nums[i];
        }
        for(int i = 0; i <= n; i++){
            currmax += nums[i];
            currmin += nums[i];
            minSum = min(currmin, minSum);
            maxSum = max(currmax, maxSum);
            if(currmax < 0){
                currmax = 0;
            }
            if(currmin > 0){
                currmin = 0;
            }
            
            
        }
        if(maxSum < 0){
                return maxSum;
            }
        else{
        return max(totalSum - minSum, maxSum);
        }
    }
};