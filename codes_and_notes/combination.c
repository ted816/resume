#include <stdio.h>
#include <math.h>

int main(void){

int a[16][4]={0};
for(int i=0; i<16; i++){
	for(int j =0;j<4;j++){
		int k =(int)pow(2,j+1);
		if( i%k+1 > k/2){
			a[i][j]=1;
		}				
	}
}

// print combination
for(int i=0; i <16;++i){
	for(int j=0; j<4;++j){
		printf("%d ",a[i][j]);
	}printf("\n");
}


return 0;}
