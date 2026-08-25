class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans =k;
        for(auto a:nums){
            if(a==ans){
                ans+=k;
            }
        }
        return ans;
    }
};