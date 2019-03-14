#include "structs.h"
//N-7
NaturalNumber* MUL_Nk_N(NaturalNumber* one , unsigned int k)
{
while (k>0)
	{
		
		one->numbers=(int*)realloc(one->numbers,(one->length+1)*sizeof(int));
		one->length+=1;
		one->numbers[one->length+1]=0;
		k--;
	}
    return one;
}

//Z-1
WholeNumber* ABS_Z_N (WholeNumber* one)
{
    one->sign=2;
    return one;
}


//Q-3
RationNumber* TRANS_Z_Q(WholeNumber* zero)
{
    int i;
    RationNumber* one=NULL;
    one->wholeNumber->naturalNumber->numbers=(int*)realloc(one->wholeNumber->naturalNumber->numbers,zero->naturalNumber->length*sizeof(int));
    for (i=0;i<zero->naturalNumber->length;i++)
        one->wholeNumber->naturalNumber->numbers[i]=zero->naturalNumber->numbers[i];
    one->wholeNumber->sign=zero->sign;
    one->naturalNumber->length=1;
    one->naturalNumber->numbers=(int*)realloc(one->naturalNumber->numbers,1*sizeof(int));
    one->naturalNumber->numbers[0]=1;
    return one;
}




int main() {
    
	return 0;
}










