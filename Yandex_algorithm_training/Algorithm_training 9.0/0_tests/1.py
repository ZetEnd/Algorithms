import sys


def main():
    """
    Пример ввода и вывода числа n, где -10^9 < n < 10^9:
    n = int(input())
    print(n)
    """
    pass


if __name__ == '__main__':
    main()
import sys
input = sys.stdin.readline

s = input().strip()
result = []
i = len(s) - 1

while i >= 0:
    if s[i] == '#':
        # Two digits before '#' form number 10-26
        num = int(s[i-2:i])
        result.append(chr(ord('a') + num - 1))
        i -= 3
    else:
        # Single digit 1-9
        num = int(s[i])
        result.append(chr(ord('a') + num - 1))
        i -= 1

print(''.join(reversed(result)))