# 0-1 Knapsack using dp 
def knapsack(val,wt,W,n):
    k=[[0 for z in range(W+1)] for x in range (n+1)]
    print(k)
    for i in range(n+1):
        for w in range(W+1):
            if i==0 or w==0:
                k[i][w]=0
            elif wt[i-1]>w: 
                k[i][w]=k[i-1][w]
                
            else:
                k[i][w]=max(k[i-1][w],val[i-1]
                          + k[i-1][w-wt[i-1]])
    return k
val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
K = knapsack(val, wt, W , n)
print(K)
result = K[n][W]
print(result)
lis=[]
w=W
 # 3,2,1,0 
for i in range(n,0,-1): 
    if result <=0:
        break
    if result == K[1-1][w]:    # not taken so subtract i and rest w capacity remains unchanged 
        continue
    
    if result !=K[i-1][w]:
        lis.append(val[i-1])
        result=result-val[i-1]
        w=w-wt[i-1]
    
print(lis)
        
        
        
     
    
