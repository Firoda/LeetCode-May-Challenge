class StockSpanner {
public:
    vector<int> list;
    unordered_map<int, int> umap; // Index ~~ stock span
    StockSpanner() {
        list = vector<int>();
    }
    
    int next(int price) {
        
        list.push_back(price);
        int curridx = list.size() - 1;
        if(curridx == 0 || list[curridx-1] > price)
        {
            umap[curridx] = 1;
            return 1;
        }
        int res = 1;
        int j = curridx - 1;
        while(j>=0 and list[j] <= price)
        {
            res+=umap[j];
            j = j - umap[j];
        }
        umap[curridx] = res;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
