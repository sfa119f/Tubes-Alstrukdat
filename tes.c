#include <stdio.h>
#include <stdlib.h>
#include "input_command.c"
#include "player.h"
#include "bangunan.h"
#include "listlinier.h"
#include "arraydin.h"
int main(){
   // INPUT_COMMAND();
   TabInt TabBangunan;
   MakeEmpty(&TabBangunan,50);

    // kamus
   Player P1 = initPlayer(1);
   Player P2 = initPlayer(2);
   Bangunan A,B,C,D,E,F;
   POINT Po = MakePOINT(2,5);
   POINT Po2 = MakePOINT(1,4);
   POINT Po3 = MakePOINT(8,8);

   MakeBangunan(&A,Po,'C',1);
   MakeBangunan(&B,Po2,'V',1);
   MakeBangunan(&C,Po3,'T',1);
   MakeBangunan(&D,Po,'C',2);
   MakeBangunan(&E,Po2,'V',2);
   MakeBangunan(&F,Po3,'T',2);

   AddAsLastEl(&TabBangunan,A);
   AddAsLastEl(&TabBangunan,B);
   AddAsLastEl(&TabBangunan,C);
   AddAsLastEl(&TabBangunan,D);
   AddAsLastEl(&TabBangunan,E);
   AddAsLastEl(&TabBangunan,F);

   for (int i = GetFirstIdx(TabBangunan); i<= GetLastIdx(TabBangunan); i++) {
      if (Pemilik(Elmt(TabBangunan,i)) == 1) {
         InsVLast(&listB(P1),i);
      } else if (Pemilik(Elmt(TabBangunan,i)) == 2) {
         InsVLast(&listB(P2),i);
      }
   }
   printf("Bangunan milik Player 1:\n");
   PrintBangunan(P1);
   printf("Bangunan milik Player 2:\n");
   PrintBangunan(P2);

   inputCommand(&P1, &P2);
   
   return 0;
}