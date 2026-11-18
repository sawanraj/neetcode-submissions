class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix=strs[0];
        for s in strs[1:]:
            j=0
            while j<len(prefix) and j<len(s) and prefix[j]==s[j]:
                j+=1
            prefix=prefix[:j]
            if not prefix:
                break
        return prefix