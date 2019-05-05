MOD = int(1e9 + 7)


def binomial(n, k):
    """
    A fast way to calculate binomial coefficients by Andrew Dalke.
    See http://stackoverflow.com/questions/3025162/statistics-combinations-in-python
    """
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return (ntok // ktok) % MOD
    else:
        return 0


T = int(input())
for _ in range(T):
    n, k = [int(x) for x in input().split()]
    s = 0
    for r in range(1, k + 1):
        t = pow(2, r, MOD) * binomial(k - 1, r - 1) * binomial(n - k + 1, r)
        t %= MOD
        s += t
        s %= MOD
    print(s)
