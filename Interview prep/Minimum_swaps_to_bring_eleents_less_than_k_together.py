def solution(array,k):    # all elements less than euqal k must be together so window size will be exual to no of elements less than equal k
    required_ele = 0
    for i in range(len(array)):
        if(array[i]<=k):
            required_ele= required_ele+1
    bad = 0
    for i in range(required_ele):
        if(array[i]>k):
            bad = bad+1

    min_bad = bad

    first_bad = 0
    last_bad = 0
    for  i in range(k,len(array)):#  hypo thetacally adding a  single next element to window  annd removing first most from window
        if(array[i-k]>k):
            first_bad = 1
        if array[i]>k:
            last_bad = 1

        bad = bad-first_bad+last_bad

        min_bad=min(bad,min_bad)
        first_bad = 0
        last_bad = 0
    return (k- min_bad)


solution([2, 1, 5, 6, 3],3)


            



            

    


