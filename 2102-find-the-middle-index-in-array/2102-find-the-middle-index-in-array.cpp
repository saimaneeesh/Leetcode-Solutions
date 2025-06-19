class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int count = 0;
        long sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
        }
        long first = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(first == (sum - first - nums[i])){
                return i;
            }
            first += nums[i];
        }
        return -1;
    }
};