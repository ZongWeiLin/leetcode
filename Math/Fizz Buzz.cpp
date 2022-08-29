#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string_length 10

//這題就單純取餘數後判斷//
//分成%3、%5、%5&&%3這三種case//
char ** fizzBuzz(int n, int* returnSize)
{
    char **str=(char**)calloc(n,sizeof(char*));

    for(int i=0;i<n;i++)
    {
        str[i]=(char*)calloc(max_string_length,sizeof(char));
    }
    
    char text[20];

    for(int i=1;i<=n;i++)
    {
        if(i%3==0)
        {
            if(i%3==0&&i%5==0)
            {
                strcpy(str[i-1],"FizzBuzz");
            }
            else 
            strcpy(str[i-1],"Fizz");
        }
        else if(i%5==0)
        {
            if(i%3==0&&i%5==0)
            {
                strcpy(str[i-1],"FizzBuzz");
            }
            else
            strcpy(str[i-1],"Buzz");
        }
        else
        {
            //用sprintf把int的值轉成字串//
            sprintf(text,"%d",i);
            //把字串的值copy到對應的陣列//
            strcpy(str[i-1],text);
        }
    }

    return str;
}

int main(void)
{   
    char arr[3][10]={{"hi"},{"2"},{""}};

    char str[10];
    sprintf(str,"%d",2);
    strcpy(arr[2],str);
    printf("%s\n",arr[2]);

    system("pause");
    return 0;
}