class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        unordered_map<int, int> umap;
        // First- prefix sum Second - index seen
        umap[0] = -1;
        int prefix_sum = 0;
        int max_length = 0;
        for(int i=0;i<nums.size(); i++)
        {
            if(nums[i] == 1) 
                prefix_sum++;
            else    
                prefix_sum--;
            
            
            if(umap.find(prefix_sum) != umap.end())
            {  
                max_length = max(max_length, i - umap[prefix_sum]);
            }
            else
                umap[prefix_sum] = i;
        }
        return max_length;
    }
};
