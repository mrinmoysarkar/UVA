# Uses python3
def minmax(M,m,i,j,op):
    mi = float('inf')
    ma = float('-inf')
    a,b,c,d=0,0,0,0
    for k in range(i,j):
        if op[k]=='+':
            a = M[i][k] + M[k+1][j]
            b = M[i][k] + m[k+1][j]
            c = m[i][k] + M[k+1][j]
            d = m[i][k] + m[k+1][j]
        elif op[k]=='-':
            a = M[i][k] - M[k+1][j]
            b = M[i][k] - m[k+1][j]
            c = m[i][k] - M[k+1][j]
            d = m[i][k] - m[k+1][j]
        elif op[k]=='*':
            a = M[i][k] * M[k+1][j]
            b = M[i][k] * m[k+1][j]
            c = m[i][k] * M[k+1][j]
            d = m[i][k] * m[k+1][j]
        mi = min(mi,a,b,c,d)
        ma = max(ma,a,b,c,d)
    return (mi,ma)

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    #write your code here
    operations = []
    numbers = []
    num = ""
    for i in dataset:
        if i in ['+','-','*']:
            operations.append(i)
            num = num.strip()
            numbers.append(int(num))
            num = ""
        else:
            num+=i
    num = num.strip()
    numbers.append(int(num))
    n = len(numbers)
    M = [[float('-inf')]*n for _ in range(n)]
    m = [[float('inf')]*n for _ in range(n)]
    for i in range(n):
        M[i][i],m[i][i]=numbers[i],numbers[i]
    
    for s in range(1,n):
        for i in range(n-s):
            j = i+s
            m[i][j],M[i][j]=minmax(M,m,i,j,operations)
    
    return M[0][-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
