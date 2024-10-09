
A = [list(map(int, input().split())) for _ in range(4)]
maps = []
for line in A:
    fishes=[]
    fish = tuple()
    for i, value in enumerate(line):
        fish += (value,)
        if i%2==1:
            fishes.append(fish)
            fish = tuple()
    maps.append(fishes)


# dire = [0,1,2,3,4,5,6,7] #up, counter-clock

dx = [-1,-1, 0, 1, 1, 1, 0, -1]
dy = [0, -1,-1, -1, 0, 1, 1, 1]

def map_print():
    string = ""
    for x in range(4):
        for y in range(4):
            string += f"{maps[x][y][0]} "
        string += "\n"
    print(string)

map_print()

def fish_move(s_x=0, s_y=0):
    fish_number = 1
    while True:
        map_print()
        for i in range(16):
            x = i // 4
            y = i % 4
            if f_map[x][y] == fish_number:                 # check fish
                d = d_map[x][y]-1
                while True:
                    if 0 <= x + dx[d] < 4 and 0 <= y + dy[d] < 4 and (s_x != x + dx[d] or s_y != y + dy[d]): # no shark, no wall
                        break
                    else:
                        d= (d+9)%8
                temp = (f_map[x][y], d_map[x][y])
                f_map[x][y], d_map[x][y] = f_map[x + dx[d]][y + dy[d]], d_map[x + dx[d]][y + dy[d]]
                f_map[x + dx[d]][y + dy[d]], d_map[x + dx[d]][y + dy[d]] = temp
                break
        fish_number +=1
        if fish_number > 16:
            break
#
#
# # map_print()
# f_map[0][0] = 0
# d_map[0][0] = 0
# fish_move()
# map_print()


# def shark_move():
#     pass
