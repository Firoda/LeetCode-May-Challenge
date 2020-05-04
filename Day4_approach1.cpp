class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;
        vector<int> ar;
        binary(num, ar);
       
        invert(ar);
             
        //addOne(ar);
        return convertToNum(ar);
      
         // for(int i=0;i<ar.size(); i++)
          //   cout << ar[i] << " ";
       //cout << convertToNum(ar) << " ";  
    }
    
    void binary(int num, vector<int>& ar)
    {
        while(num > 0)
        {
            ar.push_back(num%2);
            num/=2;
        }
    }
    void invert(vector<int>& ar)
    {
        for(int i=0;i<ar.size(); i++)
        {
            if(ar[i] == 0)
                ar[i] = 1;
            else
                ar[i] = 0;
        }
    }
    
    void addOne(vector<int>& ar)
    {
        ar[0] +=1;
        int carry = ar[0]/2;
        ar[0] = ar[0]%2;
        for(int i=1;i<ar.size(); i++)
        {
            ar[i] = ar[i] + carry;
            carry = ar[i]/2;
            ar[i] = ar[i]%2;
        }
        while(carry > 0)
        {
            ar.push_back(carry%2);
            carry/=2;
        }
    }
    
    
    int convertToNum(vector<int>& ar)
    {
        int res = 0;
        for(int i=0;i<ar.size(); i++)
        {
            res+= pow(2, i)*ar[i];
        }
        return res;
    }
};
