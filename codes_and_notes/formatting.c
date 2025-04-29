/*
gcc -o formatting formating.c
./formatting write
./formatting read
./formatting read3
./formatting write
./formatting read3

if you are testing the code, do take note on the directory.

A code to understand the surface for text formatting.
I can use this for database, json, php, csv, API, GET request.

This code writes 3 variable into a certain format.
When reading the data, depends on how the data is formatted, we can assign the data to different variable.
Or the simple way, read the whole thing as a string.

I uses argv, argc for learning purposes. I foresee it to be used with shell scripting.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* FORMAT_WRITE = "(%s, %d, %d)\n";
const char* FORMAT_READ_3 = "(%[^,], %d, %d)\n";
const char* FORMAT_READ_1 = "(%[^)])\n";

struct score{
        char name[50];
        int age;
        int score;
};

int main(int argc, char *argv[]){

// writing to a file using 3 variable and special format
if(strcmp(argv[1],"write")==0){

        struct score p1={.name = "Andrew Lim",.age = 10, .score =76};

        FILE *file = fopen("people.dat","a+");
        if (file == NULL){ 
          printf("file error\n");return 1;
        }

// save format as (Andrew Lim, 10, 76)\n , refer to line 5
fprintf(file,FORMAT_WRITE, p1.name,p1.age,p1.score);

puts("Andrew added");
}

        
// reading the input as an string, omitting the "special format"
// note on the file location
if(strcmp(argv[1],"read")==0){
char a[100];
FILE *file =fopen("/home/user/new_folder/people.dat","r");
  while(fscanf(file,FORMAT_READ_1,a)==1){
      printf("%s\n",a);
  }
}

// reading the input and seperating them into 3 variable
if(strcmp(argv[1],"read3")==0){
        FILE *file =fopen("/home/user/new_folder/people.dat","r");
        char a[100]; int b,c;
            while(fscanf(file, FORMAT_READ_3,a , &b, &c)==3){   
                printf("%s %d, %d\n", a, b, c);
            }
}



return 0;
}
