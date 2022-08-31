count = 0
def subsetsum(arr,n,i,sum,v):
    
    if sum==0:
        
        global count
        count += 1
        print(v)
        return v
    if i==n or sum<0:
        
        return 
    
    subsetsum(arr,n,i+1,sum-arr[i],v+[arr[i]])                          
    
    subsetsum(arr,n,i+1,sum,v)

arr = [10,15,20,25,30,25,50,40,30]
sum = 50
n = len(arr)
v=[]

subsetsum(arr,n,0,sum,v)
print(count)