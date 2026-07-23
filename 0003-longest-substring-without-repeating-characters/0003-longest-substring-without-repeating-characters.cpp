class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high=0;
        int low=0;
        int res=INT_MIN;
        int n=s.size();
        unordered_map<char,int> f;
        for(high=0; high<n; high++){
            f[s[high]]++;
            while(f[s[high]]>1){
                f[s[low]]--;
                low++;
            }
            res=max(high-low+1,res);
        }
        if(res==INT_MIN){
            return 0;
        }
        return res;
    }
};