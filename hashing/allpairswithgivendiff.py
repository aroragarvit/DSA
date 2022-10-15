def count(arr,n,k):
    count=0
    hash={}
    
    for i in arr:
        if i in hash:
            hash[i]=hash[i]+1 
        else:
            hash[i]=1 
        
    
    for i in arr:
        if hash[i]>=1:
            element=i-k
            element2=i+k
            
            if element in hash and hash[element]>=1:
                count=count+1
                
                hash[element]=hash[element]-1
                hash[i]=hash[i]-1
                print(i ,element)
            elif element2 in hash and  hash[element2]>=1:
                count=count+1
                hash[element2]=hash[element2]-1
                hash[i]=hash[i]-1
                print(i, element2)
    print(count)
count([1,2,3,4,5,6,6,0],8,4)
