/*
3840. House Robber V
https://leetcode.com/problems/house-robber-v
TC: O(n)
SC: O(1)
SC: O(1)
  As we cant rob two adjacent houses with the same color, we can maintain two variables one for the old house and one for the current house.
  If the current house has a different color than the old house, we can add the current house's money to the current variable, 
  otherwise we can add the current house's money to the previous variable.
*/


class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size(); 
        if(n == 1 ) {
            return nums[0] ; 
        }

        long long ok = nums[0] ; 
        long long cnt = 0 ; 

        if(colors[1] != colors[0]) {
            cnt = nums[0] + nums[1] ; 
        }
        else {
            cnt = max(nums[0] , nums[1]) ; 
        }

        for(int i = 2 ; i < n; i++) {
            long long chk = 0 ; 

            if(colors[i] != colors[i - 1]) {
                chk = nums[i] + cnt ; 
            }
            else {
                chk = nums[i] + ok ; 
            }

            long long c = max(cnt , chk); 
            ok = cnt ; 
            cnt = c ;
        }

        return cnt ; 
        
    }
};