class StockSpanner {
public:
    vector<int> list;
    StockSpanner() {
        list = vector<int>();
    }
    
    int next(int price) {
        
        list.push_back(price);
        int j = list.size() - 2;
        while(j>=0 and list[j] <= price)
            j--;
        
        return list.size() - 1 - j;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
