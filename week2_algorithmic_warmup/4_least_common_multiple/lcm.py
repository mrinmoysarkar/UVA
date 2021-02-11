# Uses python3
import sys

def lcm_naive(a, b):
    # for l in range(1, a*b + 1):
    #     if l % a == 0 and l % b == 0:
    #         return l
    if a<=b:
        c = b
        while b%a != 0:
            b = b+c
        return b
    else:
        c = a
        while a%b != 0:
            a = a+c
        return a

if __name__ == '__main__':
    input = sys.stdin.read()
    a, b = map(int, input.split())
    print(lcm_naive(a, b))

