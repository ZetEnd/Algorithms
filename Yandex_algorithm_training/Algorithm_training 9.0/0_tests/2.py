import sys
from itertools import accumulate
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    if n == 1:
        sys.stdout.write("1\n")
        return
    
    # prefix sums
    prefix = list(accumulate(a))  # prefix[i] = sum(a[0..i])
    
    # last_break: last j (1-indexed compare) where sum(a[0..j-1]) <= a[j]
    # i.e., prefix[j-1] <= a[j]
    last_break = 0
    for j in range(1, n):
        if prefix[j-1] <= a[j]:
            last_break = j
    
    # first index where a[i] > a[0]
    first_can_start = n
    # a is sorted, use binary search equivalent
    lo, hi = 0, n
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] > a[0]:
            hi = mid
        else:
            lo = mid + 1
    first_can_start = lo
    
    first_winner = max(last_break, first_can_start)
    
    out = ['0'] * n
    for i in range(first_winner, n):
        out[i] = '1'
    
    sys.stdout.write(' '.join(out) + '\n')

solve()