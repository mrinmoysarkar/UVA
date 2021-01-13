

def soln(grid):
    m = len(grid)
    n = len(grid[0])
    q = []
    v = []
    p = {}
    for i in range(m):
        for j in range(n):
            if grid[i][j]=='s':
                q.append((i,j))
    nei = [(0,1),(0,-1),(1,0),(-1,0)]
    pe = False
    while q:
        cur = q[0]
        v.append(cur)
        del q[0]
        if grid[cur[0]][cur[1]]=='B':
            pe=True
            break
        for ne in nei:
            nxt = (cur[0]+ne[0],cur[1]+ne[1])
            if nxt not in v and nxt not in q and 0<=nxt[0]<m and 0<=nxt[1]<n and grid[nxt[0]][nxt[1]] != '#':
                q.append(nxt)
                p[nxt] = cur
    if pe:
        while True:
            cur = p[cur]
            if grid[cur[0]][cur[1]] == 's':
                break
            grid[cur[0]][cur[1]]='*'
        return grid
    else:
        return -1

if __name__=="__main__":
    grid = [["#","#","#","#","#","#"],
        ["#","s","#","#","#","#"],
        ["#",".",".",".",".","#"],
        ["#",".","#","#",".","#"],
        ["#",".","#","B","#","#"],
        ["#","#","#","#","#","#"]]
    grid = soln(grid)
    if grid == -1:
        print(-1)
    else:
        for g in grid:
            print("".join(g))
