class Solution {
public:
    bool isValid(string s) {


        //map 

        unordered_map<char,char> mp;

        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';

        //stack
        stack<char>st;

       

        for ( auto x : s){

            if ( !mp.contains(x)){

                st.push(x);
            }else{

                if ( !st.empty() && st.top() == mp[x]){

                    st.pop();
                    
                }else{

                    return false;
                }
            }
        }

        return st.empty();
        
    }
};
