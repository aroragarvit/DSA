# Check if a an array is subset of another 
def isSubset(arr1,arr2,m,n):
    s=set()
    for i in arr1:
        s.add(i)
    print(s)
    for i in arr2:
        if i in s:
            
            continue
        else:
            return False
    return True



arr1 = [11,  13, 21, 3, 7]
arr2 = [11, 3, 7, 1]
 
m = len(arr1)
n = len(arr2)
 
if (isSubset(arr1,arr2, m, n)):
    print("arr2[] is subset of arr1[] ")
else:
    print("arr2[] is not a subset of arr1[] ")