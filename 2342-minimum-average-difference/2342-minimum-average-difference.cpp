class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
        }
        int s = nums.size()-1;
        long long avg = 0;
        long long avgl = 0;
        int min = INT_MAX;
        long long first = 0;
        int index = 0;
       for(int i = 0; i < nums.size(); i++){
            avg += nums[i];
            avgl = avg / (i + 1);
            long long avgr = 0;
            if (s > 0) {
                avgr = (sum - avg) / s;
            }
            first = abs(avgl - avgr);
            s--;
            if(min > first){
                min = first;
                index = i;
            }
       }
        return index;
    }
};