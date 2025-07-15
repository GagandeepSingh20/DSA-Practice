// Leetcode Problem: https://leetcode.com/problems/valid-word/
// Problem Number: 3136
// Problem Name: Valid Word
// Level: Easy
// Tags: Strings, Validation

/*
🧠 Problem Summary:
A word is valid if:
1. It has at least 3 characters
2. It contains at least one vowel and at least one consonant
3. All characters must be letters or digits
4. Any symbol or special character makes it invalid

📌 Example:
Input: "abc123"
Output: true

Input: "@b3"
Output: false

🛠️ Approach:
- Check length < 3 → false
- Traverse the string:
    - If a letter: check if it's a vowel or consonant
    - If a digit: skip
    - Else: invalid → return false
- After loop, return true only if both vowel and consonant found

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
*/

// Leetcode Problem: https://leetcode.com/problems/valid-word/
// Problem Number: 3136
// Problem Name: Valid Word
// Level: Easy
// Tags: Strings, Validation

/*
🧠 Problem Summary:
A word is valid if:
1. It has at least 3 characters
2. It contains at least one vowel and at least one consonant
3. All characters must be letters or digits
4. Any symbol or special character makes it invalid

📌 Example:
Input: "abc123"
Output: true

Input: "@b3"
Output: false

🛠️ Approach:
- Check length < 3 → false
- Traverse the string:
    - If a letter: check if it's a vowel or consonant
    - If a digit: skip
    - Else: invalid → return false
- After loop, return true only if both vowel and consonant found

🧮 Time Complexity: O(n)
🧮 Space Complexity: O(1)
*/

class Solution {
public:
    bool isValid(string words) {
        if (words.length() < 3) return false;

        int n = words.length();
        bool vowel = false;
        bool consonant = false;

        for (int i = 0; i < n; i++) {
            char ch = words[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    vowel = true;
                else
                    consonant = true;
            }
            else if (ch >= '0' && ch <= '9') {
                continue;
            }
            else {
                return false; // invalid character
            }
        }

        return vowel && consonant;
    }
};

