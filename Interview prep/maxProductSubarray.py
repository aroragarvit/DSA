def solution(array, length):
    if all(val == 0 for val in array):
        return 0
        
    maxi = array[0]
    max_pos_until = 1
    max_negative_until = 1
    
    for i in range(length):
        if array[i]>0:
            max_pos_until =max_pos_until* array[i]
            max_negative_until =max_negative_until * array[i]
            maxi = max(max_pos_until , maxi)

        elif array[i]<0:
            temp = max_pos_until
            max_pos_until = max(max_negative_until * array[i], 1)  #for example in beginning we are taking max_negative_until as 1 so max_pos_until will become negative if not compared
            max_negative_until = temp * array[i]
            maxi = max(max_pos_until , maxi)

        else:
            max_pos_until = 1
            max_negative_until = 1

    return maxi


print(solution([-1, -3, -10, 0, 60],5))
        
        