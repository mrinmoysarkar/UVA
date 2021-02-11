# Uses python3
import sys




def partition3(a, l, r):
    #write your code here
    x=a[l]
    j=l
    for i in range(l+1,r+1):
        if a[i][0]<=x[0]:
            j+=1
            a[i],a[j]=a[j],a[i]

    a[l],a[j]=a[j],a[l]
    k=j
    while k>=0 and a[k]==x:
        k-=1

    xx = a[k+1:j+1]
    xx.sort(key=lambda x:x[1])
    a[k+1:j+1]=xx
    return k+1,j


def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    m1,m2=partition3(a,l,r)
    randomized_quick_sort(a,l,m1-1)
    randomized_quick_sort(a,m2+1,r)

def merge_sort(a,b,l,r):
    if l>=r-1:
        return
    m = (l+r)//2
    merge_sort(a,b,l,m)
    merge_sort(a,b,m,r)

    for i in range(l,r):
        b[i] = a[i]
    bl = l
    br = m
    for i in range(l,r):
        if bl<m and br<r:
            if b[bl][0]<b[br][0] or (b[bl][0]==b[br][0] and b[bl][1]<b[br][1]):
                a[i] = b[bl]
                bl += 1
            else:
                a[i] = b[br]
                br += 1
        elif bl<m:
            a[i]=b[bl]
            bl += 1
        elif br<r:
            a[i]=b[br]
            br += 1

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    # #write your code here
    # d = {}
    # for i,j in zip(starts,ends):
    #     for k in range(i,j+1):
    #         d[k]=1+d.get(k,0)
    # for i in range(len(points)):
    #     cnt[i] = d.get(points[i],0)
    a=[]
    n = max(len(starts),len(points))
    for i in range(n):
        if i<len(starts):
            a.append((starts[i],-1))
            a.append((ends[i],1))
        if i<len(points):
            a.append((points[i],0,i))
    # randomized_quick_sort(a,0,len(a)-1)
    # print(a)
    b=[0]*len(a)
    merge_sort(a,b,0,len(a))
    # print(a)
    # d = {}
    l=0
    for i in a:
        if i[1]==0:
            # d[i[0]]=l
            cnt[i[2]] = l
        elif i[1]==-1:
            l+=1
        else:
            l-=1
    # for i,p in enumerate(points):
    #     cnt[i]=d[p]

    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    # cnt = naive_count_segments(starts, ends, points)
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
