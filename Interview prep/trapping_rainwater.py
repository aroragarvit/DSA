def trapping_rainwater(array,size):
    result =0
    left_max = []
    max_element = 0
    for i in range(size):
        if array[i]> max_element:
            max_element = array[i]
        left_max.append(max_element)
       

    right_max = []
    max_element2 = 0
    for i in reversed(range(size)):
        # Checks for array[i] > max_element2 instead of array[i] > max_element
        if array[i] > max_element2:
            max_element2 = array[i]
        # Appends max_element2 instead of max_element
        right_max.append(max_element2)
  

    for i in range(size):
        min_element = min(left_max[i],right_max[size-i-1])
        result = result + min_element-array[i]
    
    print (result)

trapping_rainwater([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],12)



    
    
        

        

       

      
