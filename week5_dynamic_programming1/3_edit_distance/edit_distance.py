# Uses python3
def edit_distance(s, t):
    #write your code here
    m = len(s)
    n = len(t)
    T =[[0]*(m+1) for _ in range(n+1)]
    for i in range(max(m,n)+1):
    	if i<=m:
    		T[0][i]=i
    	if i<=n:
    		T[i][0]=i
    for i in range(1,m+1):
    	for j in range(1,n+1):
    		cost = 0 if s[i-1]==t[j-1] else 1
    		T[j][i]=min(T[j-1][i]+1,#insertion
    					T[j][i-1]+1,#deletion
    					T[j-1][i-1]+cost)# equal or replace 
    return T[n][m]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
