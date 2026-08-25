class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int n = prices.size();
        int mini = INT_MAX;
        for(auto price:prices){
            mini = min(mini,price);
            ans=max(ans,price-mini);
        }
        return ans;
    }
};