#include <stdio.h>

int main(void){
  
#if defined (_WIN64__)
  puts("you are on windows");
#elif(__APPLE__)
  puts("you are on MAC");
#elif(__unix)
  puts("You are on Linux");
#endif

return 0;
}
