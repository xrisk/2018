T = input()

# https://stackoverflow.com/questions/9829578/fast-way-of-counting-non-zero-bits-in-positive-integer
POPCOUNT_TABLE16 = [0] * 2 ** 16
for index in xrange(len(POPCOUNT_TABLE16)):
    POPCOUNT_TABLE16[index] = (index & 1) + POPCOUNT_TABLE16[index >> 1]


def popcnt(v):
    return POPCOUNT_TABLE16[v & 0xFFFF] + POPCOUNT_TABLE16[(v >> 16) & 0xFFFF]


for _ in xrange(T):

    # a = int(369)
    # b = int(428)
    # c = int(797)

    a, b, c = map(int, raw_input().split())
    ac = popcnt(a)
    bc = popcnt(b)

    # print(bin(a)[2:].zfill(len(bin(c)[1:])))
    # print(bin(b)[2:].zfill(len(bin(c)[1:])))

    # print("==============")

    # print(a, b, c)
    cnt = 0

    start = (1 << popcnt(a)) - 1

    while True:

        if popcnt(c - start) == bc:
            cnt += 1

            # print(start)
            # print(bin(start))

        t = (start | (start - 1)) + 1
        start = t | ((((t & -t) // (start & -start)) >> 1) - 1)

        if start >= c:
            break

    print(cnt)
