#include <stdio.h>
int  Drawline(unsigned int n){
  for (int j = 0; j < n; j++){
    printf("#");
  }
  printf("\n");
  return n;
}

void draw_2 (unsigned int n){
  for (int k = 0; k < n; k++){
    if (k==0){
      printf("#");
    }
    else if (k<n-1){
      printf(" ");
    }
    else{
      printf("#");
      printf("\n");
    }
  }
}

  
       
int main(void){
  int n = Drawline(5);
  for (int i=1; i<n-1; i++){
    draw_2(n);
  }
  Drawline(5);
  return 0;
}
