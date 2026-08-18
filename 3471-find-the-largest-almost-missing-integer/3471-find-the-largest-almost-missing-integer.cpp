class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int ans = nums[0];
            for (int i = 0; i < n; i++) {
                ans = max(ans, nums[i]);
            }
            return ans;
        }
        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
        }
        
        int ans = -1;
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                if (counts[nums[i]] == 1) {
                    ans = max(ans, nums[i]);
                }
            }
            return ans;
        }
        if (counts[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};