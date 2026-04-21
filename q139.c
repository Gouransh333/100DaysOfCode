Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.

class Solution {
   int n;
    int[,] dp;

    int solve(int mask, int pos, int[,] cost) {
        if (mask == (1 << n) - 1) {
            return cost[pos, 0];
        }

        if (dp[mask, pos] != -1) return dp[mask, pos];

        int ans = int.MaxValue;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = cost[pos, city] + solve(mask | (1 << city), city, cost);
                if (newAns < ans) ans = newAns;
            }
        }

        return dp[mask, pos] = ans;
    }

   
    public int tsp(int[,] cost) {
         n = cost.GetLength(0);
        dp = new int[1 << n, n];

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                dp[i, j] = -1;
            }
        }

        return solve(1, 0, cost);
    }
        
   }
