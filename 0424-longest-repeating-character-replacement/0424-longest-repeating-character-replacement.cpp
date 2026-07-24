class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0;
        int res=0;
        int maxcnt=0;
        unordered_map<char,int> f;
        for(int high=0; high<s.size(); high++){
            f[s[high]]++;
            int len=high-low+1;
            maxcnt=max(maxcnt, f[s[high]]);
            int diff=len-maxcnt;
            while(diff>k){
                f[s[low]]--;
                low++;
                len=high-low+1;
                maxcnt=max(maxcnt, f[s[high]]);
                diff=len-maxcnt;
            }
            len=high-low+1;
            res=max(res, len);
        }
        return res;
    }
};