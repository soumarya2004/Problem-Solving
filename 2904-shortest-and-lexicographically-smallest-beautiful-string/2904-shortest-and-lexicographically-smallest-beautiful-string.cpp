class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        for (int right = 0; right < n; right++) {
            if (s[right] == '1'){
                ones++;
            }
            if (ones == k) {
                while (left <= right && s[left] == '0'){
                    left++;
                }
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                }
                else if (len == minLen) {
                    string curr = s.substr(left, len);
                    if (ans == "" || curr < ans){
                        ans = curr;
                    }
                }
                while (left <= right && s[left] != '1')
                    left++;
                left++;
                ones--;
            }
        }
        return ans;
    }
};