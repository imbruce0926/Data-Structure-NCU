#include <iostream>
#include <vector>

using namespace std;

    struct element{
        short int row;
        short int col;
        short int dir;
    };
    typedef struct element element;
    
    struct offsets{
        int vert;
        int horiz;
    };
    typedef struct offsets offsets;

    const int MAX_STACK_SIZE = 300;
    element stack[MAX_STACK_SIZE];

    void getmaze(vector<vector<int>> &, int, int);
    void push(int *, element);
    element pop(int *);

int main(){

    int maze_row, maze_col;
    cin >> maze_row >> maze_col;

    vector<vector<int>> maze(maze_row + 2, vector<int>(maze_col + 2));
    getmaze(maze, maze_row, maze_col);          /* get maze and enclosed by 1 */ 
    vector<vector<int>> mark(maze);             /* copy maze to mark */ 

    int row, col, dir, next_row, next_col;
    int top = 0, found = 0;
    int EXIT_ROW = maze_row, EXIT_COL = maze_col;

    element position;
    offsets move[4];

    mark[1][1] = 1;                             /* must step on (1,1) */ 
    stack[0] = {.row = 1, .col = 1, .dir = 1};  /* because first step of while loop is to pop the stack*/ 
    move[0] = {.vert = -1, .horiz = 0};
    move[1] = {.vert = 0, .horiz = 1};
    move[2] = {.vert = 1, .horiz = 0};
    move[3] = {.vert = 0, .horiz = -1};         /* set the direction */ 


    while (top > -1 && found == 0){

        position = pop(&top);
        row = position.row; 
        col = position.col; 
        dir = position.dir;

        while(dir < 4 && found == 0){

            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;

            if (next_row == EXIT_ROW && next_col == EXIT_COL){
                found = 1;

                position.row = row; 
                position.col = col; 

                push(&top, position);
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
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

    if (found == 1){
        for(int i = 0; i <= top; i++)
            cout << "(" << stack[i].row-1 << "," << stack[i].col-1 << ")" << " ";
        cout << "(" << EXIT_ROW-1 << "," << EXIT_COL-1 << ")" << " ";
    }
    else
        cout << "Can't reach the exit!" ;
}

void push (int *top, element added){
    stack[++(*top)] = added;
}

element pop (int *top){
    return stack[(*top)--];
}

void getmaze (vector<vector<int>> &maze, int row, int col){
    for (int i = 1; i < row+1; i++)
        for (int j = 1; j < col+1; j++)
                cin >> maze[i][j];          /* get maze */

    for (int j = 0; j < row+2; j++){
        maze[j][0] = 1;
        maze[j][col+1] = 1;
    }
    for (int k = 0; k < col+2; k++){
        maze[0][k] = 1;
        maze[row+1][k] = 1;
    }                                       /* enclose maze by 1 */ 
                                           
}

