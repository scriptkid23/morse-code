#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define username "admin"
#define password "admin@98765321"

/// tạo login người dùng
/*int counterLine(){
  FILE *fp = fopen("asset/dictionary.txt","r");
  int counter = 0;
  char line[100];
  while(fgets(line, sizeof(line), fp) != NULL){
      counter++;
  }
  fclose(fp);
  return counter;
} */
int displayLogin(){
  char user[30],pass[30];
  HANDLE hConsoleColor;
  hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleColor, 31);
  printf("************************************************************************************\n");
  printf("*                                         ICON SOFTWARE                            *\n");
  printf("************************************************************************************\n");
  printf("                                                                                    \n");
  printf("----------------------------------------------LOGIN---------------------------------\n");
  printf("------------------------------------------------------------------------------------\n");
  fflush(stdin);
  SetConsoleTextAttribute(hConsoleColor, 10);
  printf("Username: ");
  gets(user);
  fflush(stdin);
  SetConsoleTextAttribute(hConsoleColor, 10);
  printf("Password: ");
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  DWORD mode = 0;
  GetConsoleMode(hStdin, &mode);
  SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

  gets(pass);
  if(strcmp(user,username) == 0 && strcmp(pass,password) == 0){
    return 1;
  }else{
    return 0;
  }
}
 // kết thúc login