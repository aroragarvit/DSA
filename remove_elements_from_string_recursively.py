


def remove(s,string_temp,last_found):
    
    if s[0]==s[1] or s[0]==last_found:
        last_found =s[0]
        print(s[1:])
        remove(s[1:],string_temp,last_found)
    
    if len(s) == 1 and s[0]==last_found:
        return string_temp
    
    if len(s) == 1:
        return string_temp+last_found
    
    elif s[0] != s[1]:
        string_temp.append(s[0])
        remove(s[1:],string_temp,last_found)
        
def remove_from_all(st):
    
    if returned=prev_returned:
        return
    
    else:
        st = remove(st,"","")
    
    
    
     
remove("aabb","","")


