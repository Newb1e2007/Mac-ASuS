
MAX_NUM = 100000

n, m = map(int, input().split())
a = list(map(int, input().split()))
x = list(map(int, input().split()))
print(a, ' ', x)

num_a = [0] * (MAX_NUM + 1)
for ai in a:
    num_a[ai] += 1

fp = [0] * (MAX_NUM + 1)    # fp[xi] - result for xi
prev = [0] * (MAX_NUM + 1)      # previous position (from 1) where Equal to xi
Leq = [0] * (MAX_NUM + 1)           # current number of Left Equal to xi
Rne = [n - num for num in num_a]    # current number of Right Not-Equal to xi

pos = 0
for ai in a:
    Leq[ai] += 1
    Rne[ai] -= pos - prev[ai]
    pos += 1
    prev[ai] = pos
    curr_fp = Leq[ai] * Rne[ai]
    if fp[ai] < curr_fp:
        fp[ai] = curr_fp

print(' '.join(str(fp[xi]) for xi in x))

