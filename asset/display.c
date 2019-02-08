#include <stdio.h>
#include <string.h>
#include <windows.h>

void loading() 
{
  HANDLE hConsoleColor;
  hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleColor, 6);
  printf("[");
  for(int i = 0; i < 101; i++){
    Sleep(30);
  SetConsoleTextAttribute(hConsoleColor, 6);
    printf("%s","=");
  }
  printf("] 100%s","%");
  system("cls");
}
void display()
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 31);
    printf("*************************************************************\n");
    printf("*                         ------------                      *\n");
    printf("*                          Morse Code                       *\n");
    printf("*                                                           *\n");
    printf("*************************************************************\n");
    printf("\n");
    SetConsoleTextAttribute(hConsoleColor, 9);
    printf("1.Morse encoder \n");
    printf("2.Morse decoder \n");
    printf("3.Morse encoder view\n");
    SetConsoleTextAttribute(hConsoleColor, 2);
    printf("0.exit\n");
    SetConsoleTextAttribute(hConsoleColor, 9);
    printf("select: ");
}
void displayReturn()
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 9);
    printf("1.Back \n");
    SetConsoleTextAttribute(hConsoleColor, 2);
    printf("0.Exit \n");
    SetConsoleTextAttribute(hConsoleColor, 9);
    printf("select:  ");
}