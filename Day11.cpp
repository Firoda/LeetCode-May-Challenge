class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
        queue<pair<int, int>> q;
        int currColor = image[sr][sc];
        if(currColor == newColor)
            return image;
        q.push({sr, sc});
        
        
        while(!q.empty())
        {
            pair<int, int> currPixel = q.front();   q.pop();
            int x = currPixel.first;
            int y = currPixel.second;
            image[x][y] = newColor;
            
            if(x-1>=0 and image[x-1][y] == currColor)
                q.push({x-1, y});
            if(x+1<image.size() and image[x+1][y] == currColor)
                q.push({x+1, y});
            if(y-1>=0 and image[x][y-1] == currColor)
                q.push({x, y-1});
            if(y+1<image[0].size() and image[x][y+1] == currColor)
                q.push({x, y+1});
        }
        
        return image;
    }
};
