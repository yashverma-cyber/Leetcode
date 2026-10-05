class Solution
{
public:
    // Array Approach (check ../Arrays/(E) Valid Anagram.cpp)
    bool isAnagramArray(string s, string t)
    {

        int cnt[26] = {0};
        if (size(s) != size(t))
            return false;
        for (int i = 0; i < size(s); ++i)
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] != 0)
                return false;
        }
        return true;
    }

    // Hashing approach (check ../Hashing/(E) Valid Anagram.cpp)
    bool isAnagramHash(string s, string t)
    {

        if (size(s) != size(t))
            return false;

        unordered_map<char, int> chcnt;

        for (char c : s)
            chcnt[c]++;

        for (char c : t)
        {
            if (chcnt.find(c) == chcnt.end() || chcnt[c] == 0)
                return false;
            chcnt[c]--;
        }
        return true;
    }
};
