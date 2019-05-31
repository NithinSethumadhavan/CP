


def foo(ch):
    d = { 'N':(0,-1),
          'S':(0,1),
          'W':(-1,0),
          'E':(1,0)
        }
    return d[ch]

if __name__ == "__main__":
    T = int(input().strip())
    for t in range(T):
        n,r,c,sc,sr = map(int,input().strip().split())
        instr = list(map(foo, list(input().strip())))
        i,j = 0,0
        v = {(0,0)}
        for a,b in instr:
            while True:
                i = i + a
                j = j + b
                if (i,j) not in v:
                    v.add((i,j))
                    break
        print("Case #%d: %d %d" % (t+1,sc+j,sr+i))


