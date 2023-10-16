#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
 
#define DIM 100



int main() {
  int a[DIM];
  int cntPari = 0;
  int cntDispari = 0;
  int temp;
  srand(time(0)); 
  
  for(int i = 0; i < DIM; i++) {
    a[i] = 1 + rand()%223;
    for(int j = 0; j < i; j++) {
       	if(a[i] == a[j]) {
           i--;
        }
    }
  }

    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
       	    if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }


  for(int i = 0; i < DIM; i++) {
      if(a[i] % 2 == 0){
        cntPari++;
      }
      else{
        cntDispari++;
      }
    }

    int p = 0;
    for(int i = 0; i < DIM; i++) {
        if(a[i] % 2 == 0) {
            if(p < cntPari || p < 20) {
                temp = a[p];
                a[p] = a[i];
                a[i] = temp;
                p++; 
            } 
            else{
                i = DIM;
            }	                  
        }            
    }

    int d = 20;
    for(int i = (DIM -1); i > 19; i--) {
        if(a[i] % 2 != 0) {
            if(d < (cntDispari + 20) || d < 40) {
                temp = a[d];
                a[d] = a[i];
                a[i] = temp;
                d++; 
            } 
            else{
                i = 19;
            }	                  
        }            
    }
    for(int i = 20; i < 40; i++) {
        for(int j = 20; j < 40; j++) {
       	    if(a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for(int i = 40; i < DIM; i++) {
        for(int j = 40; j < DIM; j++) {
       	    if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", a[i]);
        if(i == 19 || i == 39) {
            printf("\n\n");
        }
    }
    printf("\n");

}