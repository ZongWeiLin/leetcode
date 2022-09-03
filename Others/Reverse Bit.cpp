#include <stdio.h>
#include <stdlib.h>

typedef unsigned long  uint32_t;

//隔//
//硂肈琌硓筁盢セ计籔1暗and//
//–bit琌1琌杠盢は锣计程硓筁ORミΘ1//
//癹伴程穦盢块计パオshiftは锣计パオshift//
uint32_t reverseBits(uint32_t n) 
{

    uint32_t rev_num=0;
    
    for(int i=0;i<31;i++)
    {
        //程琌1琌杠盢は锣计程ミΘ1//
        if(n&1)
            rev_num|=1;
        
        //块计パ程程蔼Traversal┮パオ┕shift//
        n>>=1;
        //パ琌は锣计┮琌パオshift//
        rev_num<<=1;
    }
    
    //程逞程琌1//
    if(n&1)
        rev_num|=1;

    return rev_num;
}


int main(void)
{

    system("pause");
    return 0;
}