#Uses python3

import sys

def comp(a,b):
    return int(a+b)>int(b+a)


def largest_number(a):
    #write your code here
    
    #n = len(a)
    #for i in range(n):
    #    for j in range(n-i-1):
    #        if not comp(a[j],a[j+1]):
    #            a[j],a[j+1]=a[j+1],a[j]
    res=""
    while a:
        max_digit = a[0]
        for i in a:
            if comp(i,max_digit):
                max_digit=i
        res += max_digit
        a.remove(max_digit)
    #res="".join(a)
    return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(largest_number(a))
    
