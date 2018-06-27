from operator import itemgetter

R = lambda: map(int, input().split())
t = int(input())
n, q = R()
a = list(R())
b = sorted(enumerate(a), key=itemgetter(1))
d = dict((x, (i, j)) for j, (i, x) in enumerate(b))
for _ in range(q):
    x = int(input())
    i, j = d[x]
    l, h = 0, n - 1
    a1 = a2 = b1 = b2 = 0
    while True:
        m = (l + h) // 2
        if m == i:
            break
        if m < i:
            l = m + 1
            a1 += 1
            if a[m] > x:
                a2 += 1
        else:
            h = m - 1
            b1 += 1
            if a[m] < x:
                b2 += 1
    if a1 > j or b1 > n - 1 - j:
        print(-1)
    else:
        print(max(a2, b2))