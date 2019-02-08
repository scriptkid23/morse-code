#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int counterSpace()
{
    FILE *fp;
    fp = fopen("decoder/encript.txt","r");
    int counter = 0;
    int c;
    while(1){
      c = fgetc(fp);
      if(feof(fp)){
        break;
      }
      if(c == ' '){
        counter++;
      }
    }
    fclose(fp);
    return counter;
}
// phục vụ cho việc cập nhật dữ liệu , các cấu trúc mã hóa mới 1 cách thuận lợi
int counterLines(){
  FILE *fp = fopen("asset/dictionary.txt","r");
  int counter = 0;
  char line[100];
  while(fgets(line, sizeof(line), fp) != NULL){
      counter++;
  }
  fclose(fp);
  return counter;
}
void Decoder_morse()
{
   FILE *fdictionary = fopen("asset/dictionary.txt","r");
   FILE *fClear      = fopen("encoder/clear.txt","wa+");
   FILE *fencript    = fopen("decoder/encript.txt","r");

   //khởi tạo để truyền dữ liệu
   char *cKey[55];
   char *cDecoder[55];
   char *cDecoder_newline[256];
   char temp[256];
   //cấp bộ nhớ động;
   for(int i = 0 ; i < counterLines(); i++)
   {
     cKey[i]     = (char*)malloc(20 * sizeof(char));
     cDecoder[i] = (char*)malloc(20 * sizeof(char));
     fscanf(fdictionary,"%s %s",cDecoder[i],cKey[i]);

   }
   // cấp bộ nhớ động;
   for(int i = 0 ; i < counterSpace()+1; i++) // số chuỗi mã hóa = số khoảng trống + 1
   {
     cDecoder_newline[i] = (char*)malloc(20 * sizeof(char));
     fscanf(fencript,"%s",cDecoder_newline[i]);
   }
   // so khớp các giá trị
   for(int i = 0 ; i < counterSpace()+1; i++)
   {
     strcpy(temp,cDecoder_newline[i]);
     if(strcmp(temp,"/") == 0)
     {
       fprintf(fClear,"%s"," ");
     }
     else
     {
       for(int j = 0; j < counterLines(); j++){
         if(strcmp(temp,cKey[j]) == 0)
            {
              {
                fprintf(fClear,"%s",cDecoder[j]);
              }
            }
       }
     }
   }
   // đóng file
   fclose(fdictionary);
   fclose(fencript);
   fclose(fClear);

}
