class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int longest=0;
        unordered_set<int>::iterator it;
        for(it=st.begin(); it!=st.end(); it++){
            int num=*it;
            if(st.find(num-1)==st.end()){
                int current=num;
                int length=1;
                while(st.find(current+1)!=st.end()){
                    current++;
                    length++;
                }
                longest=max(longest, length);
            }
        }
        return longest;
    }
};