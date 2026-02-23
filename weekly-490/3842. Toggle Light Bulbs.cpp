/* 3842. Toggle Light Bulbs
map bulbs

if frequency of a bulb is odd, then it will be on , else off

now sort and return 

TC- O(nlogn)
SC- O(n)
*/


class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int , int>mpp ; 
        int n = bulbs.size() ; 
        int cnt = 0 ; 
        vector<int>res ; 
        sort(bulbs.begin() , bulbs.end()) ; 
        for(auto x : bulbs) {
            mpp[x]++ ; 
        }

        for(auto it :mpp) {
            if(it.second % 2 != 0) {
                res.push_back(it.first) ; 
            }
        }

        sort(res.begin() , res.end()); 
        return res ; 
    }
};