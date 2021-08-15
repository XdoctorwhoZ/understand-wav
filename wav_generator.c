#include "wav_generator.h"



int write_header(
        FILE *file_p,
        int32_t sampleRate,
        int32_t frameCount,
        int32_t num_channels,           // number of channels 1=mono, 2=stereo
        int32_t bits_per_sample         // 8, 16, 32
        )
{
    int ret;
    
    wavfile_header_t wav_header;
    int32_t subchunk2_size;
    int32_t chunk_size;
    
    size_t write_count;
    
    subchunk2_size  = frameCount * num_channels * bits_per_sample / 8;
    chunk_size      = 4 + (8 + SUBCHUNK1SIZE) + (8 + subchunk2_size);
    
    wav_header.ChunkID[0] = 'R';
    wav_header.ChunkID[1] = 'I';
    wav_header.ChunkID[2] = 'F';
    wav_header.ChunkID[3] = 'F';
    
    wav_header.ChunkSize = chunk_size;
    
    wav_header.Format[0] = 'W';
    wav_header.Format[1] = 'A';
    wav_header.Format[2] = 'V';
    wav_header.Format[3] = 'E';
    
    wav_header.Subchunk1ID[0] = 'f';
    wav_header.Subchunk1ID[1] = 'm';
    wav_header.Subchunk1ID[2] = 't';
    wav_header.Subchunk1ID[3] = ' ';
    
    wav_header.Subchunk1Size = SUBCHUNK1SIZE;
    wav_header.AudioFormat = AUDIO_FORMAT_PCM;
    wav_header.NumChannels = num_channels;
    wav_header.SampleRate = sampleRate;
    wav_header.ByteRate = (sampleRate * num_channels * bits_per_sample / 8);
    wav_header.BlockAlign = (num_channels * bits_per_sample / 8);
    wav_header.BitsPerSample = bits_per_sample;
    
    wav_header.Subchunk2ID[0] = 'd';
    wav_header.Subchunk2ID[1] = 'a';
    wav_header.Subchunk2ID[2] = 't';
    wav_header.Subchunk2ID[3] = 'a';
    wav_header.Subchunk2Size = subchunk2_size;
    
    write_count = fwrite(   &wav_header, 
                            sizeof(wavfile_header_t), 1,
                            file_p);
                    
    ret = (1 != write_count)? -1 : 0;
    
    return ret;
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

    int32_t filesize = sizeof(wavfile_header_t) + (frame_count * sample_chan_size);




    fclose(file_p);
}






