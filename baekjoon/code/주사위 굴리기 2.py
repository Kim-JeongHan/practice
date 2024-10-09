from collections import deque

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

dice = [0]*6  # [위, 아래, 왼쪽, 오른쪽, 앞, 뒤]
dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = 1, 6, 4, 3, 5, 2

# east, south, west,north(clock-wise)
dx = [0,1, 0,-1]
dy = [1,0,-1,0]

#  2       2
#4 1 3   6 4 1
#  5       5
#  6       3

# 주사위
def roll_dice(dir):
    a,b,c,d,e,f =  dice
    if dir == 0: #east
        dice[0], dice[1], dice[2], dice[3] = c, d, b, a
    elif  dir == 2: #west
        dice[0], dice[1], dice[2], dice[3] = d, c, a, b
    elif dir == 1: #south
        dice[0], dice[1], dice[4], dice[5] = f, e, a, b
    else:
        dice[0], dice[1], dice[4], dice[5] = e, f, b, a

def print_dice():
    string=""
    string += f"  {dice[5]}  \n"
    string += f"{dice[2]} {dice[0]} {dice[3]}\n"
    string += f"  {dice[4]}  \n"
    string += f"  {dice[1]}  \n"
    print(string)

global answer
answer = 0


def bfs(x,y):
    global answer
    visited = [[False]*M for _ in range(N)]
    queue = deque()
    queue.append((x,y))
    answer += A[x][y]
    visited[x][y] = True
    while queue:
        cx, cy = queue.popleft()
        for i in range(4):
            tx = cx + dx[i]
            ty = cy + dy[i]
            if 0<= tx < N and 0 <= ty < M:
                if visited[tx][ty]:
                    continue
                else:
                    visited[tx][ty] = True
                    if A[tx][ty] == A[x][y]:
                        queue.append((tx,ty))
                        answer += A[tx][ty]






def game():
    x =y = 0
    direction = 0
    x += dx[direction]
    y += dy[direction]
    roll_dice(direction)
    bfs(x,y)
    for _ in range(K-1):
        if dice[1] > A[x][y]:
            direction += 1
        elif dice[1] < A[x][y]:
            direction -= 1
        direction = (direction + 4) % 4
        if 0 <= x+dx[direction] < N and 0 <= y + dy[direction] < M:
            pass
        else:
            direction +=2
            direction = (direction + 4) % 4
        x += dx[direction]
        y += dy[direction]
        roll_dice(direction)
        bfs(x,y)


# bfs(1,2)
game()
print(answer)
