/*
(upsolved)
3844. Longest Almost-Palindromic Substring
https://leetcode.com/problems/longest-almost-palindromic-substring

TC: O(N^2)
SC: O(1)

for every index iterate left and right(expand palidrome)
then once for left , take an exception of 1 and expand normally, 
similarly for right, take an exception of 1 and expand normally, from the previous stored index
*/

class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length();
        int ans = 2;

        for (int i = 0; i < n; i++) {

            if (i > 0 && i < n - 1) {
                int l = i - 1;
                int r = i + 1;

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                if (l >= 0 || r < n){
                    ans = max(ans, r - l);
                }

                if (l > 0){
                    l--;
                }

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                ans = max(ans, r - l - 1);

                l = i - 1;
                r = i + 1;

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                if (r < n - 1){
                    r++;
                }

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                ans = max(ans, r - l - 1);
            }

            if (i < n - 1) {
                int l = i;
                int r = i + 1;

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                if (l >= 0 || r < n){
                    ans = max(ans, r - l);
                }

                if (l > 0){
                    l--;
                }

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                ans = max(ans, r - l - 1);

                l = i;
                r = i + 1;

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                if (r < n - 1){
                    r++;
                }

                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }

                ans = max(ans, r - l - 1);
            }
        }

        return ans;
    }
};
