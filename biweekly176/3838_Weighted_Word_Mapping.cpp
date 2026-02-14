/* 3838. Weighted Word Mapping
https://leetcode.com/problems/weighted-word-mapping/description
TC: O(n)
SC: O(n)
 Implementation problem
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size() ; 
        string res = "" ; 
        int sz = weights.size() ; 
        for(int i = 0 ; i < n ; i++) {
            int sum = 0 ;
            for(int j = 0 ; j < (int)words[i].size() ; j++ ){
                int num = words[i][j]  - 'a' ; 
                sum += weights[num] ; 
            }
            sum = (sum % 26) ; 
            char ch = 'a' + (25 - sum) ; 
            res += ch ; 
        }

        return res ;
    }
};