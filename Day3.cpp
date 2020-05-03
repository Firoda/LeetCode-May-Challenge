class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int countMag[26];
        int countRan[26];
        memset(countMag, 0, sizeof(countMag));
        memset(countRan, 0, sizeof(countRan));
        
        for(int i=0;i<ransomNote.length(); i++)
            countRan[ransomNote[i]-'a']++;
        for(int i=0;i<magazine.length(); i++)
            countMag[magazine[i]-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(countMag[i] < countRan[i])
                return false;
        }
        return true;
    }
};
