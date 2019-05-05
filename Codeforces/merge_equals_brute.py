n = int(input())
ls = [int(_) for _ in input().split()]

out = [-1] * n


while True:
    m = min(ls)
    if m == -1:
        break
    if ls.count(m) >= 2:
        one = ls.index(m)
        two = ls.index(m, start=(one + 1))
        ls[one] = -1
        ls[two] = 2 * m
        out[one] = -1
        out[two] = 2 * m
    else:
        out[ls.index(m)] = m
        ls[ls.index(m)] = -1
