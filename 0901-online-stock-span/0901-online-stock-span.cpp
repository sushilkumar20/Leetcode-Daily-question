class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index ;
    StockSpanner() {
        index =0;
    }
    
    int next(int price) {
        index+=1;
        
        while(st.size()&&st.top().second<=price)
            st.pop();
        
        if(st.size()==0)
        {
            st.push({index,price});
            return  index;
        }
        
        int result = st.top().first;
        st.push({index,price});
        
        return index-result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */