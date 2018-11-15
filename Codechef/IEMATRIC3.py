foo = []
from itertools import product
for a in range(51):
	for b in range(a + 1, 51):
		for c in range(b + 1, 51):
			for d in range(c + 1, 51):
				term = 2**a + 2**b + 2**c + 2**d
				foo.append(term)
foo.sort()
print(foo[80])