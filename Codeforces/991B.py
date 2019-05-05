n = int(input())
m = [int(x) for x in input().split()]
m.sort()

avg = sum(m) / n
cnt = 0

while avg < 4.5:
    m[0] = 5
    cnt += 1
    m.sort()
    avg = sum(m) / n

print(cnt)
