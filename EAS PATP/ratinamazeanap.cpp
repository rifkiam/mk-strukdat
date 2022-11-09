#include <stdio.h>
const int n = 10;
int c = 999999;
int shortest[n][n];
int flag_first = 1;
int first_found[n][n];

void cpy_2d(int arr[][n], int arr2[][n]){ //to make another array
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            arr[i][j] = arr2[i][j];
        }
    }
}

void printsol(int sol_arr[n][n]){ //print solution array
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(sol_arr[i][j] == 3){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solveMaze(int arr[n][n], int row, int col, int count){ //recursive to find the path
    if (row<0 || row>n-1 || col<0 || col>n-1){
        return;
    }
    if (arr[row][col] == 0){ //0 is the wall
        return;
    }
    if(arr[row][col] == 3){ //3 is the sign for each path that had taken 
        return;
    }
    if(arr[row][col] == 2){ //2 is the destination
        arr[row][col] = 3;
        if(flag_first == 1){
            cpy_2d(first_found, arr);   
            flag_first = 0;
        }
        if(c > count){
            cpy_2d(shortest, arr);
            c = count;
        }
    }
    int sol_arr[n][n];
    cpy_2d(sol_arr, arr);
    sol_arr[row][col] = 3;
    solveMaze(sol_arr, row + 1, col, count + 1);
    solveMaze(sol_arr, row-1, col, count + 1);
    solveMaze(sol_arr, row, col+1, count + 1);
    solveMaze(sol_arr, row, col-1, count + 1);
}

int main(){
    int arr[10][10] = {{0, 0, 1, 1, 0, 0, 1, 1, 1, 1}, 
                       {0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
                       {1, 1, 0, 1, 1, 0, 1, 0, 1, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
                       {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {0, 1, 0, 0, 1, 1, 0, 0, 0, 1},
                       {1, 1, 1, 0, 0, 1, 0, 1, 1, 2}, 
                       {1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                       {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                       {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}};
    //number 2 in the arr is the destination and row 2 col 0 is the starting point
    solveMaze(arr, 2, 0, 1);
    printsol(shortest);
    printsol(first_found);
}