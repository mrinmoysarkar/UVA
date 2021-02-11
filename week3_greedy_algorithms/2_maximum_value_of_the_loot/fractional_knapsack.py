# Uses python3
import sys

def func(a):
    return a[2]
    
def get_optimal_value(capacity, weights, values):
    value = 0.
    # write your code here
    a = [values[i]/weights[i] for i in range(len(values))]
    data = zip(values,weights,a)
    data = sorted(data,key=func,reverse=True)
    for d in data:
        if capacity==0:
            return value
        a = min(capacity,d[1])
        value += a*d[0]/d[1]
        capacity -= a
    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
