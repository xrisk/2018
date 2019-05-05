n = int(input())
w = set([])

l = input().split()

for word in l:
    root = set(word)
    root = list(root)
    root.sort()
    root = "".join(root)
    w.add(root)

print(len(w))
