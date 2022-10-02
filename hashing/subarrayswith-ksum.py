# subarrays with zero sum
def findSubArrays(arr,n,sum,k):
    
    dict={0:[-1]}
    for i in range(n):
        sum=sum+arr[i]
        if sum-(k) in dict:
           
            for j in dict[sum-k]:  # all indexes
                print("sum zero from {} to {}".format(j+1,i))
            
            if sum in dict:
                dict[sum].append(i)
            else:
                dict[sum]=[i]
            
            
           
           
            
        
        else:
            if sum in dict:
                dict[sum].append(i)
            else:
                dict[sum]=[i]
            
            continue
            
        
arr = [10, 2, -2, -20, 10]
              
n = len(arr)
out = findSubArrays(arr, n,0,k= -10)
     
