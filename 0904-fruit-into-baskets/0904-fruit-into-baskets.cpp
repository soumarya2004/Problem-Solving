class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        int left=0;
        int ans=0;
        for(int right=0; right<fruits.size(); right++){
            f[fruits[right]]++;
            while(f.size()>2){
                f[fruits[left]]--;
                if(f[fruits[left]]==0){
                    f.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};