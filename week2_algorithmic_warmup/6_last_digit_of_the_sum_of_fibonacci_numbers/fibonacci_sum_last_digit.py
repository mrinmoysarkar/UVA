# Uses python3
import sys

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    su      = 1
    md = [0,1]
    for _ in range(n - 1):
        previous, current = current, (previous + current)%10
        future = (previous + current)%10
        if current==0 and future==1:
            break
        su += current
        md.append(current)
    
    l = len(md)
    su = su*(n//l)+sum(md[:n%l+1])
    

    return su % 10

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum_naive(n))
    # print(fibonacci_sum_naive(100))
