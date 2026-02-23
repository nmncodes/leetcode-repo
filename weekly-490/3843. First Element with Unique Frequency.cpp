/* 3843. First Element with Unique Frequency
map the freq of nums 

then map the freq of freq 

then check for the first element in nums whose freq of freq is 1

TC- O(n)
SC- O(n)
*/

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size(); 
        int cnt = 0 ; 
        unordered_map<int , int>mpp ; 

        for(auto x : nums) {
            mpp[x]++ ; 
        }

        unordered_map<int ,int>ok ; 

        for(auto it : mpp) {
            ok[it.second]++ ; 
        } 
        // int freq = 0 ; 
        // for(auto it : ok) {
        //     if(it.second == 1) {
        //         freq = it.first ;
        //          break ; 
        //     }
        // }

        for(auto it : nums) {
            if(ok[mpp[it]] == 1) {
                return it ; 
            }
        }

      
            return -1 ; 
      
        
    }
};