class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        ss = [0] * 26
        for c in s:
            ss[ord(c) - ord('a')] += 1
        for c in t:
            ss[ord(c) - ord('a')] -= 1

        return ss == ([0] * 26)
