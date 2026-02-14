/*
3839. Number of Prefix Connected Groups
https://leetcode.com/problems/number-of-prefix-connected-groups
TC: O(n)
SC: O(n)
 Discard strings with less than k characters.
 Then map the substring of each from index 0 to k-1th index 
 Once the word is used mark it as -1 to avoid counting it again
*/

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int cnt= 0 ; 


        vector<string>res ; 

        for(int i = 0 ; i < words.size() ; i++) {
            if(words[i].size() < k) {
                continue  ;
            }
            else {
                res.push_back(words[i]) ;
            }
        }
                int n = res.size() ; 

                
            unordered_map<string , int>mpp ; 

            for(auto x : res ) {
                mpp[x.substr(0 , k )]++ ; 
            }

        for(int i = 0 ; i < n ; i++){
            string wo = res[i]; 
            int ok = 0 ; 
            string hm = wo.substr(0 , k) ;
            
           
            if(mpp.find(hm) != mpp.end() ) {
                
                if(mpp[hm] != -1 && mpp[hm] >= 2 ){
                ok = 1 ;
                     // cout<<hm<<endl ;
                }
                mpp[hm] = -1 ; 
            }
            cnt += ok  ; 
            
        }

        return cnt ; 
    }
};