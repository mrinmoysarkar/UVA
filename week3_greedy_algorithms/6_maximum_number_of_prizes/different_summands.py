# Uses python3
import sys

def optimal_summands(n):
    summands = []
    #write your code here
    n1=n
    for i in range(1,n1):
        if i < n-i:
            summands.append(i)
            n = n-i
        if i>=n:
            break
    summands.append(n)
    return summands

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
