class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        
        int i=0;
        int j=0;
        
        while(i<A.size() and j<B.size())
        {
            vector<int> intersect = getMatch(A[i], B[j]);
            if(intersect.size() != 0)
                res.push_back(intersect);
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        
        return res;
    }
    
    
    
    //[1, 5] and [0, 2]
    vector<int> getMatch(vector<int> l1, vector<int> l2)
    {
        vector<int> res;
        if((l1[1]>=l2[0] and l1[1]<=l2[1]) or (l2[1]>=l1[0] and l2[1]<=l1[1]))
        {
            res.push_back(max(l1[0], l2[0]));
            res.push_back(min(l1[1], l2[1]));
        }
        
        return res;
    }
    
};
