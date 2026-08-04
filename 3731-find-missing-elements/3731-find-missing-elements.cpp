class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <int> ans;
        for(int i=0; i<nums.size()-1; i++){
            for(int x=nums[i]+1; x<nums[i+1]; x++){
                ans.push_back(x);
            }
        }
        return ans;
    }
};