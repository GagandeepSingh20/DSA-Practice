// File: 966-Vowel-Spellchecker.cpp

/**
 * LeetCode Problem: https://leetcode.com/problems/vowel-spellchecker/
 * Problem Number: 966
 * Problem Name: Vowel Spellchecker
 * Difficulty: Medium
 * Tags: Hash Table, String
 *
 * Problem Summary:
 * Given a wordlist and a set of queries, you must return the words from the wordlist
 * that match the queries according to the following priority:
 *  1. Exact match
 *  2. Case-insensitive match
 *  3. Vowel error match (vowels are interchangeable)
 * If no match is found, return an empty string "".
 *
 * Example:
 * Input:
 *   wordlist = ["KiTe","kite","hare","Hare"]
 *   queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
 * Output:
 *   ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
 *
 * Approach:
 *  - Use a set for exact matches.
 *  - Use a hashmap for lowercase matches (case-insensitive).
 *  - Use a hashmap for vowel-masked strings (treat all vowels as '*').
 *  - For each query, check in order:
 *      1. Exact set
 *      2. Lowercase hashmap
 *      3. Vowel-masked hashmap
 *      4. Otherwise return ""
 *
 * Time Complexity: O(N + Q * L), where:
 *   N = size of wordlist
 *   Q = number of queries
 *   L = average length of a word
 * Space Complexity: O(N * L) for hashmaps and sets
 */

class Solution {
public:
    string toLowerStr(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        return s;
    }

    string maskVowels(string s) {
        s = toLowerStr(s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                s[i] = '*'; // ASCII 42
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> casecheck;   // lowercase → original
        unordered_map<string, string> vowelcheck;  // masked vowels → original

        for (string &w: wordlist) {
            string low = toLowerStr(w);
            if (!casecheck.count(low)) casecheck[low] = w;

            string vow = maskVowels(w);
            if (!vowelcheck.count(vow)) vowelcheck[vow] = w;
        }

        for (string &q: queries) {
            if (exact.count(q)) { 
                ans.push_back(q); 
                continue; 
            }

            string low = toLowerStr(q);
            if (casecheck.count(low)) { 
                ans.push_back(casecheck[low]); 
                continue; 
            }

            string vow = maskVowels(q);
            if (vowelcheck.count(vow)) { 
                ans.push_back(vowelcheck[vow]); 
                continue; 
            }

            ans.push_back("");
        }

        return ans;
    }
};
