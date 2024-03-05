    vector<vector<int>> mark(maze);

    offsets move[4];
    move[0] = {.horiz = 0, .vert = -1};
    move[1] = {.horiz = 1, .vert = 0};
    move[2] = {.horiz = 0, .vert = 1};
    move[3] = {.horiz = -1, .vert = 0};

    element position;
    int top = 0, found = 0;
    int row, col, dir, next_row, next_col, EXIT_ROW = maze_row, EXIT_COL = maze_col;
    mark[1][1] = 1;
    stack[0] = {.row = 1, .col = 1, .dir = 0};

    while(top > -1 && found == 0){
        position = pop(&top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while(dir < 4 && found == 0) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if(next_row == EXIT_ROW && next_col == EXIT_COL) {
                position.row = next_row;
                position.col = next_col;
                found = 1;
            }
            else if(!maze[next_row][next_col] && !mark[next_row][next_col]){
                mark[next_row][next_col] = 1;
                position.row = next_row;
                position.col = next_col;
                position.dir = ++dir;
                push(&top, position);
            }
            else
                ++dir;
        }
    } 

    if(found){
        for(int i = 0; i <= top; i++) {
            cout << "(" << stack[i].row << "," << stack[i].col << ") ";
        }
    }
    else
        cout << "Can't reach the exit!" ;