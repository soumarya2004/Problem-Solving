class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int res=INT_MIN;
        unordered_map<int,int> f;
        for(int high=0; high<nums.size(); high++){
            f[nums[high]]++;
            while(f[0]>k){
                f[nums[low]]--;
                if(f[nums[low]]==0){
                    f.erase(nums[low]);
                }
                low++;
            }
            res=max(res,high-low+1);
        }
        if(res==INT_MIN){
            return 0;
        }
        return res;
    }
};