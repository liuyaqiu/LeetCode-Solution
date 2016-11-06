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

