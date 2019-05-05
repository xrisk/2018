n = int(input())

d = [100, 20, 10, 5, 1]
cnt = 0

for i in d:
    if i <= n:
        t = n // i
        cnt += t
        n -= i * t

print(cnt)
