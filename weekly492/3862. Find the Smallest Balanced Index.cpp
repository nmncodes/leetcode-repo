/*
3862. Find the Smallest Balanced Index
find sum of all elements and compare it with the suffix product
to avoid overflow issue.
as size is 10^5 and element 10^9 , we can have 10^14 as the product of 2 elements and 10^19 as the product of 3 elements, 
so we can not store the product of more than 3 elements in long long variable
*/

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int idx = -1 ; 
        int n= nums.size() ;
        long long cnt = 0 ; 
        long long chk = 0 ; 
        for(auto x: nums) {
            chk += x; 
        }
        chk += 1; 

        vector<long long> sfs(n + 1, 1) ; 

        for(int i = n - 1 ; i >=0 ; i--) {
            if(sfs[i + 1] > (chk / nums[i])) {
                sfs[i] = chk ; 
            }
            else
            sfs[i] = sfs[i + 1] * nums[i] ; 
           
        }

        for(int i = 0 ; i < n ; i++) {
            long long ok = sfs[i + 1] ; 

            if(ok == cnt){
                return i ; 
            }

            cnt += nums[i] ; 
        }

        return -1 ; 

        

        
    }
};