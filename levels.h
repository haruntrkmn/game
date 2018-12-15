#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define LENGTH 30
#define HEIGHT 17

using namespace std;

void level1(int field[HEIGHT][LENGTH]){
    int i, j;
    for (j = 0; j < 10 ; j++){
        field[7][j] = 1;
    }

    for (j = 0; j < 13 ; j++){
        field[9][j] = 1;
    }

    for (i = 2; i < 8 ; i++){
        field[i][9] = 1;
    }

    for (i = 4; i < 9 ; i++){
        field[i][12] = 1;
    }

    for (j = 10; j < 27 ; j++){
        field[2][j] = 1;
    }

    for (j = 13; j < 25 ; j++){
        field[4][j] = 1;
    }

    for (i = 4; i < 9 ; i++){
        field[i][25] = 1;
    }

    for (i = 2; i < 8 ; i++){
        field[i][27] = 1;
    }

    for (j = 25; j < 29 ; j++){
        field[9][j] = 1;
    }

    field[7][28] = 1;
}


void level2(int field[HEIGHT][LENGTH]){
    field[1][2] = 1;
    field[1][18] = 1;
    field[1][21] = 1;
    field[1][22] = 1;
    field[1][23] = 1;
    field[1][24] = 1;
    field[1][25] = 1;
    field[1][26] = 1;

    field[2][2] = 1;
    field[2][4] = 1;
    field[2][5] = 1;
    field[2][6] = 1;
    field[2][7] = 1;
    field[2][8] = 1;
    field[2][9] = 1;
    field[2][10] = 1;
    field[2][11] = 1;
    field[2][12] = 1;
    field[2][13] = 1;
    field[2][14] = 1;
    field[2][15] = 1;
    field[2][16] = 1;
    field[2][18] = 1;
    field[2][21] = 1;
    field[2][26] = 1;

    field[3][2] = 1;
    field[3][16] = 1;
    field[3][18] = 1;
    field[3][19] = 1;
    field[3][20] = 1;
    field[3][21] = 1;
    field[3][23] = 1;
    field[3][24] = 1;
    field[3][25] = 1;
    field[3][26] = 1;
    field[3][27] = 1;
    field[3][28] = 1;

    field[4][2] = 1;
    field[4][3] = 1;
    field[4][4] = 1;
    field[4][5] = 1;
    field[4][6] = 1;
    field[4][8] = 1;
    field[4][9] = 1;
    field[4][10] = 1;
    field[4][11] = 1;
    field[4][12] = 1;
    field[4][14] = 1;
    field[4][15] = 1;
    field[4][16] = 1;
    field[4][25] = 1;

    field[5][6] = 1;
    field[5][8] = 1;
    field[5][14] = 1;
    field[5][16] = 1;
    field[5][17] = 1;
    field[5][18] = 1;
    field[5][19] = 1;
    field[5][21] = 1;
    field[5][22] = 1;
    field[5][23] = 1;
    field[5][26] = 1;
    field[5][27] = 1;
    field[5][28] = 1;

    field[6][1] = 1;
    field[6][2] = 1;
    field[6][3] = 1;
    field[6][4] = 1;
    field[6][6] = 1;
    field[6][8] = 1;
    field[6][10] = 1;
    field[6][11] = 1;
    field[6][13] = 1;
    field[6][14] = 1;
    field[6][19] = 1;
    field[6][20] = 1;
    field[6][21] = 1;
    field[6][23] = 1;
    field[6][24] = 1;
    field[6][26] = 1;

    field[7][4] = 1;
    field[7][6] = 1;
    field[7][8] = 1;
    field[7][9] = 1;
    field[7][10] = 1;
    field[7][11] = 1;
    field[7][15] = 1;
    field[7][16] = 1;
    field[7][17] = 1;
    field[7][18] = 1;
    field[7][19] = 1;
    field[7][21] = 1;
    field[7][24] = 1;
    field[7][25] = 1;
    field[7][26] = 1;

    field[8][2] = 1;
    field[8][4] = 1;
    field[8][6] = 1;
    field[8][11] = 1;
    field[8][21] = 1;
    field[8][22] = 1;
    field[8][23] = 1;
    field[8][24] = 1;
    field[8][25] = 1;
    field[8][26] = 1;

    field[9][2] = 1;
    field[9][4] = 1;
    field[9][5] = 1;
    field[9][6] = 1;
    field[9][9] = 1;
    field[9][10] = 1;
    field[9][11] = 1;
    field[9][12] = 1;
    field[9][13] = 1;
    field[9][14] = 1;
    field[9][15] = 1;
    field[9][16] = 1;
    field[9][18] = 1;
    field[9][19] = 1;
    field[9][20] = 1;
    field[9][21] = 1;
    field[9][22] = 1;
    field[9][28] = 1;

    field[10][2] = 1;
    field[10][10] = 1;
    field[10][16] = 1;
    field[10][24] = 1;
    field[10][25] = 1;
    field[10][26] = 1;
    field[10][27] = 1;
    field[10][28] = 1;

    field[11][2] = 1;
    field[11][3] = 1;
    field[11][4] = 1;
    field[11][5] = 1;
    field[11][7] = 1;
    field[11][8] = 1;
    field[11][10] = 1;
    field[11][12] = 1;
    field[11][13] = 1;
    field[11][14] = 1;
    field[11][16] = 1;
    field[11][17] = 1;
    field[11][18] = 1;
    field[11][21] = 1;
    field[11][22] = 1;
    field[11][24] = 1;

    field[12][5] = 1;
    field[12][7] = 1;
    field[12][8] = 1;
    field[12][9] = 1;
    field[12][10] = 1;
    field[12][12] = 1;
    field[12][14] = 1;
    field[12][16] = 1;
    field[12][17] = 1;
    field[12][18] = 1;
    field[12][21] = 1;
    field[12][23] = 1;
    field[12][24] = 1;
    field[12][27] = 1;

    field[13][1] = 1;
    field[13][2] = 1;
    field[13][5] = 1;
    field[13][12] = 1;
    field[13][14] = 1;
    field[13][16] = 1;
    field[13][17] = 1;
    field[13][18] = 1;
    field[13][19] = 1;
    field[13][20] = 1;
    field[13][21] = 1;
    field[13][23] = 1;
    field[13][25] = 1;
    field[13][26] = 1;
    field[13][27] = 1;

    field[14][2] = 1;
    field[14][3] = 1;
    field[14][5] = 1;
    field[14][6] = 1;
    field[14][7] = 1;
    field[14][8] = 1;
    field[14][9] = 1;
    field[14][10] = 1;
    field[14][11] = 1;
    field[14][12] = 1;
    field[14][14] = 1;
    field[14][23] = 1;

}

