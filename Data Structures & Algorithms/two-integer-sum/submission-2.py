class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for i in range(len(nums)):
            if nums[i] in map:
                return [map[nums[i]], i]
            else:
                map[target - nums[i]] = i

