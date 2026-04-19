def main():
    n, m = map(int, input().split())

    if n < 0 or m < 0:
        print(-2)
        return

    events = [tuple(map(int, input().split())) for _ in range(n)]
    queries = [int(input()) for _ in range(m)]

    for q in queries:
        res = 0

        for l, r, x in events:
            if l <= q <= r:
                if (q - l) % 2 == 0:
                    res += x
                else:
                    res -= x

        print(res)


if __name__ == "__main__":
    main()