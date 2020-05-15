class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == num.length())
            return "0";
        
        
        stack<char> st;
        int i = 0;
        while(i < num.size())
        {
            while(k > 0 and !st.empty() and st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        while(k > 0)
        {
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        i = 0;
        while(i<res.size() and res[i] == '0')
            i++;
        if(i == res.length())
            return "0";
        else
            return res.substr(i);
       
        
    }
};
