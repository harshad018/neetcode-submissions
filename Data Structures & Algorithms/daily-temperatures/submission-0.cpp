class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> s;

        int n = temperatures.size();

        vector<int> ans(n, 0);

        for ( int i = 0 ; i < temperatures.size() ; i++){


            while ( !s.empty() && temperatures[i] > temperatures[s.top()]){

                int prev_idx = s.top();

                ans[prev_idx] = i - prev_idx;


                s.pop();


            }

            s.push(i);




        }

        return ans;



        
    }
};
