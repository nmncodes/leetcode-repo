/*Q2. Sum of GCD of Formed Pairs
    implementation + two pointer + prefix array

   TC- O(nlogn) // sorting + gcd
   SC- O(n) // prefix array
*/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n= nums.size() ; 
        vector<int>pref(n , 0) ; 
        long long ans = 0 ; 
        int cnt = 0 ; 


        for(int i = 0 ; i < n; i++) {
            cnt = max(cnt , nums[i]) ;

            pref[i] = __gcd(cnt , nums[i]) ;
        }

        sort(pref.begin() , pref.end()) ; 

        int l = 0 ; 
        int r = n- 1; 

        while(l < r) {
            int ok = __gcd(pref[l] ,pref[r] ) ; 
            ans += ok ; 
            l++ ; 
            r-- ; 
        }

        return ans ; 
        
    }
};