# Uses python3
import sys

def get_change(m):
    #write your code here
    m = m//10 + (m%10)//5 + (m%10)%5
    return m

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
    #print(get_change(19))
