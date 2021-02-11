# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n
    n0=0
    n1=1
    for i in range(1,n):
    	n2 = n0+n1
    	n0 = n1
    	n1 = n2

    return n2

n = int(input())
print(calc_fib(n))
