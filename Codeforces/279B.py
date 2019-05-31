


if __name__ == "__main__":
    n,l = map(int,input().strip().split())
    a = list(map(int,input().strip().split()))
    i,j = -1, 0
    s,ans = 0,0
    while j != n:
        s = s + a[j]
        while s > l:
            i = i + 1
            s = s - a[i]
        if j - i > ans :
            ans = j - i
        j = j + 1
    print(ans)


