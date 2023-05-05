def number_of_subarray_k_sum(array,size,k):
    dictt = {k:[-1]}
    current_sum = 0
    count = 0
    for i in range(size):
        current_sum = current_sum+array[i]
        
        if (current_sum - k  in dictt):
            count = count+ len(dictt[current_sum-k])

        if(current_sum not in dictt):
            dictt[current_sum ]=[i]

        if (current_sum  in dictt):
            dictt[current_sum].append(i)

    return count
no_of_subarrays = number_of_subarray_k_sum([10, 2, -2, -20, 10],5,-10)
print(no_of_subarrays)








