class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> us;
        for(int i=0;i<J.length(); i++)
            us.insert(J[i]);
        
        int count = 0;
        for(int i=0;i<S.length(); i++)
        {
            if(us.find(S[i]) !=us.end())
                count++;
        }
        return count;
    }
};
