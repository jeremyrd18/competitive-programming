n, m, x = map(int, input().split())

matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

ops = []
for _ in range(x):
    ops.append(input())

for op in ops:
    if op == "_":
        matrix = matrix[::-1]
    elif op == "|":
        matrix = [row[::-1] for row in matrix]
    elif op == "90":
        matrix = [list(row) for row in zip(*matrix[::-1])]
    elif op == "180":
        matrix = [row[::-1] for row in matrix[::-1]]
    elif op == "270":
        matrix = [list(row) for row in zip(*matrix)][::-1]
        matrix = [list(row) for row in matrix]

for row in matrix:
    print(*(row))