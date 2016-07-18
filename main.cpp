#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;


void insertBoard();
void printBoard(u_int32_t board[20][20], u_int32_t dimention);
void findCrossroad(u_int32_t board[20][20], u_int32_t dimention);

int main()
{

    insertBoard();

    return 0;
}

void insertBoard(){
    u_int32_t dimention;
    u_int32_t board[20][20];
    cout << "Insert dimentions for the board(one integer)" << endl;
    cin >> dimention;

    for(int i = 0; i < dimention; i++){
        for(int j = dimention-1; j >= 0; j--){
            board[i][j] = 0;
        }
    }
    findCrossroad(board, dimention);
}


void findCrossroad(u_int32_t board[20][20], u_int32_t dimention){
    u_int32_t firstDimention, secondDimention;
    u_int32_t newDimention;
    cout << "Enter coordinates:" << endl;
    cin >> firstDimention >> secondDimention;

    board[firstDimention][secondDimention] = 1;

    if(firstDimention == secondDimention){        //Main diagonal
        for(int i = 0; i < dimention; i++){
            for(int j = dimention -1; j >= 0; j--){
               if(i == j){
                  board[i][j] = 1;
               }
            }
        }

        if(firstDimention % 2 == 0){
            newDimention = 2*firstDimention;
        }
        else{
             newDimention = 2*firstDimention + 1;
        }


        for(int i = 0; i < newDimention; i++){
            for(int j = newDimention -1; j >= 0; j--){
               if(j == newDimention - (i +1))
                  board[i][j] = 1;
            }
        }


    }

    else if(secondDimention == dimention - (firstDimention + 1)){        //Secondary diagonal
        for(int i = 0; i < dimention; i++){
            for(int j = dimention -1; j >= 0; j--){
               if(j == dimention - (i +1))
                  board[i][j] = 1;
            }
        }

        if(firstDimention % 2 == 0){
            newDimention = 2*firstDimention;
        }
        else{
             newDimention = 2*firstDimention + 1;
        }

         for(int i = 0; i < newDimention; i++){
             for(int j = newDimention -1; j >= 0; j--){
                if(i == j){
                   board[i][j] = 1;
                }
             }
         }

    }

    else{
        if(firstDimention % 2 == 0){
            newDimention = 2*firstDimention;
        }
     else{
     newDimention = 2*firstDimention + 1;
     }
        for(int i = 0; i < newDimention; i++){
            for(int j = newDimention -1; j >= 0; j--){
               if(i == j && j == newDimention - (i +1)){
                  board[i][j] = 1;
               }
            }
        }
    }



    printBoard(board, dimention);
}

void printBoard(u_int32_t board[20][20], u_int32_t dimention){
    u_int32_t outputD = 0;
    for(int i = 0; i < dimention; i++){
        for(int j = dimention -1; j >= 0; j--){
            if(board[i][j] == 1)
            {
                outputD += pow(2, j);
            }

        }
        cout << outputD << '\n';
    }
}

