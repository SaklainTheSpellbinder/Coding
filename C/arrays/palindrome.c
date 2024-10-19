#include<stdio.h>
int main(){
  int temp=0;
  int arr[5]={1,2,3,3,1};
  for(int i=0,j=4;i!=j;i++,j--){
    if(arr[i]!=arr[j])
    {
        temp=1;
        break;
    }
  }
  if(temp==1)
  printf("Not a palindrome");
  else
  printf("A palindrome");
  return 0;
}
