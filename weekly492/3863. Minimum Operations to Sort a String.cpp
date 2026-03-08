/*
(will upsolve later)
3863. Minimum Operations to Sort a String

answer can only be 1,2,3 or -1
-1 is when there are only 2 chars that arent sorted

if the smallest char is at the beginning of the string then the answer is 1 

*/

class Solution {
public:
    int minOperations(string s) {
        string r = s ; 
        sort(r.begin() , r.end()) ; 

        if(s == r) return 0 ; 
        int n = s.size() ; 
        if(s != r && n == 2) return -1 ; 

        // ab minus 1 kabhi nahi ayega

        int idx = n + 1 ; 

        char cr = r[0] ; 

        for(int i = 0 ; i < n; i++) {
            if(cr == s[i]) {
                idx = min(idx , i);  
            }
        }

        if(idx == 0 ) {
            return 1 ; 
        }

        int idx1 = n + 1 ; 

        for(int i= 0 ; i < n; i++) {
            if(s[i] == cr){
                idx1 = i ; 
            }
        }

        if(idx1 != n - 1) {
            string q = s.substr(idx1 + 1 , n- idx1) ; 
            string sq = q ;
            sort(sq.begin() , sq.end()) ; 

            if( sq == q) {
                sort(s.begin() , s.end() -1 ) ;
                cout<<s<<endl; 
                if(s == r) return 1 ; 
                return 2 ; 
            }
            else {
                return 2 ; 
            }

        }

        // sort(s.begin() + 1 , s.end()) ;
        string hm = s.substr(1 , n - 1); 
        sort(hm.begin(), hm.end()) ; 
        // cout<<hm<<" " ; 
        if(hm == s.substr(1 , n - 1)) {
            return 2 ; 
        }
        // cout<<s<<endl ; 
        sort(s.begin() + 1 , s.end()) ;


        int cnt = 2 ;

        sort(s.begin() , s.end() - 1); 
        cout<<s<<endl ; 

        if(s == r) {
            return cnt ; 
        }

        return cnt + 1; 
        
    }
};