# GFG Problem: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
# Problem Name: Allocate Minimum Pages
# Level: Medium-Hard
# Tags: Binary Search, Greedy, Searching

"""
🧠 Problem Summary:
Given a list of books with page counts and `k` students, allocate books such that:
- Each student gets at least one book
- Books assigned to a student are contiguous
- Minimize the maximum number of pages assigned to any student

Return the minimum possible value of the maximum pages.

📌 Example:
Input: arr = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation - [12, 34, 67] and [90]

🛠️ Approach:
- Use Binary Search on the answer space (from max single book to total pages)
- For each mid value, check if allocation is valid using a greedy helper
- If valid, try minimizing further; else increase the allowed pages

🧮 Time Complexity: O(n log(sum of pages))
🧮 Space Complexity: O(1)
"""

class Solution:
    def valid(self, arr, k, mid) -> bool:
        st = 1  # student count
        pages = 0

        for i in arr:
            if i > mid:
                return False
            if pages + i <= mid:
                pages += i
            else:
                st += 1
                pages = i

        return st <= k

    def findPages(self, arr, k):
        if len(arr) < k:
            return -1

        s = max(arr)
        e = sum(arr)
        ans = 0

        while s <= e:
            mid = (s + e) // 2
            if self.valid(arr, k, mid):
                ans = mid
                e = mid - 1
            else:
                s = mid + 1

        return ans
