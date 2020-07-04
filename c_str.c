#include "c_str.h"
#include <stdio.h>
int c_str_len(char *pointer)
{
    printf("Getting length");
   int c = 0;

   while( *(pointer + c) != '\0' )
      c++;
    
   return c;
}

void reverse(char *s)
{
   int length, c;
   char *begin, *end, temp;

   length = c_str_len(s);
   begin  = s;
   end    = s;

   for (c = 0; c < length - 1; c++)
      end++;

   for (c = 0; c < length/2; c++)
   {
      temp   = *end;
      *end   = *begin;
      *begin = temp;

      begin++;
      end--;
   }
}

