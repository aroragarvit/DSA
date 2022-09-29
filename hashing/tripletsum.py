def foundThreeSum(arr,size,sum):
    for i in range(0,size-2):
        
        s=set()
        temp = sum-arr[i]
        for j in range(i+1,size):
            if temp-arr[j] in s:
                
                print("Triplet is", A[i],
                        ", ", A[j], ", ", temp-A[j])
                return True
            else :
                s.add(arr[j])
        
       
A = [1, 4, 45, 6, 10, 8]
sum = 22
arr_size = len(A)
foundThreeSum(A,arr_size,sum)
