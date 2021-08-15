#include "wav_generator.h"


int main(void)
{


    generate_signal_sin(
        "sound_sin_300hz.wav",
        2,
        300,
        0.8,
        SAMPLE_RATE_11025, // sample_rate
        2,
        16
    );

}
