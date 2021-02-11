#Uses python3

import sys

def lcs2(s, t):
    #write your code here
    m = len(s)
    n = len(t)
    T =[[0]*(m+1) for _ in range(n+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            cost = 1 if s[i-1]==t[j-1] else 0
            T[j][i]=max(T[j-1][i],#insertion
                        T[j][i-1],#deletion
                        T[j-1][i-1]+cost)# equal or replace 
    # print(T)
    return T[n][m]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
