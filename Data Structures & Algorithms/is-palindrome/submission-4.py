class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while (l < r):
            if (not self.isValid(s[l])):
                l += 1
                continue
            if (not self.isValid(s[r])):
                r -= 1
                continue
                
            if s[l].lower() != s[r].lower():
                return False;
            l += 1
            r -= 1

        return True;
    
    def isValid(self, c: str) -> bool:
        n = ord(c)
        state1 = n - ord('A') >= 0 and n - ord('A') < 26
        state2 = n - ord('a') >= 0 and n - ord('a') < 26
        state3 = n - ord('0') >= 0 and n - ord('0') < 10
        return state1 or state2 or state3