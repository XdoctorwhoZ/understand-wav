#include "wav_generator.h"


int main(void)
{

    generate_signal_sin(
        "sound_sin_300hz.wav",
        2,                          // duration
        300,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_400hz.wav",
        2,                          // duration
        400,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_500hz.wav",
        2,                          // duration
        500,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_600hz.wav",
        2,                          // duration
        600,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );


}





