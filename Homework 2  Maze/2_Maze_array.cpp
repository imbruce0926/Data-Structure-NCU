#include <iostream>
#include <vector>
using namespace std;


typedef struct{
    short int row;
    short int col;
    short int dir;
}element;


void push(int &, element, element []);
element pop(int &, element []);

int main(){

    int maze_row, maze_col;
    cin >> maze_row >> maze_col;
    int maze[maze_row+2][maze_col+2]={}, mark[maze_row+2][maze_col+2]={};

    for (int i = 1; i < maze_row+1; i++){
        for (int j = 1; j < maze_col+1; j++){
                cin >> maze[i][j];
        }
    } // get maze
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < maze_row+2; j++){
            maze[j][0] = 1;
            maze[j][maze_col+1] = 1;
        }
        for (int k = 0; k < maze_col+2; k++){
            maze[0][k] = 1;
            maze[maze_row+1][k] = 1;
        }
    } // enclose maze by 1

    for(int i=0; i<maze_row+2; i++){
        for(int j=0; j<maze_col+2; j++)
            mark[i][j]=maze[i][j];
    }

    mark[1][1] = 1;


    const int MAX_STACK_SIZE=300;
    int top = 0, row, col, dir, next_row, next_col, found = 0;
    int EXIT_ROW = maze_row, EXIT_COL = maze_col;

    element stack[MAX_STACK_SIZE];
    stack[0] = {.row = 1, .col = 1, .dir = 1};
    element position;

    typedef struct{
        int vert;
        int horiz;
    }offsets;
    offsets move[4];
    move[0] = {.vert = -1, .horiz = 0};
    move[1] = {.vert = 0, .horiz = 1};
    move[2] = {.vert = 1, .horiz = 0};
    move[3] = {.vert = 0, .horiz = -1};


    while (top > -1 && found == 0){
        position = pop(top, stack);
        row = position.row; col = position.col; dir = position.dir;
        while(dir < 4 && found == 0){
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
            if (next_row == EXIT_ROW && next_col == EXIT_COL){
                found = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(top, position, stack);
            }
            else if (!maze[next_row][next_col] && !mark[next_row][next_col]){
                mark[next_row][next_col] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(top, position, stack);
                row = next_row; col = next_col; dir = 0;
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

void push (int &top, element added, element stack[]){
    top++;
    stack[top]=added;
}

element pop (int &top, element stack[]){
    int temp_top=top--;
    return stack[temp_top];
}
