class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        pre=0
        suff=0
        ans=float('-inf')
        n=len(nums)
        for i in range(n):
            if(pre==0): pre=1
            if(suff==0): suff=1
            pre=pre*nums[i]
            suff=suff*nums[n-i-1]
            ans=max(ans, max(pre, suff))
        return ans