void level4(int field[HEIGHT][LENGTH]){
    field[2][3] = 1;
    field[2][4] = 1;
    field[2][5] = 1;
    field[2][6] = 1;
    field[2][7] = 1;
    field[2][8] = 1;
    field[2][9] = 1;
    field[2][10] = 1;
    field[2][12] = 1;
    field[2][13] = 1;
    field[2][14] = 1;
    field[2][15] = 1;
    field[2][16] = 1;
    field[2][17] = 1;
    field[2][18] = 1;
    field[2][19] = 1;

    field[3][3] = 1;
    field[3][19] = 1;

    field[4][3] = 1;
    field[4][5] = 1;
    field[4][6] = 1;
    field[4][7] = 1;
    field[4][8] = 1;
    field[4][9] = 1;
    field[4][10] = 1;
    field[4][11] = 1;
    field[4][12] = 1;
    field[4][13] = 1;
    field[4][14] = 1;
    field[4][15] = 1;
    field[4][16] = 1;
    field[4][17] = 1;
    field[4][19] = 1;

}


void level5(int field[HEIGHT][LENGTH]){
    field[3][3] = 1;
    field[3][4] = 1;
    field[3][5] = 1;
    field[3][6] = 1;
    field[3][7] = 1;
    field[3][8] = 1;
    field[3][9] = 1;
    field[3][10] = 1;
    field[3][12] = 1;
    field[3][13] = 1;
    field[3][14] = 1;
    field[3][15] = 1;
    field[3][16] = 1;
    field[3][17] = 1;
    field[3][18] = 1;
    field[3][19] = 1;

    field[4][3] = 1;
    field[4][19] = 1;

    field[5][3] = 1;
    field[5][5] = 1;
    field[5][6] = 1;
    field[5][7] = 1;
    field[5][8] = 1;
    field[5][9] = 1;
    field[5][10] = 1;
    field[5][11] = 1;
    field[5][12] = 1;
    field[5][13] = 1;
    field[5][14] = 1;
    field[5][15] = 1;
    field[5][16] = 1;
    field[5][17] = 1;
    field[5][19] = 1;

    field[6][5] = 1;
    field[6][20] = 1;
    field[6][21] = 1;
    field[6][22] = 1;

    field[7][1] = 1;
    field[7][2] = 1;
    field[7][3] = 1;
    field[7][5] = 1;
    field[7][17] = 1;
    field[7][19] = 1;
    field[7][23] = 1;
    field[7][24] = 1;
    field[7][25] = 1;
    field[7][26] = 1;
    field[7][27] = 1;
    field[7][28] = 1;

    field[8][5] = 1;
    field[8][17] = 1;

    field[9][1] = 1;
    field[9][2] = 1;
    field[9][3] = 1;
    field[9][4] = 1;
    field[9][5] = 1;
    field[9][17] = 1;
    field[9][18] = 1;
    field[9][19] = 1;
    field[9][23] = 1;
    field[9][24] = 1;
    field[9][25] = 1;
    field[9][26] = 1;
    field[9][27] = 1;
    field[9][28] = 1;

    field[10][20] = 1;
    field[10][21] = 1;
    field[10][22] = 1;

}
void level6(int field[HEIGHT][LENGTH]){
    field[1][24] = 1;
    field[2][24] = 1;
    field[4][24] = 1;
    field[4][25] = 1;
    field[4][26] = 1;
    field[4][27] = 1;
    field[4][28] = 1;


}

