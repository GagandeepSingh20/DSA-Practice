"""
🔗 Problem Link: https://leetcode.com/problems/magical-sum/
🏷️ Problem No: 3359
📚 Problem Name: Magical Sum
🧩 Difficulty: Hard
🧠 Tags: Dynamic Programming, Bit Manipulation, Combinatorics, Memoization

📝 Problem Summary:
You are given:
- `total_count`: total number of elements to use
- `target_odd`: desired number of odd bits after computation
- `numbers`: a list of integers

You must calculate the number of ways to distribute `total_count` selections across the given numbers such that 
the **resulting carry propagation** through binary addition yields exactly `target_odd` bits set to `1`.

Return the count of such magical combinations modulo 10^9 + 7.

📘 Example:
Input: total_count = 3, target_odd = 2, numbers = [2, 5]
Output: 8

💡 Approach:
1️⃣ Use recursive **DFS + memoization** (`@lru_cache`) to explore all distributions.
2️⃣ State parameters:
    - `remaining`: numbers left to distribute
    - `odd_needed`: how many odd bits we still need
    - `index`: current number being processed
    - `carry`: carry value in binary addition
3️⃣ For each number, try taking 0..remaining times and calculate combinations via `math.comb`.
4️⃣ Recursively call DFS with updated carry and remaining values.
5️⃣ Cache results to avoid recomputation.

"""



MOD = 10**9 + 7
from functools import lru_cache
import math
from typing import List

class Solution:
    def magicalSum(self, total_count: int, target_odd: int, numbers: List[int]) -> int:
        
        @lru_cache(None)
        def dfs(remaining, odd_needed, index, carry):
            if remaining < 0 or odd_needed < 0 or remaining + carry.bit_count() < odd_needed:
                return 0
            if remaining == 0:
                return 1 if odd_needed == carry.bit_count() else 0
            if index >= len(numbers):
                return 0
            
            ans = 0
            for take in range(remaining + 1):
                ways = math.comb(remaining, take) * pow(numbers[index], take, MOD) % MOD
                new_carry = carry + take
                ans += ways * dfs(remaining - take, odd_needed - (new_carry % 2), index + 1, new_carry // 2)
                ans %= MOD
            return ans
        
        return dfs(total_count, target_odd, 0, 0)
