# removing duplicates from positive array
def removeduplicates(l,temp):
    if len(l)==0:
        return l
    
    elif l[0]==temp:
        return removeduplicates(l[1:],l[0])

    elif l[0]!=temp:
        return ( [l[0]] + removeduplicates(l[1:],l[0]) )

print(removeduplicates([1,1,2],-1))