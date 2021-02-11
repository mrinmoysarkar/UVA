#Uses python3

import sys

def lcs3(a, b, c):
    #write your code here
    m = len(a)
    n = len(b)
    o = len(c)
    T =[[[0]*(m+1) for _ in range(n+1)] for _ in range(o+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            for k in range(1,o+1):
                cost = 1 if a[i-1]==b[j-1]==c[k-1] else 0
                T[k][j][i]= max(T[k-1][j][i],
                                T[k][j-1][i],
                                T[k][j][i-1],
                                T[k-1][j-1][i-1]+cost) 
    # print(T)
    return T[o][n][m]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))
