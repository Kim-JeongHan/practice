N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


percentages = [
    [(1, 1, 1), (-1, 1, 1), (1, 0, 7), (-1, 0, 7),
     (2, 0, 2), (-2, 0, 2), (1, -1, 10), (-1, -1, 10),
     (0, -2, 5)],
    [(-1, 1, 1), (-1, -1, 1), (0, 1, 7), (0, -1, 7),
     (0, 2, 2), (0, -2, 2), (1, 1, 10), (1, -1, 10),
     (2, 0, 5)],
    [(-1, -1, 1), (1, -1, 1), (-1, 0, 7), (1, 0, 7),
     (-2, 0, 2), (2, 0, 2), (-1, 1, 10), (1, 1, 10),
     (0, 2, 5)],
    [(1, -1, 1), (1, 1, 1), (0, -1, 7), (0, 1, 7),
     (0, -2, 2), (0, 2, 2), (-1, -1, 10), (-1, 1, 10),
     (-2, 0, 5)],
]


global answer
answer = 0

def print_A():
    string =""
    for x in A:
        for num in x:
            string += f"{num} "
        string += "\n"
    print(string)

def move():
    x = y = N//2
    dir =0
    length = 1
    while True:
        for _ in range(2):
            for _ in range(length):
                x += dx[dir]
                y += dy[dir]
                if x<=0 and y<=0:
                    spread(0,0, dir)
                    return
                spread(x,y, dir)
            dir += 1
            dir = dir % 4
        length +=1


def spread(x,y, d):
    global answer
    current = A[x][y]
    alpha = current
    for xx, yy, value in percentages[d]:
        if x+xx < 0 or x+xx >= N or y+yy < 0 or y+yy >= N:
            answer += (A[x][y]*value) //100
            alpha -= (A[x][y]*value) // 100
        else:
            A[x+xx][y+yy] += (A[x][y]*value) //100
            alpha -= (A[x][y]*value) //100
    if x+dx[d] < 0 or x+dx[d] >= N or y+dy[d] < 0 or y+dy[d] >= N:
        answer += alpha
    else:
        A[x+dx[d]][y+dy[d]] += alpha

    A[x][y] = 0 

move()

print(answer)