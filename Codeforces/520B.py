import queue


def foo(n,m):
    if n >= m:
        return n-m
    else :
        mx = 20002
        dist = [-1]*mx
        dist[n] = 0
        q = queue.Queue(maxsize = mx)
        q.put(n)
        while not q.empty():
            f = q.get()
            g = f*2
            if g < mx and dist[g] == -1 :
                dist[g] = dist[f] + 1
                q.put(g)
                if g == m:
                    break
            l = f-1
            if l > 0 and dist[l] == -1:
                dist[l] = dist[f] + 1
                q.put(l)
                if l == m:
                    break
        return dist[m]



if __name__ == "__main__":
    n,m = map(int,input().strip().split())
    result = foo(n,m)
    print(result)
