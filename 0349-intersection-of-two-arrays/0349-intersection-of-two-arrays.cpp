class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            st1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            if(st1.count(nums2[i]) && !st2.count(nums2[i])){
                ans.push_back(nums2[i]);
                st2.insert(nums2[i]);
            }
        }
        return ans;
    }
};