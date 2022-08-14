#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize)
{
    int *ret=(int*)malloc((digitsSize+1)*sizeof(int));
    int i;
    int value;
    //р程计1//
    digits[digitsSize-1]+=1;
    
    //パ程┕玡Τ9碞砞Θ盢玡计1//
    for(i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]>9&&i!=0)//磷underflow┮硂柑璶砞竚i!=0э糶玡
        {
            digits[i]=0;
            digits[i-1]+=1;
        }
        else
            break;
    }
    
    //程硂琌耞程玡琌Τ秈//
    int j=0;
    if(digits[0]>9)
    {
            ret[0]=digits[0]/10;
            ret[1]=digits[0]%10;
            j+=2;
    }
    else
    {
        ret[0]=digits[0];
        j++;
    }

    //パ程蔼и竒矪瞶奔惠璶р逞计穐秈ㄓㄤ緇皚竚//
    i=1;
    while(i<digitsSize)
    {
        ret[j]=digits[i];
        i++;j++;
    }


    return ret;

}


int main(void)
{

    int arr[6]={9,9,9,9,8,9};

    int *ptr=plusOne(arr,6);

    for(int i=0;i<7;i++)
    {
        printf("%d\n",ptr[i]);
    }

    system("pause");
    return 0;
}