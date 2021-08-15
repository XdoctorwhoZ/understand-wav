#include "wav_generator.h"
#include <stdio.h>
#include <math.h>

int write_header(
    uint8_t* buffer,
    int32_t sampleRate,
    int32_t frameCount,
    int32_t num_channels,           // number of channels 1=mono, 2=stereo
    int32_t bits_per_sample         // 8, 16, 32
    )
{
    wavfile_header_t* wav_header = (wavfile_header_t*) buffer;
    int32_t subchunk2_size;
    int32_t chunk_size;
    
    size_t write_count;
    
    subchunk2_size  = frameCount * num_channels * bits_per_sample / 8;
    chunk_size      = 4 + (8 + SUBCHUNK1SIZE) + (8 + subchunk2_size);
    
    wav_header->ChunkID[0] = 'R';
    wav_header->ChunkID[1] = 'I';
    wav_header->ChunkID[2] = 'F';
    wav_header->ChunkID[3] = 'F';
    
    wav_header->ChunkSize = chunk_size;
    
    wav_header->Format[0] = 'W';
    wav_header->Format[1] = 'A';
    wav_header->Format[2] = 'V';
    wav_header->Format[3] = 'E';
    
    wav_header->Subchunk1ID[0] = 'f';
    wav_header->Subchunk1ID[1] = 'm';
    wav_header->Subchunk1ID[2] = 't';
    wav_header->Subchunk1ID[3] = ' ';
    
    wav_header->Subchunk1Size = SUBCHUNK1SIZE;
    wav_header->AudioFormat = AUDIO_FORMAT_PCM;
    wav_header->NumChannels = num_channels;
    wav_header->SampleRate = sampleRate;
    wav_header->ByteRate = (sampleRate * num_channels * bits_per_sample / 8);
    wav_header->BlockAlign = (num_channels * bits_per_sample / 8);
    wav_header->BitsPerSample = bits_per_sample;
    
    wav_header->Subchunk2ID[0] = 'd';
    wav_header->Subchunk2ID[1] = 'a';
    wav_header->Subchunk2ID[2] = 't';
    wav_header->Subchunk2ID[3] = 'a';
    wav_header->Subchunk2Size = subchunk2_size;
    
    return 0;
}









void generate_signal_sin(
    const char* filename,
    double duration,            // seconds
    double frequency,           //
    double amplitude,           // min 0 => max 1
    int32_t sample_rate,
    int32_t num_channels,       // number of channels 1=mono, 2=stereo
    int32_t bits_per_sample     // 8, 16, 32
)
{
    FILE* file_p;
    uint8_t* buffer;

    // Open the wav file
    file_p = fopen(filename, "wb");
    if(NULL == file_p)
    {
        perror("fopen failed");
        exit(1);
    }

    // number of sample per seconds * the number of seconds
    int32_t frame_count = duration * sample_rate;

    // sample size
    int32_t sample_chan_size;
    if(bits_per_sample == 8)
    {
        sample_chan_size = num_channels;
    }
    else if(bits_per_sample == 16)
    {
        sample_chan_size = num_channels * 2;
    }
    else if(bits_per_sample == 32)
    {
        sample_chan_size = num_channels * 4;
    }

    //
    printf("frame_count         %d\n", frame_count);
    printf("num_channels        %d\n", num_channels);
    printf("sample_chan_size    %d\n", sample_chan_size);
    int32_t filesize = sizeof(wavfile_header_t) + (frame_count * sample_chan_size);
    buffer = (uint8_t*) malloc( filesize );

    //
    write_header(buffer, sample_rate, sample_rate, num_channels, bits_per_sample);

    //
    double SampleRate_d = (double)sample_rate;
    double SamplePeriod = 1.0 / SampleRate_d;
    printf("SamplePeriod        %lf\n", SamplePeriod);

    //
    double freq_period = 1.0 / frequency;
    double alpha = (2*M_PI) / freq_period;
    printf("freq_period         %lf\n", freq_period);
    printf("alpha               %lf\n", alpha);


    //
    if(bits_per_sample == 8)
    {
        int8_t* data = buffer + sizeof(wavfile_header_t);
        
    }
    else if(bits_per_sample == 16)
    {
        int16_t* data = (int16_t*) (buffer + sizeof(wavfile_header_t));
        for(int i=0; i<frame_count ; i++)
        {
            double val = sin( (double)((double)i*(double)SamplePeriod*(double)alpha) );
            
            // printf("v=%d\n", idx);

            // left
            int idx = i*num_channels;
            data[idx] = (int16_t) (val * SHRT_MAX);
            // right
            data[idx+1] = (int16_t) (val * SHRT_MAX);
        
            
        }
    }
    else if(bits_per_sample == 32)
    {
        sample_chan_size = num_channels * 4;
    }


    //
    fwrite(buffer, filesize, 1, file_p);

    //
    free(buffer);
    fclose(file_p);
}






