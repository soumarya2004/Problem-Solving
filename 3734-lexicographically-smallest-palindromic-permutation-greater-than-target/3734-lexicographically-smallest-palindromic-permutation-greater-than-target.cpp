class Solution {
public:
    string makePalindrome(string half, char mid, bool odd) {
        string ans = half;
        if (odd) {
            ans += mid;
        }
        reverse(half.begin(), half.end());
        ans += half;
        return ans;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int oddCount = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                oddCount++;
                mid = 'a' + i;
            }
        }
        if (oddCount > 1) {
            return "";
        }
        bool odd = n % 2;
        string half;
        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
        }
        int m = n / 2;
        string targetHalf = target.substr(0, m);
        vector<int> cnt(26, 0);
        for (char c : half) {
            cnt[c - 'a']++;
        }
        bool canMakeTargetHalf = true;
        for (char c : targetHalf) {
            if (cnt[c - 'a'] == 0) {
                canMakeTargetHalf = false;
                break;
            }
            cnt[c - 'a']--;
        }
        if (canMakeTargetHalf) {
            string candidate = makePalindrome(targetHalf, mid, odd);
            if (candidate > target) {
                return candidate;
            }
        }
        for (int pos = m - 1; pos >= 0; pos--) {
            vector<int> cnt(26, 0);
            for (char c : half) {
                cnt[c - 'a']++;
            }
            bool possible = true;
            for (int i = 0; i < pos; i++) {
                int x = targetHalf[i] - 'a';
                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }
                cnt[x]--;
            }
            if (!possible) {
                continue;
            }
            int t = targetHalf[pos] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string candidate;
                    candidate += targetHalf.substr(0, pos);
                    candidate += char('a' + c);
                    cnt[c]--;
                    for (int x = 0; x < 26; x++) {
                        while (cnt[x] > 0) {
                            candidate += char('a' + x);
                            cnt[x]--;
                        }
                    }
                    return makePalindrome(candidate, mid, odd);
                }
            }
        }
        return "";
    }
};