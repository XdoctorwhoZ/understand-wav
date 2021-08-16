#include "wav_mini.h"

#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define MAX_HEADER_SIZE 300

int main(int argc, char *argv[])
{
   if(argc != 2)
   {
      printf("Need to pass the file argument");
      return 1;
   }


   char buffer[MAX_HEADER_SIZE];

   // Read file first MAX_HEADER_SIZE bytes
   FILE *fp = NULL;
   fp = fopen(argv[1], "rb");
   if(fp == NULL)
   {      
      printf("Error! Could not open file %s\n", strerror(errno) ); 
   }
   fseek(fp, 0L, SEEK_END);
   uint32_t real_size = ftell(fp);
   printf("real_size       : %d\n", real_size);
   fseek(fp, 0L, SEEK_SET);
   fread(buffer, 1, MAX_HEADER_SIZE, fp);


    // Decode buffer
    struct wavfile_header_s* header;
    uint32_t data_shift;
    int ret = wav_decode_header(buffer, MAX_HEADER_SIZE, &header, &data_shift);
    printf("parsing status  => %d\n", ret);


    printf("SampleRate      => %d\n", header->SampleRate);
    printf("BitsPerSample   => %d\n", header->BitsPerSample);
    printf("NumChannels     => %d\n", header->NumChannels);

    printf("data shift      => %d\n", data_shift); // start of data array


    // End
    if(fp != NULL)
    {
        fclose(fp);
    }
    return 0;
}




   