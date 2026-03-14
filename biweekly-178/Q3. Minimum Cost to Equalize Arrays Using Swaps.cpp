/* Q3. Minimum Cost to Equalize Arrays Using Swaps
  first deal with the edge case where the freq of an element is odd
  FOR ex-> [10 , 20] and [10 , 10] . we cant equalise these arrays in any way

  then map both vectors, store the elements in a set 
  and iterate over the set
  balance is freq / 2 , and we figure out how many elements we have to swap from nums1 to nums2 and add that to the answer
  as swapping in own array is free, only this cost is incurred 

  TC- O(nums1.sizs() + nums2.size()) 
  SC- O(n) // map size
*/

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size() ; 
        unordered_map<int , int>mpp ; 

        for(auto x : nums1)mpp[x]++ ; 
        for(auto x : nums2)mpp[x]++ ; 

        for(auto it : mpp) {
            if(it.second & 1)return -1 ;
        }

        // iske baad -1 nahi ayega

        unordered_map<int , int>cnt1 ; 
        unordered_map<int , int>cnt2 ; 

        for(auto x : nums1)cnt1[x]++ ; 
        for(auto x : nums2)cnt2[x]++ ; 

        long long ans = 0 ; 

        unordered_set<int>ke ; 

        for(auto it : cnt1) {
            ke.insert(it.first) ; 
        }
         for(auto it : cnt2) {
            ke.insert(it.first) ; 
        }


        for(auto x : ke) {

            int sum = cnt1[x] + cnt2[x] ; 

            int tg = sum / 2; 

            if(cnt1[x] > tg) {
                ans += cnt1[x] - tg ; 
            }
        }

        return ans ; 


    }
};