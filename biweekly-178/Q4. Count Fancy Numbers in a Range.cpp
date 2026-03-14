/* (upsolved)
 Q4. Count Fancy Numbers in a Range
 DIGIT DP + precomputation of sum of digits

 So, first of all it makes sense to precompute the sum of digits and store it in a bool array.

 dp states ==> (position , tight , started, previous digit , trend , sum of digits) 
 ==> position is basically index of the digit we are currently at
 ==> tight tells us whether we are bounded to a particular digit or can go till 9
 ==> started is to check whether we have started forming the number or not
 ==> previous digit is to check and compare with current digit (d) and decide ntrend 
 ==> trend -> 0 , two digits till now, yet to decide whether increasing or decreasing
           -> 1 , increasing
           -> 2 , decreasing
           -> 3 , not a fancy number
 ==> sum of digits we have taken rn , will be used to check whether the sum is fancy or not  
 
 A. base condition -> 
    if not started then 0
    if started and trend is not 3 || sum if fancy then 1 
    else 0 
 
  B. memoize , check limit 

  C. if not started and digit is 0 then skip 
    else if not started by d != 0 , then start the number and set the prev as d 
    check ntrend by compariing d and prev 

TC: O(1)
SC: O(1)
*/

class Solution {
public:
    vector<int> digits;
    int n;
    bool sum_str[200];
    // dp params
    // pos, tight , start, previous, (up,down,wrong) , sum
    long long dp[20][2][2][11][4][200];

    void computesum() {
        for (int i = 0; i <= 171; i++) {
            sum_str[i] = solve(i);
        }
    }

    bool solve(int x) {
        string s = to_string(x);
        bool flag = true;
        bool flagg = true;

        if (s.size() == 1) {
            return true;
        }

        for (int i = 1; i < s.size(); i++) {
            if (s[i] <= s[i - 1])
                flag = false;
            if (s[i] >= s[i - 1])
                flagg = false;
        }
        // ya to increasing ho ya decreasing
        return flag || flagg;
    }

    long long digitdp(int pos, int tight, int start, int prev, int trend,
                      int sum) {
        if (pos == n) {
            if (!start)
                return 0;
            if (trend != 3 || sum_str[sum])
                return 1;
            return 0;
        }
        if (dp[pos][tight][start][prev][trend][sum] != -1) {
            return dp[pos][tight][start][prev][trend][sum];
        }

        int limit = tight ? digits[pos] : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            int ntight = (tight && d == digits[pos]);

            if (!start && d == 0) {
                ans += digitdp(pos + 1, ntight, 0, 10, 0, 0);
            } else {
                if (!start) {
                    ans += digitdp(pos + 1, ntight, 1, d, 0, d);
                } else {
                    int ntrend = 3;

                    if (trend == 3) {
                        ntrend = 3;
                    } 
                    else if (trend == 0) {
                        if (d > prev) ntrend = 1;
                        else if (d < prev) ntrend = 2;
                    } 
                    else if (trend == 1) {
                        if (d > prev) ntrend = 1;
                    } 
                    else {
                        if (d < prev) ntrend = 2;
                    }

                    ans += digitdp(pos + 1, ntight, 1, d, ntrend, sum + d);
                }
            }
        }
        return dp[pos][tight][start][prev][trend][sum] = ans;
    }

    long long helper(long long x) {
        if (x <= 0)
            return 0;
        digits.clear();
        string s = to_string(x);

        for (auto c : s) {
            digits.push_back(c - '0');
        }

        n = digits.size();

        memset(dp, -1, sizeof(dp));
        // pos , tight, start, prev, trend, sum
        return digitdp(0, 1, 0, 10, 0, 0);
    }

    long long countFancy(long long l, long long r) {
        computesum();
        return helper(r) - helper(l - 1);
    }
};