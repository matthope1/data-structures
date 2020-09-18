#include <stdio.h>


struct Rectangle {
   int width;
   int height;
};


int main() {
   // printf() displays the string inside quotation



   struct Rectangle rect;
   rect.width = 0;
   rect.height = 0;


   printf("%i %i", rect.width, rect.height);




   return 0;
}

