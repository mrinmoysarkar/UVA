# Uses python3
import sys

def optimal_sequence(n):
    if n<2:
        return [n]
    T = [float('inf')]*(n+1)
    prev = [-1]*(n+1)
    T[0] = 0
    T[1] = 0
    w = [1,2,3]
    for i in range(2,n+1):
        for j in w:
            if j<=i and j == 1:
                idx = i-j
                if T[i]>T[idx]+1:
                    T[i] = T[idx]+1
                    prev[i] = idx
            elif i%j==0:
                idx = i//j
                if T[i] > T[idx]+1:
                    T[i] = T[idx]+1
                    prev[i] = idx
    # print(T)
    # print(prev)
    sequence = []
    sequence.append(n)
    i = -1
    while prev[i] != 1:
        sequence.append(prev[i])
        i = prev[i]
    sequence.append(1)
    sequence = sequence[::-1]
    return sequence

    # sequence = []
    # while n >= 1:
    #     sequence.append(n)
    #     if n % 3 == 0:
    #         n = n // 3
    #     elif n % 2 == 0:
    #         n = n // 2
    #     else:
    #         n = n - 1
    # return reversed(sequence)

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
