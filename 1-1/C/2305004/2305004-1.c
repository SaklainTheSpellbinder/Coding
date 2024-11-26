#include<stdio.h>
int main(){
    int n,max=-2147483648 ,min=2147483647,even=0,odd=0;
    float s=0.0;
    printf("How many numbers do you want to enter? ");
    scanf("%d",&n);
    int p;
    printf("Enter %d numbers: ",n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        s+=p;
        if(p%2==0)
            even++;
        else
            odd++;
        if(max<p)
        {
            max=p;
        }
        if(min>p)
        {
            min=p;
        }
    }
    printf("\nMinimum Number: %d",min);
    printf("\nMaximum Number: %d",max);
    printf("\nSum of all Numbers: %d",(int)s);
    if((float)(s/n)>(int)(s/n))
        printf("\nAverage: %.2f",(float)(s/n));
    else
        printf("\nAverage: %d",(int)(s/n));
    printf("\nEven Number count: %d",even);
    printf("\nOdd Number count: %d",odd);
    return 0;
}