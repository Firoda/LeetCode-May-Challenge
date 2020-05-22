class Solution {
public:
    string frequencySort(string s) {
        if(s.length() == 0) return "";
        
        unordered_map<char, int> umap;
        
        for(int i=0;i<s.length(); i++)
            umap[s[i]]++;
        
        vector<pair<int, char>> counts;
        
        for(auto& it: umap)
        {
            int n = it.second;
            char c =  it.first;
            counts.push_back({n, c});
        }
        
        sort(counts.begin(), counts.end());
        string res = "";
        
        for(int i=counts.size()-1; i>=0; i--)
        {
            res.append(counts[i].first, counts[i].second);
        }
        return res;
    }
};
