# Uses python3
import sys

def fibonacci_partial_sum_naive(from_, to):
    # sum = 0

    # current = 0
    # next  = 1

    # for i in range(to + 1):
    #     if i >= from_:
    #         sum += current

    #     current, next = next, current + next

    previous = 0
    current  = 1
    su      = 1
    md = [0,1]
    for _ in range(to - 1):
        previous, current = current, (previous + current)%10
        future = (previous + current)%10
        if current==0 and future==1:
            break
        su += current
        md.append(current)
    
    l = len(md)
    l1 = from_%l
    l2 = to%l
    n = to-from_ - (l-l1)-l2
    su = sum(md[l1:])%10 + (su*(n//l))%10 + sum(md[:l2+1])%10
    

    return su % 10

    return sum % 10


if __name__ == '__main__':
    input = sys.stdin.read();
    from_, to = map(int, input.split())
    print(fibonacci_partial_sum_naive(from_, to))
    # print(fibonacci_partial_sum_naive(10, 200))

