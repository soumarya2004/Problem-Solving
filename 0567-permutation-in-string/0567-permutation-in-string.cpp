class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> need(26,0);
        vector<int> window(26,0);
        for(int i=0; i<s1.size(); i++){
            need[s1[i]-'a']++;
        }
        int left=0;
        for(int right=0; right<s2.size(); right++){
            window[s2[right]-'a']++;
            if(right-left+1 > s1.size()){
                window[s2[left]-'a']--;
                left++;
            }
            if(need==window){
                return true;
            }
        }
        return false;
    }
};