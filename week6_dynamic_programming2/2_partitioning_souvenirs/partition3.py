# Uses python3
import sys
import itertools

def partition3(A):
    # for c in itertools.product(range(3), repeat=len(A)):
    #     sums = [None] * 3
    #     for i in range(3):
    #         sums[i] = sum(A[k] for k in range(len(A)) if c[k] == i)

    #     if sums[0] == sums[1] and sums[1] == sums[2]:
    #         return 1

    n = len(A)
    W = sum(A)//3
    if W*3 != sum(A):
        return 0
    T = [[0]*(W+1) for _ in range(n+1)]
    for i in range(1,W+1):
        for j in range(1,n+1):
            if A[j-1]<=i:
                T[j][i] = max(T[j-1][i],A[j-1]+T[j-1][i-A[j-1]])
            else:
                T[j][i] = T[j-1][i]
    if T[-1][-1] != W:
        return 0
    # i = W
    # j = n
    # sol = []
    # while i != 0 and j != 0:
    #     if T[j][i] != T[j-1][i]:
    #         sol.append(A[j-1])
    #         i = i-A[j-1]
    #     j = j-1
    # for s in sol:
    #     A.remove(s)
    W = 2*W
    n = len(A)
    T = [[0]*(W+1) for _ in range(n+1)]
    for i in range(1,W+1):
        for j in range(1,n+1):
            if A[j-1]<=i:
                T[j][i] = max(T[j-1][i],A[j-1]+T[j-1][i-A[j-1]])
            else:
                T[j][i] = T[j-1][i]
    
    if T[-1][-1] != W:
        return 0
    return 1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3(A))

