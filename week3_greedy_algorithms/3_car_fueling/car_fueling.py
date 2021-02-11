# python3
import sys


def compute_min_refills(distance, tank, stops):
    # write your code here
    i = 0
    n = len(stops)
    stops = [0]+stops
    output = 0
    stops.append(distance)
    last_fuel = 0


    while i<=n:
        last_fuel = i
        while i<=n and stops[i+1]-stops[last_fuel]<=tank:
            i += 1

        if i==last_fuel:
            return -1
        if i<=n:
            output += 1

    return output

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))   
    #print(compute_min_refills(500, 200, [100,200,300,400]))