void level7(int field[HEIGHT][LENGTH]){
    field[1][2] = 1;
    field[1][4] = 1;
    field[1][9] = 1;
    field[1][20] = 1;
    field[1][25] = 1;
    field[1][27] = 1;

    field[2][2] = 1;
    field[2][4] = 1;
    field[2][5] = 1;
    field[2][6] = 1;
    field[2][7] = 1;
    field[2][8] = 1;
    field[2][9] = 1;
    field[2][20] = 1;
    field[2][21] = 1;
    field[2][22] = 1;
    field[2][23] = 1;
    field[2][24] = 1;
    field[2][25] = 1;
    field[2][27] = 1;

    field[3][2] = 1;
    field[3][4] = 1;
    field[3][25] = 1;
    field[3][27] = 1;

    field[13][2] = 1;
    field[13][4] = 1;
    field[13][25] = 1;
    field[13][27] = 1;

    field[14][2] = 1;
    field[14][4] = 1;
    field[14][5] = 1;
    field[14][6] = 1;
    field[14][7] = 1;
    field[14][8] = 1;
    field[14][9] = 1;
    field[14][20] = 1;
    field[14][21] = 1;
    field[14][22] = 1;
    field[14][23] = 1;
    field[14][24] = 1;
    field[14][25] = 1;
    field[14][27] = 1;

    field[15][2] = 1;
    field[15][4] = 1;
    field[15][9] = 1;
    field[15][20] = 1;
    field[15][25] = 1;
    field[15][27] = 1;

    field[8][29] = 1;

    field[1][3] = 6;
    field[15][3] = 6;
    field[1][8] = 6;
    field[15][8] = 6;
    field[1][21] = 6;
    field[15][21] = 6;
    field[1][26] = 6;
    field[15][26] = 6;
}

void level9(int field[HEIGHT][LENGTH]){
    field[1][17] = 6;
    field[1][10] = 1;
    field[2][10] = 1;
    field[3][10] = 1;
    field[3][11] = 1;
    field[3][12] = 1;
    field[3][13] = 1;
    field[3][14] = 1;
    field[3][15] = 1;
    field[3][16] = 1;
    field[3][17] = 1;
    field[3][18] = 1;
    field[3][19] = 1;
    field[3][20] = 1;
    field[3][21] = 1;
    field[3][22] = 1;

    field[8][29] = 1;
}






