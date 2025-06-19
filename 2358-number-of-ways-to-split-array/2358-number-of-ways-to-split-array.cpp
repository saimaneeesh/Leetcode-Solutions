class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        long sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
        }
        long first = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            first += nums[i];
            if(first >= (sum - first)){
                count++;
            }
        }
        return count;
    }
};