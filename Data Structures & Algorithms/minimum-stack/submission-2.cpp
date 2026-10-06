class MinStack {
public:

    int topEl;
    vector<int> st;
    MinStack() {

        topEl = -1;
        
    }
    
    void push(int val) {

        
        topEl++;

        st.push_back(val);
        
    }
    
    void pop() {

        if ( topEl == -1){
            return;
        }

        topEl--;
        st.pop_back();
        
    }
    
    int top() {

        return st[topEl];
        
    }
    
    int getMin() {

        int minimum = INT_MAX;

        for ( int i = 0; i <= topEl ; i++){

            minimum = min(minimum, st[i]);
        }

        return minimum;
        
    }
};
