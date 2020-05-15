class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0)   return 0;
        
        int total = 0;
        for(int i=0;i<A.size(); i++)
            total += A[i];
        
        int straight_max = FindMax(A);
        //cout << straight_max << " ";
        for(int i=0;i<A.size(); i++)
            A[i] = -1*A[i];
        
        int circ_max = (-1)*FindMax(A);
        //cout << circ_max << " ";
        if((total - circ_max) > straight_max and (total - circ_max) != 0)
            return (total - circ_max);
        
        return straight_max;
        
    }
    
    int FindMax(vector<int>& A)
    {
        int curr = A[0];
        int ans = A[0];
        for(int i=1;i<A.size(); i++)
        {
            curr = A[i] + max(curr, 0);
            ans = max(curr, ans);
        }
        return ans;
    }
};
