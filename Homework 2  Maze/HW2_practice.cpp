#include <iostream>
#include <vector>

using namespace std;

    struct offsets {
        int horiz;
        int vert;
    };
    typedef struct offsets offsets;
    
    struct element {
        int row;
        int col;
        int dir;
    };
    typedef struct element element;

    const int MAX_STACK_SIZE = 300;
    element stack[MAX_STACK_SIZE];

    void push(int *, element);
    element pop(int *);
    void getmaze(vector<vector<int>> &, int, int);

int main() {
    int maze_row, maze_col;

    cin >> maze_row >> maze_col;
    vector<vector<int>> maze(maze_row + 2, vector<int>(maze_col + 2));
    getmaze(maze, maze_row, maze_col);
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
                position.row = row;
                position.col = col;
                push(&top, position);
                found = 1;
            }
            else if(!maze[next_row][next_col] && !mark[next_row][next_col]){
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(&top, position);
                row = next_row;
                col = next_col;
                dir = 0;
            }
            else
                ++dir;
        }
    } 

    if(found){
        for(int i = 0; i <= top; i++) {
            cout << "(" << stack[i].row - 1 << "," << stack[i].col - 1 << ") ";
        }
        cout << "(" << EXIT_ROW - 1 << "," << EXIT_COL - 1 << ") ";
    }
    else
        cout << "Can't reach the exit!" ;


}
void push(int *top, element position) {
    stack[++(*top)] = position;
}
element pop(int *top) {
    return stack[(*top)--];
}
void getmaze(vector<vector<int>> &maze, int row, int col) {
    for(int i = 1; i <= row; i++ ) 
        for(int j = 1; j <= col; j++ ) 
            cin >> maze[i][j];

    for(int i = 0; i < col + 2; i++ ) {
        maze[0][i] = 1;
        maze[row + 1][i] = 1;
    }

    for(int i = 0; i < row + 2; i++ ) {
        maze[i][0] = 1;
        maze[i][col + 1] = 1;
    }
}