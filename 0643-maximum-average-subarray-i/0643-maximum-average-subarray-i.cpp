class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowsum = 0;
        double m = INT_MIN;
        for(int i  = 0; i < nums.size(); i++){
            windowsum += nums[i];
            if(i >= k - 1){
                m = max(windowsum/k, m);
                windowsum -= nums[i - k + 1];
            }
        }
        return m;
    }
};