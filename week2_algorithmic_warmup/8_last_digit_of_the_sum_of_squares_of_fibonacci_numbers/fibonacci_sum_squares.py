# Uses python3
from sys import stdin

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    # previous = 0
    # current  = 1
    # sum      = 1

    # for _ in range(n - 1):
    #     previous, current = current, previous + current
    #     sum += current * current

    # return sum % 10
    previous = 0
    current  = 1
    md = [0,1]
    for _ in range(n):
        previous, current = current, (previous + current)%10
        future = (previous + current)%10
        if current==0 and future==1:
            break
        md.append(current)
    l1 = n%len(md)
    l2 = (n+1)%len(md)
    d1 = md[l1]
    d2 = md[l2]
    return (d1*d2)%10

if __name__ == '__main__':
    n = int(stdin.read())
    print(fibonacci_sum_squares_naive(n))
    # print(fibonacci_sum_squares_naive(239))
