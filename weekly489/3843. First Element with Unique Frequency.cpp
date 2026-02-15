/*
3843. First Element with Unique Frequency
https://leetcode.com/problems/first-element-with-unique-frequency

TC: O(n)
SC: O(n)

map the freq of each element in the array.
now the the freq of those elements.
Ex: [1 , 2,1 ,  2 , 2 , 1] ==> 1=> 3 , 2 => 3 ,  map ok[3] = 2 , as both 1 and 2 have freq of 3.  
once done , find the first ok[freq] == 1 , unique frequency and return it 
else -1 
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
        int freq = 0 ; 
        for(auto it : ok) {
            if(it.second == 1) {
                freq = it.first ;
                 break ; 
            }
        }

        for(auto it : nums) {
            if(ok[mpp[it]] == 1) {
                return it ; 
            }
        }

      
            return -1 ; 
      
        
    }
};