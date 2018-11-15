from sys import exit
debug = False

T = input()
for _ in range(T):
	N, M, X, Y = map(int, raw_input().split())

	sol = 0
	for i in range(1, N + 1):
		for j in range(1, M + 1):

	# for i in range(3, 100):
		# for j in range(1, 10):

			if i == X and j == Y:
				continue

			tmp = 0

			left = 0
			right = 0
			top = 0
			bottom = 0
			main = 0
			cross = 0

			# count left cases
			if X == i and Y < j:
				# count only till the right of the king
				left += max(0, j - Y - 1	)
			else:
				left += max(0, j - 1)

			if debug:
				print("left", left)

			# count right cases
			if X == i and Y > j:
				# count only till left of the king
				# print("here")
				right += max(0, Y - j - 1)
			else:
				right += max(M - j, 0)

			if debug:
				print("right", right)

			# count top cases
			if Y == j and X < i:
				# count only till below king
				top += max(0, i - X - 1)
			else:
				top += max(0, i - 1)

			if debug:
				print("top", top)

			# count bottom cases
			if Y == j and X > i:
				bottom += max(0, X - i - 1)
			else:
				bottom += max(0, N - i)

			if debug:
				print("bottom", bottom)

			# count leading diagonal
			diff_x = N - i
			diff_y = M - j
			tmp_x = i + min(diff_x, diff_y)
			tmp_y = j + min(diff_x, diff_y)
			main = min(tmp_x, tmp_y)
		    # subtract one square for the queen itself
			main -= 1 # subtract one square for the king



			if X - i == Y - j:
				# king lies on the same diagonal
				if X < i:
					main -= min(X, Y)
				else:
					main -= tmp_x - X + 1


			if debug:
				print("leading", main)

			# count off diagonal
			# diff_x = i - 1
			# diff_y = M - j
			# tmp_x = i - min(diff_x, diff_y)
			# tmp_y = j + min(diff_x, diff_y)
			# rek = min(tmp_x, tmp_y) - 1
			# # if tmp_x == 1:
			# # 	off = tmp_x + tmp_y - 1
			# # else:
			# off = (tmp_x - rek) + (tmp_y - rek) - 1
			# print("tmp", tmp_x, tmp_y)
			# print("row count", off)

			# off -= 1
			# dcnt = off
			
			# if X - i == - (Y - j):
			# 	if X < i:
			# 		off -= X
			# 	else:
			# 		off -= dcnt - i + 1
			# if debug:
			# 	print("off", off)

			diff_x = i - 1
			diff_y = M - j
			tmp_x = i - min(diff_x, diff_y)
			tmp_y = j + min(diff_x, diff_y)

			diff2_x = N - tmp_x
			diff2_y = tmp_y - 1
			tmp2_x = tmp_x + min(diff2_x, diff2_y)
			tmp2_y = tmp_y - min(diff2_x, diff2_y)

			rowcnt = tmp2_x - tmp_x + 1
			# print("rowcnt", rowcnt)
			off = rowcnt - 1
			if X - i == -(Y - j):
				if X < i:
					off -= X - tmp_x + 1
				else:
					off -= tmp2_x - X + 1


			if debug:
				print("off", off)


			# print("rowcnt", rowcnt)

			tmp = 0
			
			tmp += max(0, top)
			tmp += max(0, bottom)
			tmp += max(0, left)
			tmp += max(0, right)
			tmp += max(0, main)
			tmp += max(0, off)

			tmp += 2 # subtract one square for queen
			
			# print(i, j, "safe", N * M - tmp)
			if debug:
				exit(0)
			num_sq = N * M
			sol += num_sq - tmp
	print(sol)


