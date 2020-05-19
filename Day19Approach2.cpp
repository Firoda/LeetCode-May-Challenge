class StockSpanner {
public:
     
    stack<pair<int, int>> st; 
    StockSpanner() {
        st  =  stack<pair<int, int>>();
    }
    
    int next(int price) {
        
        int res = 1;
        while(!st.empty() and st.top().first <= price)
        {
            res+=st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};

