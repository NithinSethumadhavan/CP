

if __name__ == "__main__":
    n = int(input().strip())
    ip = []
    for i in range(n):
        ip.append(tuple(map(int,input().strip().split())))
    ip.sort()
    i = 0
    for l,f in ip:
        if f >= i:
            i = f
        else :
            i = l
    print(i)

""" Time Taken
Reading + Algo : ~ 7 min
Coding         : ~ 7 min <- *
Debugging      : 0
"""
