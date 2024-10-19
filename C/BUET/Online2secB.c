#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    scanf("%[^\n]s",str);
    int n=strlen(str);
    int count=0;
    int i=0;
    int maxcount=0;
    int index;
    while(i<n)
    {
        if(str[i]!=' ' && i!=(n-1))
        {
            count++;
        }
        else{
            if(count>=maxcount)
            {    maxcount=count;
                index=i;
            }
            count=0;
        }
        i++;
    }
    //printf("%d %d ",maxcount,index);
    printf("The largest Word is ");
    for(int j=index-maxcount;j<=index;j++)
    {
        printf("%c",str[j]);
    }
    return 0;
}