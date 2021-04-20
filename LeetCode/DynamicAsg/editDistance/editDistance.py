class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = dict()

        def dp(m: int, n: int) -> int:
            if (m, n) in memo:
                return memo[(m, n)]
            if m == -1:
                return n+1
            if n == -1:
                return m+1
            if word1[m] == word2[n]:
                memo[(m, n)] = dp(m-1, n-1)
            else:
                memo[(m, n)] = min(dp(m, n-1), dp(m-1, n), dp(m-1, n-1))+1
            return memo[(m, n)]
        return dp(len(word1)-1, len(word2)-1)


# print(Solution().minDistance("horse", "ros"))
