class Solution {
public:

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0)    return true;
        
        
        for(int i=0;i<dislikes.size(); i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        
        
        for(int node=1;node<=N;node++)
        {
            if((color.find(node) == color.end()) and !dfs(node, 0))
                return false;
        }
       
        return true;
    }
    
    
    bool dfs(int node, int c)
    {
        if(color.find(node)!= color.end())
            return (color[node] == c);
        color[node] = c;
        for(int i=0;i<graph[node].size(); i++)
        {
            if(!dfs(graph[node][i], !c))
                return false;
        }
        return true;
    }
private:
    unordered_map<int, int> color;
    unordered_map<int, vector<int>> graph;
};

