def get_p_n(k, m, x):
    p = (k - 1) // (x * m) + 1
    n = ((k - 1) % (x * m)) // x + 1
    return p, n


def main():
    k1, m, k2, p2, n2 = map(int, input().split())

    p_set = set()
    n_set = set()

    found = False

    for i in range(1, 10**6 + 1):
        p, n = get_p_n(k2, m, i)

        if p == p2 and n == n2:
            found = True

            p1, n1 = get_p_n(k1, m, i)
            p_set.add(p1)
            n_set.add(n1)

    if not found:
        print(-1, -1)
        return

    p1 = p_set.pop() if len(p_set) == 1 else 0
    n1 = n_set.pop() if len(n_set) == 1 else 0

    print(p1, n1)


if __name__ == "__main__":
    main()