# Uses python3
import sys

def optimal_weight(W, w):
    # write your code here
    n = len(w)
    T = [[0]*(W+1) for _ in range(n+1)]
    for i in range(1,W+1):
    	for j in range(1,n+1):
    		if w[j-1]<=i:
    			T[j][i] = max(T[j-1][i],w[j-1]+T[j-1][i-w[j-1]])
    		else:
    			T[j][i] = T[j-1][i]
    return T[-1][-1]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
