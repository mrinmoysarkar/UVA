# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    points = []
    #write your code here
    segments = sorted(segments, key=lambda x:x.start)
    current = -1
    for s in segments:
        if current==-1:
            current = s.end
            continue
        if s.start<=current<=s.end:
            continue
        elif current<s.start:
            points.append(current)
            current = s.end
        elif current>s.end:
            current=s.end
    points.append(current)
    
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    print(*points)
