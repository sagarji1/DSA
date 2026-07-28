class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency
        for (char c : s)
            freq[c - 'a']++;

        string left = "", mid = "";

        for (int i = 0; i < 26; i++) {
            // Add half of the characters to the left
            while (freq[i] > 1) {
                left += char('a' + i);
                freq[i] -= 2;
            }

            // If one character is left, it goes in the middle
            if (freq[i] == 1)
                mid = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};