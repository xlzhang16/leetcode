class Solution {
public:
    string reverseString(string s) {
        for(int i = 0; i < s.length() / 2; i++){
            char tmp = s[i];
            s[i] = s[s.length() -1 - i];
            s[s.length() - 1 - i] = tmp;
        }
        return s;
    }
};
