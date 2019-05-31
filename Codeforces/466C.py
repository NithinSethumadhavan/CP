if __name__ == "__main__":
    n = int(input())
    arr = list(map(int,input().strip().split()))
    if sum(arr) % 3 != 0:
        print(0)
    else:
        t = sum(arr) / 3
        s = 0
        l = []
        r = []
        for i,x in enumerate(arr[:-1]):
            s += x
            if s == t:
                l.append(i)
            if s == 2 * t:
                r.append(i)
        i = 0
        j = 0
        ans = 0
        while i < len(l) and j < len(r):
            if l[i] >= r[j]:
                j = j + 1
            else:
                ans += len(r) - j
                i = i + 1
        print(ans)


