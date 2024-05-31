#include <stdio.h>

void tower_hanoi(int n , char from_rod , char to_rod , char aux_rod){


if(n == 1){
  printf("move the  disk1 from rod %c to rod %c\n",from_rod , to_rod);
  return;
}

tower_hanoi(n-1 , from_rod , aux_rod , to_rod);
printf("move the disk %d from  rod %c to  rod %c\n",n,from_rod , to_rod);
tower_hanoi(n-1 , aux_rod , to_rod , from_rod);
}


void main(){
  int n = 3;
  tower_hanoi(n , 'A' , 'C' , 'B');
}