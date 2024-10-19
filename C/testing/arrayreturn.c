#include<stdio.h>

void oi(int n,int k,int arr[])
{
    int r=0;
    int i=k-1;
    while(n!=0)
    {
        r=n%10;
        n=n/10;
        arr[i]=r;
        i--;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int p=n;
    int digit=0;
    while(p!=0)
    {
        p=p/10;
        digit++;
    }
    int arr[digit];
    oi(n,digit,arr);
    int j=0;
    int temp=0;
    while(j<digit)
    {
    int duplicate=arr[j];
    for(int i=j+1;i<digit;i++)
    {
        if(duplicate==arr[i]){
            temp=1;
            break;
        }
    }
    if(temp==1)
    {
        printf("Yes");
        break;
    }
    else
        j++;
    }
    if(temp==0)
        printf("No");
    return 0;
}