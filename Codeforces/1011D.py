from sys import stdout, exit

m, p = map(int, input().split())

seq = []

for i in range(p):
    print(1)
    stdout.flush()
    inp = int(input())
    if inp == 0:
        exit(0)
    else:
        seq.append((inp == 1))
        # print(seq[-1])
        # if seq[-1]:
        # 	print("truth")
        # else:
        # 	print("lie")

lo = 2
hi = m

cnt = 0

while lo <= hi:
    mid = (lo + hi) // 2
    # print(mid, lo, hi)
    print(mid)
    stdout.flush()
    inp = int(input())

    if not seq[cnt % len(seq)]:
        # print("Reversing because lie")
        inp = -inp

    cnt += 1

    if inp == 0:
        exit(0)
    elif inp == -1:
        hi = mid - 1
    else:
        lo = mid + 1
