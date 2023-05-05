def solution(array, n):
    dictionary = {0: [-1]}

    sum = 0

    for i in range(n):
        sum += array[i]
        if sum in dictionary:
            dictionary[sum].append(i)
        else:
            dictionary[sum] = [i]

    for key in dictionary:
        if len(dictionary[key]) >= 2:
            for j in range(len(dictionary[key])-1):
                print("Subarray with sum 0 from {} to {}".format(dictionary[key][j]+1, dictionary[key][j+1]))

solution([2, -3, 1], 3)
