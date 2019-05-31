
def findAB(string):
    ia = string.find("AB")
    if ia == -1:
        return False
    else:
        ib = string[ia+2:].find("BA")
        return ib != -1

def findBA(string):
    ib = string.find("BA")
    if ib == -1:
        return False
    else:
        ia = string[ib+2:].find("AB")
        return ia != -1
       

if __name__ == "__main__":
    s = input().strip()
    if findAB(s) or findBA(s):
        print("YES")
    else:
        print("NO")
