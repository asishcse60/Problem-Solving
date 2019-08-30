long long countPerfect(int n)
  {

    vector< ll > dp(n + 1, 0);

    dp[2] = 1;

    for(int k = 4; k <= n; k += 2) {
      for(int a = 3; a < k - 2; a += 2) {
        dp[k] += dp[a - 1] * dp[k - (a - 1 + 2)];
      }
      dp[k] += dp[k - 2] * 2;
    }

    //DUMP(dp);
    
    return dp[n];	
  }