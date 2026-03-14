/* 3866. First Unique Even Element
  lc easy 
  TC - O(n)
  SC- O(n)// map size
*/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
       int n= nums.size() ; 
        unordered_map<int , int>mpp; 
        int cnt = 0 ; 

        for(auto x : nums){
            mpp[x]++ ; 
        }

        for(auto x : nums) {
            if(x % 2 == 0 && mpp[x] == 1) {
                return x ; 
            }
        }

        return -1 ; 
    }
};