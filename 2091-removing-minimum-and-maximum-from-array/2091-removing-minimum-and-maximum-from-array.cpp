class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = 0, mx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn]) mn = i;
            if (nums[i] > nums[mx]) mx = i;
        }
        int a = min(mn, mx);
        int b = max(mn, mx);
        int option1 = b + 1;
        int option2 = n - a;
        int option3 = a + 1 + n - b;
        return min({option1, option2, option3});
    }
};