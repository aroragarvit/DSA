# Print all pairs with given sum 

def printPairs(arr,length,sum):
    dic={}
    for i in range(0,length):
        temp = sum-arr[i]
        
        
        if arr[i] in dic:
            print(arr[i],temp )
        else:
            dic[temp]=arr[i]
        
    print(dic)    
A = [ 1, 5, 7, -1, 5 ]
n = 6
printPairs(A, len(A), n)