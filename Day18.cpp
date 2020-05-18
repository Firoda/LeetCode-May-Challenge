class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())   return false;
        if(s1.length() == 0)    return true;
        
        int countS1[26];
        memset(countS1, 0, sizeof(countS1));
        
        int countS2[26];
        memset(countS2, 0, sizeof(countS2));
        
        for(int i=0;i<s1.length(); i++)
            countS1[s1[i] - 'a']++;
        
        int start = 0;
        for(int i=0;i<s1.length(); i++)
            countS2[s2[i] - 'a']++;
        
        for(int j=s1.length(); j<s2.length(); j++)
        {
            if(areEqual(countS1, countS2))
                return true;
            countS2[s2[j] - 'a']++;
            countS2[s2[start] - 'a']--;
            start++;
        }
        if(areEqual(countS1, countS2))
                return true;
        
        return false;
    }
    
    bool areEqual(int arr[26], int arr2[26])
    {
        for(int i=0;i<26;i++)
        if(arr[i] != arr2[i])
            return false;
        
        return true;
    }
    
};
