arr1 = [11, 1, 13, 21, 3, 7]
arr2 = [11, 3, 7, 1]
m = len(arr1)
n = len(arr2)
s = set()
for i in range(m):
    s.add(arr1[i])
 
p = len(s)
for i in range(n):
    s.add(arr2[i])
 
if (len(s) == p):
    print("arr2[] is subset of arr1[] ")
 
else:
    print("arr2[] is not subset of arr1[] ")