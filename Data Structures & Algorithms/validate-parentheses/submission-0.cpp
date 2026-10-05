class Solution {
public:
    bool isValid(string s) {

        //map for mapping closing brackets to opening brackets

        unordered_map<char,char> mp;

        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';

        //stack to keep track of the pair of valid paranthesis

        stack<char>st;

        for ( auto ch : s){

            if ( !mp.contains(ch)){

                st.push(ch);
            }else{

                if ( !st.empty() && st.top() == mp[ch]){

                    st.pop();
                }else{

                    return false; // the pair is not matching.
                }
            }

            


        }

        return st.empty();
        
    }
};
