/*
gcc -o combination combination.c -lm
./combination

This code is used to generate all combination of a 4bit. 
0000, 0001, 0010, 0011 all the way to 1111.

I came across an question, the user input 4 interger.
In any combination, can this 4 interger sum up to 100?

This may not be the best way, but using multi dimension array to test all possible combination.

I can statically type the combination into an array.
But if there is a different number of input each time, this codes is scalable for use.
*/

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
