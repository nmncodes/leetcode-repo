class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size() ; 
        int cnt = 0 ; 
        int ok = 1e9 ; 
        for(int i = 0 ; i < n ; i++) {
            if(capacity[i] >= itemSize ) {
                    ok = min(ok , capacity[i]) ; 
            }
        }

        for(int i = 0 ;i < n; i++) {
            if(capacity[i] == ok) {
                return i  ; 
                
            }
        }

        return -1 ; 
    }
};