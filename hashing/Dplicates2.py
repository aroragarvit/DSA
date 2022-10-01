# I an array contains duplicate within k distance 
# Hint : check within k  distance then remove elements above  k from set then check
def checkDuplicatesWithinK(arr,n,k):
    s=[]
    for i in range(k+1):
        s.append(arr[i])
        print (s)
        
    for i in range(n-k):
        if i in s:
            return True
        else:
            s.append(arr[k+i])
            s.remove (arr[i])
            
arr = [1, 2, 3, 1, 4, 5]
n = len(arr)
if (checkDuplicatesWithinK(arr, n, 3)):
    print("Yes")
else:
    print("No")

