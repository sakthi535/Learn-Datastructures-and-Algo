import math

mod = 998244353
def calc(n , r): 
    num = math.factorial(n)
    den = math.factorial(r)*math.factorial(n-r)
    return (num/den)
    
dp=[]
t = int(input())
for i in range(70):
    dp.append([0,0])
dp[2][0] = 1 
dp[2][1]=  0 
for i in range(4,70,2): 
    temp = i//2
    half = math.factorial(i-1)//(math.factorial(temp-1)*math.factorial(i-temp))
    dp[i][0] = dp[i-2][1]+half
    dp[i][1]=calc(i,i//2)-dp[i][0]-1

for test in range(0 , t) : 
    n = int(input())
    print(int(dp[n][0])%mod,int(dp[n][1])%mod,1)