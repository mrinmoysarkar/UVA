# Uses python3
import sys

def get_change(m):
    #write your code here
    w = [1,3,4]
    T = [float('inf')]*(m+1)
    T[0]=0
    for u in range(1,m+1):
    	for i in range(3):
    		if w[i]<=u:
    			T[u] = min(T[u],T[u-w[i]]+1)
    # print(T)

    return T[m]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
