def printAnagrams (words):
    dictn = {}
    temp = []
    for word in words:
        if "".join(sorted(word)) in dictn:
            dictn["".join(sorted(word))].append(word)  # because sorted converts it to a list
        else:
            dictn["".join(sorted(word))]=[word]
    for i,j in dictn.items():
        print(j)
arr = ["cat", "dog", "tac", "god", "act"]       
printAnagrams(arr)
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
