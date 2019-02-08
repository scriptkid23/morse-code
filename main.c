#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asset/Decoder_morse.c"
#include "asset/Encoder_morse.c"
#include <windows.h>
#include "asset/display.c"
#include "asset/login.c"

/*
  $$$$$$\        $$$$$$\         $$$$$$         $$\   $$\
  \_$$  _|      $$  __$$\       $$  __$$        $$$\  $$ |
    $$ |        $$ /  \__|      $$ /  $$ |      $$$$\ $$ |
    $$ |        $$ |            $$ |  $$ |      $$ $$\$$ |
    $$ |        $$ |            $$ |  $$ |      $$ \$$$$ |
    $$ |        $$ |  $$\       $$ |  $$ |      $$ |\$$$ |
  $$$$$$\       \$$$$$$  |       $$$$$$  |      $$ | \$$ |
  \______|       \______/        \______/       \__|  \__|
  SOFTWARE

*/

int main ()
 {
  FILE *fcheck = fopen("asset/dictionary.txt","r");

  int select,check;
  int countLogin = 0;
  HANDLE hConsoleColor;
  hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
  // kiểm tra tồn tại file dictionary.txt chưa 
  if(fcheck == NULL){
    perror("INFO");
    printf("====={asset/dictionary.txt}=====\n");
    return -1;
  }else{
    do
    {
      if(displayLogin() == 1)
      {
      system("cls") ;
      do
        {
          display();
          scanf("%d",&select);
          switch (select)
              {
                case 1:
                    Encoder_morse();
                    system("cls") ;
                    loading();
                    //system("cls");
                    printf("\n");
                    printf("---------------------------------------\n");
                    printf("\n");
                    printf("---------Encryption successful---------\n");
                    printf("\n");
                    printf("---------------------------------------\n");
                    displayReturn();
                    scanf("%d",&check);
                    system("cls") ;
                    break;
                case 2:
                    Decoder_morse();
                    system("cls") ;
                    loading();
                    //system("cls");
                    printf("\n");
                    printf("---------------------------------------\n");
                    printf("\n");
                    printf("----------successful decoding----------\n");
                    printf("\n");
                    printf("---------------------------------------\n");
                    displayReturn();
                    scanf("%d",&check);
                    system("cls") ;
                    break;
                case 3:
                    system("cls");

                    printf("---------------------------------------\n");
                    printf("\n");
                    printf("----------starting encoder...----------\n");
                    printf("\n");
                    printf("---------------------------------------\n");
                    printf("\n");

                    showEncoder();
                    printf("\n");
                    displayReturn();
                    scanf("%d",&check);
                    system("cls") ;

                    break;
                default:
                    check = 0;
                    break;
                }
        }
      while (check == 1);
      }
      else
      {
                system("cls") ;
                printf("\n");
                SetConsoleTextAttribute(hConsoleColor, 12);
                printf("   *LOGIN FAILED*\n");
                printf("*Please login again ^^* \n");
                countLogin++;
                SetConsoleTextAttribute(hConsoleColor, 12);
                printf("You have %d login attempts\n",5-countLogin);
                printf("\n");
      }
      if(check == 0){
        break;
      }
    }while(countLogin < 5);
}
      return(0);
}
