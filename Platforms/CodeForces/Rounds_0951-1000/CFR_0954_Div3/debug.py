def solve():
    n, m = map(int, input().split())
    s = list(input())
    ind = list(map(int, input().split()))
    c = list(input())
    will_be_replaced = set(ind)
    c.sort()
    index = 0
    for i in will_be_replaced:
        s[i-1] = c[index]
        index += 1
    return "".join(s)


t = int(input())
for _ in range(t):
    print(solve())
