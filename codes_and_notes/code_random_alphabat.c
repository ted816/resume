/*
gcc -o random_alphabat random_alphabat.c
./random_alphabat

Write a program that generates a “random walk” across a 10 x 10 array. The array will
contain characters (all ’ . ’ initially). The program must randomly “walk” from element
to element, always going up. down, left, or right by one element. The elements visited
by the program will be labeled with the letters A through Z in the order visited. Here’s
an example of the desired output:

A B . . . . . . . .
. C D E . . . . . .
. . . F G H . . . .
. . . . J I N O . .
. . . . K L M P . .
. . . . . . . Q . .
. . . . U T S R . .
. . . . V W . . . .
. . . . . X . . . .
. . . . . Y Z . . .

I used this example because it showcase the logic flow of basic programmer.
Everyone would have a different flow of the program and the limitation it has.
My code have its limitation and cannot detect when there is a dead end.
Kindly refer to below:

A J I H . . . . . .
B C F G . . . . . .
. D E . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

	// declaration of values
	char frame[10][10], letter[26];
	int now_row =0, now_col=0, check_row=0, check_col=0, pass =0, x =0, store=0;
	srand(time(NULL));


	// populate the array frame with '.'
	for( int a = 0; a < 10; ++a){
		for ( int b = 0; b < 10; ++b)
			frame[a][b]='.';
	}
	
	// populate the array with A to Z using ASCII
	for(int a =65, b=0; a < 91; ++a, ++b){
		letter[b]=a;	
	}
	
	// input A into the array frame[0][0]
	frame[now_row][now_col]= letter[x];
	++x;

	// while Z is not reached
	while(x < 26){
		while(pass==0){
			store= rand() % 4;
			switch(store){
				case 0: check_row = now_row;
					check_col = now_col -1;
					break;
				case 1: check_row = now_row +1;
					check_col = now_col;
					break;
				case 2: check_row = now_row;
					check_col = now_col +1;
					break;
				case 3: check_row = now_row -1;
					check_col = now_col;
					break;
				default:printf("ERROR!!\n");
					break;
			}
			
			// check if the next direction moves out of the frame && next direction is empty
			if(check_row>=0 && check_col>=0 && check_row <10 && check_col <10 && frame[check_row][check_col]=='.'){
				//printf("hello");
				frame[check_row][check_col]=letter[x];
				pass=1;
				now_row=check_row;
				now_col=check_col;
			}
			
		}
		pass =0;
		++x;
	}

	// print answer
	for( int a = 0; a < 10; ++a){

		for ( int b = 0; b < 10; ++b)
			printf("%c ",frame[a][b]);
			printf("\n");
				
	}
	
	return 0;
}
