class Solution {
public:
    using ll = long long;
    ll LIMIT;
    ll C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIMIT) return LIMIT;
        }
        return ans;
    }
    ll countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;
        ll ans = 1;
        for (int x : cnt) {
            if (x == 0) continue;
            ans *= C(rem, x);
            if (ans > LIMIT) ans = LIMIT;
            rem -= x;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        LIMIT = k;
        vector<int> freq(26);
        for (char c : s){
            freq[c - 'a']++;
        }
        vector<int> half(26);
        string mid = "";
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2){
                mid.push_back(char('a' + i));
            }
        }
        if (countWays(half) < k){
            return "";
        }
        string left = "";
        int len = s.size() / 2;
        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0){
                    continue;
                }
                half[c]--;
                ll ways = countWays(half);
                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }
                k -= ways;
                half[c]++;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};