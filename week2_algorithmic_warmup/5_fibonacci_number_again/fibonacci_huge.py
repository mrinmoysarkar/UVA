# Uses python3
import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    md = [0,1]
    for _ in range(n - 1):
        previous, current = current, (previous + current)%m
        future = (previous + current)%m
        if current==0 and future==1:
            break
        md.append(current%m)

    return md[n%len(md)]

if __name__ == '__main__':
    input = sys.stdin.read();
    n, m = map(int, input.split())
    print(get_fibonacci_huge_naive(n, m))
    # print(get_fibonacci_huge_naive(2816213588,239))
