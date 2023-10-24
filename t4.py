def count_deletion_plans(arr, k):
    n = len(arr)
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    mod = 10**9 + 7
    for i in range(n + 1):
        dp[i][O] = 1
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])% mod
    count = 0
    for i in range(1, n + 1):
        count = (count + dp[i][k]) % mod
    return count
arr = [1, 2, 3, 4, 5]
k =2
result = count_deletion_plans(arr, k)
result