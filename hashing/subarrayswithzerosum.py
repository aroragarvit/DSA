# subarrays with zero sum
def findSubArrays(arr,n,sum):
    
    dict={0:[-1]}
    for i in range(n):
        sum=sum+arr[i]
        if sum in dict:
           
            for j in dict[sum]:
                print("sum zero from {} to {}".format(j+1,i))
            dict[sum].append(i)
            continue
            
        
        else:
            dict[sum]=[i]
            continue
            
        
arr = [6, 3, -1, -3, 4, -2,
              2, 4, 6, -12, -7]
n = len(arr)
out = findSubArrays(arr, n,0)
     
