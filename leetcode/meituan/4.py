import sys

# 读入数据
n, x, y = map(int, input().split())
prices = []
for i in range(n):
    price, discount = map(int, input().split())
    prices.append((price, discount))

# 动态规划求解
dp = [[sys.maxsize] * (x + 1) for _ in range(y + 1)]
dp[0][0] = 0
for i in range(n):
    price, discount = prices[i]
    for j in range(y, 0, -1):
        for k in range(x, price - 1, -1):
            dp[j][k] = min(dp[j][k], dp[j - 1][k - price] + discount)

# 找到最优解
max_num = 0
min_cost = sys.maxsize
for j in range(y + 1):
    for k in range(x + 1):
        if dp[j][k] < sys.maxsize:
            num = j
            cost = dp[j][k]
            if num > max_num:
                max_num = num
                min_cost = cost
            elif num == max_num and cost < min_cost:
                min_cost = cost

# 输出结果
print(max_num, min_cost)
