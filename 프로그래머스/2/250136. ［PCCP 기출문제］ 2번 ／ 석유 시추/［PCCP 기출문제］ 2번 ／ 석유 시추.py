from collections import deque

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def isvalid(x, y, M, N):
    return 0 <= x < N and 0 <= y < M

def bfs(land, visited, x, y, M, N):
    queue = deque([(x, y)])
    visited[x][y] = True
    oil_size = 1
    cols = set([y])
    
    while queue:
        cx, cy = queue.popleft()
        for dx, dy in direction:
            nx, ny = cx + dx, cy + dy
            if isvalid(nx, ny, M, N) and not visited[nx][ny] and land[nx][ny] == 1:
                visited[nx][ny] = True
                queue.append((nx, ny))
                oil_size += 1
                cols.add(ny)
    
    return oil_size, cols

def solution(land):
    N = len(land)
    M = len(land[0])
    visited = [[False] * M for _ in range(N)]
    col_oil = [0] * M 

    for i in range(N):
        for j in range(M):
            if land[i][j] == 1 and not visited[i][j]:
                oil_size, cols = bfs(land, visited, i, j, M, N)
                for col in cols:
                    col_oil[col] += oil_size

    return max(col_oil)

