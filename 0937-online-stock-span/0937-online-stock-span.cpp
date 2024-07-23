class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    int index;
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        
        arr.push_back(price);
        index++;
        while(!st.empty() && arr[st.top()] <= arr[index])
            st.pop();
        
        int ans;
        if(st.empty()) ans=index+1;
        else
        ans = index-st.top();
        st.push(index);
        
        return ans;
    }
};