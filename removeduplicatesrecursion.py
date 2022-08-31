# removing duplicates from positive array
def removeduplicates(l,temp):
    if len(l)==0:
        return l
    
    elif l[0] in temp:
        return removeduplicates(l[1:],temp)

    elif l[0] not in temp:
        temp.append(l[0])
        return ( [l[0]] + removeduplicates(l[1:],temp) )

print(removeduplicates([1,1,2,1],[-1]))