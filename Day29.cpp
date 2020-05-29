class Solution {
public:
    unordered_map<int, vector<int>> graph;
    bool canFinish(int num, vector<vector<int>>& pre) {
        for(int i=0;i<pre.size(); i++)
            graph[pre[i][1]].push_back(pre[i][0]);
        
        vector<bool> visited(num, false);
        vector<bool> recStack(num, false);
        
        
        for(int i=0;i<num;i++)
        {
            if(isCyclic(i, visited, recStack))
                return false;
        }
        return true;
    }
    
    bool isCyclic(int src, vector<bool>& vis, vector<bool>& recStack)
    {
        if(!vis[src])
        {
            vis[src] = true;
            recStack[src] = true;
            
            for(auto it=graph[src].begin(); it!=graph[src].end(); it++)
            {
                if(!vis[*it] and isCyclic(*it, vis, recStack))
                    return true;
                else if(recStack[*it])
                    return true;
            }
            
            recStack[src] = false;
        }
        return false;
    }
    
};
