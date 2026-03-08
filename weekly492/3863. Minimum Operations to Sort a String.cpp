/*
( upsolved )
3863. Minimum Operations to Sort a String

answer can only be 1,2,3 or -1
-1 is when there are only 2 chars that arent sorted

if the smallest char is at the beginning of the string then the answer is 1 

the key is make sure that the smallest char is at the beginning and the largest char is at the end of the string, 
then we can have 2 or 3 as the answer depending on the position of the other chars
if intermediate chars are neither smallest or the largest then we will have 3 ops else 2

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

        int cnt = 0 ; 
        int mx = -1 ; int mn = 1000 ; 

        for(auto x : s) {
            mx = max(mx, (int)x) ;
            mn = min(mn , (int)x ) ; 
        }

        if((int)s[0] == mx && (int)s[n - 1] ==mn) {
            for(int i = 1; i < n - 1; i++) {
                if((int)s[i] ==mn || (int)s[i] == mx ) {
                    return 2 ; 
                }

            }
            return 3;
        }

        if((int)s[0] == mn || (int)s[n - 1] == mx) {
            return 1 ; 
        }

        return 2 ; 
        
    }
};