class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        arr=[]
        for i in range(len(nums)):
            c=0
            for j in range(len(nums)):
                if i !=j:
                    if nums[i] > nums[j]:
                        c+=1
            arr.append(c)
        return arr