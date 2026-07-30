class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            int more=target-a;
            if(mp.find(more)!=mp.end()){
                return {mp[more], i};
            }
            mp[a]=i;
        }
        return {};
    }
};