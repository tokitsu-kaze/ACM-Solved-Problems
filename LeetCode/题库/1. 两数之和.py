class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = dict()
        i = 0
        for it in nums:
            if target - it in mp:
                return [mp[target - it], i, ]
            mp[it] = i
            i += 1
        
