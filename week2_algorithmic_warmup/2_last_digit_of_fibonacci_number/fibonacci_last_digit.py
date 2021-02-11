# Uses python3
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    n0=0
    n1=1
    for i in range(1,n):
        n2 = (n0+n1)%10
        n0 = n1
        n1 = n2

    return n2

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(get_fibonacci_last_digit_naive(n))
