# Leetcode Problem: https://leetcode.com/problems/lemonade-change/
# Problem Number: 860
# Problem Name: Lemonade Change
# Level: Easy
# Tags: Greedy, Simulation

"""
🧠 Problem Summary:
You are selling lemonade at $5 per cup. Customers pay with $5, $10, or $20 bills.
You must provide correct change using only the bills you have received so far.

Return True if you can provide change to every customer, otherwise False.

📌 Example:
Input: bills = [5,5,5,10,20]
Output: True

🛠️ Approach:
- Maintain counts of $5 and $10 bills
- For each bill:
  - $5 → just collect
  - $10 → give one $5 as change
  - $20 → prefer giving one $10 and one $5, else give three $5 bills
- If not possible at any step, return False

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
"""

from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        cnt = [0, 0]  # cnt[0]: $5 bills, cnt[1]: $10 bills

        for bill in bills:
            if bill == 5:
                cnt[0] += 1
            elif bill == 10:
                if cnt[0] > 0:
                    cnt[0] -= 1
                    cnt[1] += 1
                else:
                    return False
            else:  # bill == 20
                if cnt[1] >= 1 and cnt[0] >= 1:
                    cnt[1] -= 1
                    cnt[0] -= 1
                elif cnt[0] >= 3:
                    cnt[0] -= 3
                else:
                    return False

        return True
