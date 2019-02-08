#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>

void readFile(char s[]){
  FILE *fClear;
  fClear = fopen("encoder/clear.txt","r+");
  while (!feof(fClear))
  {
    fgets(s,256,fClear);
  }
  fclose(fClear);
}
//========================hiện chuỗi đã được mã hóa======================================//

void showEncoder(){
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *show = fopen("decoder/encript.txt","r");
    int c;
    while (1) {
      c = fgetc(show);
      if(feof(show)){
        break;
      }
      Sleep(360);
      SetConsoleTextAttribute(hConsoleColor, 7);
      printf("%c",c);
      //Beep( 850, 200);
    }
    fclose(show);
}
//====================kết thúc hàm hiện chuỗi mã hóa=======================================//

//====================hàm xử lý mã hóa=====================================================//


void Encoder_morse()
{
   FILE *fdictionary = fopen("asset/dictionary.txt","r");
   FILE *fEncript    = fopen("decoder/encript.txt","wa+"); // file lưu mã hóa
   FILE *fClear      = fopen("encoder/clear.txt","r");   // file cần mã hóa

   char *cKey[55];
   char *cDecoder[55];
   char  temp[256],cDecoder_temp[256];
    // khai báo mảng động

   for(int i = 0 ; i < counterLines(); i++)
   {
     cKey[i]     = (char*)malloc(20 * sizeof(char));
     cDecoder[i] = (char*)malloc(20 * sizeof(char));
     fscanf(fdictionary,"%s %s",cDecoder[i],cKey[i]);
   }
    // kết thúc khai báo



   fflush(stdin);
   //hàm readFile được định nghĩa;
   readFile(cDecoder_temp);

   for(int i = 0; i < strlen(cDecoder_temp); i++)
   {
     //sao chep từng ký tự vào temp và từ đó so sánh với cDecoder[]
     strncpy(temp,cDecoder_temp+i,1);
     //truyền ký tự kết thúc
     temp[1] = '\0';
     strupr(temp);   // In hoa tất cả chữ cái nhập vào
     if(strcmp(temp," ") == 0)
      {
        // nếu là khoảng trống sẽ được gán bằng dấu /
        fprintf(fEncript,"%s ","/");
      }
      else
      {
    for(int j = 0; j < counterLines(); j++)
        {
       if(strcmp(temp,cDecoder[j]) == 0)
          {
            {
              fflush(stdin);
              fprintf(fEncript,"%s ",cKey[j]);
            }
          }
        }
      }
   }
   // đóng file

   fclose(fdictionary);
   fclose(fEncript);
   fclose(fClear);

}
//=========================kết thúc hàm xử lý mã hóa===============================================//

//==================================================================================================

/*void rEncoder_morse()
{
   FILE *fKey;
   FILE *fDecoder;
   FILE *fDecoder_newline;
   FILE *fClears;

   fKey             = fopen("key.txt","r");
   fDecoder         = fopen("decoder.txt","r");
   fDecoder_newline = fopen("../decoder/decoder_newline.txt","r+");
   fClears           = fopen("../encoder/clears.txt","wa+");

   //khởi tạo để truyền dữ liệu
   char *cKey[50];
   char *cDecoder[50];
   char *cDecoder_newline[50];
   char temp[256];

   for(int i = 0 ; i < 44; i++){
     cKey[i]     = (char*)malloc(20 * sizeof(char));
     cDecoder[i] = (char*)malloc(20 * sizeof(char));

   }
   //truyền dữ liệu vào cKey[i] và cDecoder[i]
   for(int i = 0; i < 44; i++)
   {
     fscanf(fKey    ,"%s",cKey[i]);
     fscanf(fDecoder,"%s",cDecoder[i]);
   }

   for(int i = 0 ; i < countlines(); i++){
     cDecoder_newline[i] = (char*)malloc(20 * sizeof(char));
   }
   for(int i = 0 ; i < countlines(); i++){
     fscanf(fDecoder_newline,"%s",cDecoder_newline[i]);
   }
 for(int i = 0 ; i < countlines(); i++){
     strcpy(temp,cDecoder_newline[i]);
     if(strcmp(temp,"/") == 0)
     {
       fprintf(fClears,"%s"," ");
     }
     else
     {
       for(int j = 0; j < 44; j++){
         if(strcmp(temp,cKey[j]) == 0)
            {
              {
                fprintf(fClears,"%s",cDecoder[j]);
              }
            }
       }
     }
   }

   fclose(fDecoder);
   fclose(fKey);
   fclose(fDecoder_newline);
   fclose(fClears);
}*/
