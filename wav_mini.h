#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>


#define SUBCHUNK1SIZE       (16)
#define AUDIO_FORMAT_PCM    (1)


// #define SAMPLE_RATE_44100     (44100)
#define SAMPLE_RATE_11025       (11025)
#define SAMPLE_RATE_16K         (16000)


/*
The header of a wav file Based on:
https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
*/
typedef struct wavfile_header_s
{
    char    ChunkID[4];     /*  4   */
    int32_t ChunkSize;      /*  4   */
    char    Format[4];      /*  4   */
    
    char    Subchunk1ID[4]; /*  4   */
    int32_t Subchunk1Size;  /*  4   */
    int16_t AudioFormat;    /*  2   */
    int16_t NumChannels;    /*  2   */
    int32_t SampleRate;     /*  4   */
    int32_t ByteRate;       /*  4   */
    int16_t BlockAlign;     /*  2   */
    int16_t BitsPerSample;  /*  2   */
    
    char    Subchunk2ID[4]; // 4
    int32_t Subchunk2Size;  // 4
}
wavfile_header_t;


int wav_decode_header(uint8_t* buffer, uint32_t buffer_size, struct wavfile_header_s** header, uint32_t* data_shift);

