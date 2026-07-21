class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activecount = count(s.begin(),s.end(),'1');
        vector<int>inactiveblock ;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i]=='0') i++;
                inactiveblock.push_back(i-start);
            }
            else{
                i++;
            }
        }
        int max_activePair = 0;
        for(int i=1;i<inactiveblock.size();i++){
            max_activePair = max(max_activePair,inactiveblock[i]+inactiveblock[i-1]);
        }
        return max_activePair+activecount;
    }
};