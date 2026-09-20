class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        cnt=0
        el=0
        for i in range(len(nums)):
            if(cnt==0):
                cnt=1
                el=nums[i]
            elif(nums[i]==el):
                cnt+=1
            else:
                cnt-=1
        cnt1=0
        for i in range(len(nums)):
            if(nums[i]==el):
                cnt1+=1
        if(cnt1>(len(nums)//2)):
            return el
        return -1