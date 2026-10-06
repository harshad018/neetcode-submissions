class Solution {
public:
    bool isAnagram(string s, string t) {

        //simple check

        if ( s.size () != t.size()){

            return false;
        }

        unordered_map<char,int> mp1;

        for ( auto ch : s){

            mp1[ch]++;
        }

        unordered_map<char,int>mp2;

        for ( auto x : t){

            mp2[x]++;
        }

        //check the apperance and frequencies. 

        for ( auto y : s){

            if ( mp1[y] != mp2[y]){

                return false;
            }
        }

        return true;
        
    }
};
