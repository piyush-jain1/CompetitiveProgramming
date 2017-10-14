#include<stdio.h>

int main()
{
  int a[10],i;
  
   for(i=0;i<10;i++){
   
   scanf("%d",&a[i]);
   
   }
   for(i=0;i<10;i++){
     if(a[i]!=42){
   printf("%d\n",a[i]);
}
     else{
      return 0;
}
}
return 0;
}
