
#include "wav_mini.h"

int wav_decode_header(uint8_t* buffer, uint32_t buffer_size, struct wavfile_header_s** header, uint32_t* data_shift)
{
    *header = (struct wavfile_header_s*) buffer;
    if( (*header)->ChunkID[0] != 'R'  )
    {
        return -1;
    }

    // wav_header->ChunkID[1] = 'I';
    // wav_header->ChunkID[2] = 'F';
    // wav_header->ChunkID[3] = 'F';
    


    *data_shift = sizeof(struct wavfile_header_s) - 8;
    while(( buffer[(*data_shift)+0] != 'd' ||
            buffer[(*data_shift)+1] != 'a' ||
            buffer[(*data_shift)+2] != 't' ||
            buffer[(*data_shift)+3] != 'a' ) &&
            (*data_shift) <= (buffer_size-4) )
    {
        // printf("%d %c\n", (*data_shift), buffer[(*data_shift)+0]);
        (*data_shift)++;
    }
    if(*data_shift == buffer_size-4)
    {
        return -2;
    }
    (*data_shift) += 8; // to go on the data section



    return 0;
}

