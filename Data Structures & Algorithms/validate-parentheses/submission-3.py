class Solution:
    def isValid(self, s: str) -> bool:
        map = {')' : '(', ']' : '[', '}': '{'}

        stack = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            elif len(stack) > 0 and stack[len(stack)-1] == map[c]:
                stack.pop()
            else: return False
            
        return stack == []