/*
 * Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 */

class solution {
    public:
        int lentghOfLongestSubstring(string s) {
            int start = 0, end = 1;
            int length = 0;
            while(end < s.size()) {
                int pos = s.find(s[end], start);
                if(pos < end) {
                    if(length < end - start)
                        length = end - start;
                    start += 1;
                }
                else
                    end += 1;
            }
            if(s.size() == 0)
                length = 0;
            else
                if(length < end - start)
                    length = end - start;
            return length;
        }
};

