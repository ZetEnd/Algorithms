import sys


def main():
    n, m = map(int, input().split())

    setka = [list(input().strip()) for _ in range(n)]

    count = 0

    for i in range(n):
        for j in range(m):
            if setka[i][j] == '.':
                if j+1<m and setka[i][j+1] == '.':
                    count+=1

                if i+1 < n and setka[i+1][j] == '.':
                    count+=1
    
    print(count)

if __name__ == '__main__':
    main()
