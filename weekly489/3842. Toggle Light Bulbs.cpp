/*
3842. Toggle Light Bulbs
TC: O(NlogN) 
SC: O(N) 

The idea is to map the bulbs and map the ones with odd freq,
as the ones with even freq will be off after x operations on it, x being the freq of that bulb.

sort the res and return it.

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