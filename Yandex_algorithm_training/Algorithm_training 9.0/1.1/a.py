import sys


def main():
    #n = int(input())
    p,v = map(int, input().split())
    q,m = map(int, input().split())
    
    if(p > q):
        if(p - v > q + m):
            print(2*v + 2*m +2)
        elif(p-v<q-m):
            print(2*v + 1)
        elif(q+m > p+v):
            print(2*m + 1)
        else:
            print(m+p-q+v + 1)
            
    elif(p==q):
        if(v>m):
            print(2*v+1)
        else:
            print(2*m+1)
    elif(p<q):
        if(q - m > p + v):
            print(2*m + 2*v +2)
        elif(q-m<p-v):
            print(2*m +1)
        elif(p+v > q+m):
            print(2*v +1)
        else:
            print(v+q-p+m + 1)
    


if __name__ == '__main__':
    main()
