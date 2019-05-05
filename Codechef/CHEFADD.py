# T = input()

# https://stackoverflow.com/questions/9829578/fast-way-of-counting-non-zero-bits-in-positive-integer
POPCOUNT_TABLE16 = [0] * 2 ** 16
for index in xrange(len(POPCOUNT_TABLE16)):
    POPCOUNT_TABLE16[index] = (index & 1) + POPCOUNT_TABLE16[index >> 1]


def popcnt(v):
    return POPCOUNT_TABLE16[v & 0xFFFF] + POPCOUNT_TABLE16[(v >> 16) & 0xFFFF]


for _ in xrange(1):

    a = int(5e8)
    b = int(5e9)
    c = int(1e9)

    # a, b, c = map(int, raw_input().split())
    ac = bin(a).count("1")
    bc = bin(b).count("1")

    print(bin(a)[2:].zfill(len(bin(c)[1:])))
    print(bin(b)[2:].zfill(len(bin(c)[1:])))

    # print("==============")

    # print(a, b, c)
    cnt = 0
    for i in xrange(1, c):
        x = i
        y = c - i
        if popcnt(x) == ac and popcnt(y) == bc:
            # print(bin(x)[2:].zfill(len(bin(c)[2:])))
            # print(bin(y)[2:].zfill(len(bin(c)[2:])))
            # print(bin(c)[2:])
            # print(x, y)
            # print("------------")
            cnt += 1
    print(cnt)
