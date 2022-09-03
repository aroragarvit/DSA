def subsetSums(arr, l, r, sum=0):
 
   
    if l > r:
        print(sum)
        return sum
 
   
    subsetSums(arr, l + 1, r, sum + arr[l])
 
    
    subsetSums(arr, l + 1, r, sum)
 
 

arr = [1,6,11,5]
n = len(arr)
subsetSums(arr, 0, n - 1)