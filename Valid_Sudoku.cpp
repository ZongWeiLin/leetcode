#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// bool isValidSudoku(char (*board)[9], int boardSize, int* boardColSize)
// {
//     //用來記錄是否有出現的array//
//     int rec_col[9][9]={0};
//     int rec_row[9]={0};
//     int rec_box[9][9]={0};
    
//     int temp;
//     int index;
//     for(int i=0;i<9;i++)
//     {
//         for(int j=0;j<9;j++)
//         {
          
//           if(board[i][j]!='.')
//           {  
//             temp=board[i][j]-'1';
//             index=(i/3)*3+(j/3); 

//             if(rec_col[i][temp]||rec_row[temp]||rec_box[index][temp])
//             {
//                 return false;
//             }
        
//             rec_col[i][temp]=rec_row[temp]=rec_box[index][temp]=1;
//           }
        
//         }

//         for(int k=0;k<9;k++)
//         {
//             rec_row[k]=0;
//         }
//     }

//     return true;
// }


bool isValidSudoku(char (*board)[9], int boardSize, int* boardColSize)
{
     for(int i;i<9;i++)
     {
        int row_rec[9]={0};
        int col_rec[9]={0};
        int blo_rec[9]={0};
        for(int j=0;j<9;j++)
        {
            //開三個hash table 分別記錄row,col,block//
            char row_elem=board[i][j];
            char col_elem=board[j][i];
            char blo_elem=board[3*(i/3)+j/3][3*(i%3)+j%3];

            if(row_elem!='.')
            {
                if (row_rec[row_elem-'1'])
                return false;

                row_rec[row_elem-'1']=1;
            }

            if(col_elem!='.')
            {
                if (col_rec[col_elem-'1'])
                return false;
                
                col_rec[col_elem-'1']=1;
            }

            if(blo_elem!='.')
            {
                if (blo_rec[blo_elem-'1'])
                return false;
                
                blo_rec[blo_elem-'1']=1;
            }
        }

        //將對應hash table清0//
        memset(row_rec,0,sizeof(int)*9);
        memset(col_rec,0,sizeof(int)*9);
        memset(blo_rec,0,sizeof(int)*9);
     }

     return true;
}


int main(void)
{
    char borad[9][9]={
 {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','.','9'}};



    int val=isValidSudoku(borad,9,NULL);

    printf("%d\n",val);

    system("pause");
    return 0;
}

