
def soln(n):
    c = str(n)
    chrs = set(c)
    if '0' in chrs or len(c) != len(chrs):
        return False
    l = len(c)
    j = int(c[0])%l
    while c[j] in chrs:
        chrs.remove(c[j])
        j = (int(c[j])+j)%l
    if len(chrs)==0:
        return True
    return False

if __name__=="__main__":
    a,b=100,500
    noScroll = True
    for i in range(a,b+1):
        if soln(i):
            print(i)
            noScroll = False
    if noScroll:
        print(-1)
