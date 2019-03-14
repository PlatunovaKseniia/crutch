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
    one=(RationNumber*)malloc(1*sizeof(RationNumber));
    one->wholeNumber->naturalNumber->numbers=(int*)realloc(one->wholeNumber->naturalNumber->numbers,zero->naturalNumber->length*sizeof(int));
    for (i=0;i<zero->naturalNumber->length;i++)
        one->wholeNumber->naturalNumber->numbers[i]=zero->naturalNumber->numbers[i];
    one->wholeNumber->sign=zero->sign;
    one->naturalNumber->length=1;
    one->naturalNumber->numbers=(int*)realloc(one->naturalNumber->numbers,1*sizeof(int));
    one->naturalNumber->numbers[0]=1;
    return one;
}



//N-12
NaturalNumber* DIV_NN_N(NaturalNumbers* zero, NaturalNumbers* one)
{
    NaturalNumber* two;
    NaturalNumber* three;
    NaturalNumber* four;
    int flag;
    flag=COM_NN_D(zero,one);
    if (flag!=2 || flag!=0)
        return NULL;
    else
    {
        two = DIV_NN_N(zero,one);
        three = MUL_NN_N(one, two);
        four = SUB_NN_N(zero,three);
    }
    FREE_N(&two);
    FREE_N(&three);
    return four;
}


//Z-7
WholeNumber* SUB_ZZ_Z(WholeNumber* zero, WholeNumber* one)
{
    
}



int main() {
    
	return 0;
}










