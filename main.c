#include "wav_generator.h"


int main(void)
{

    generate_test_rampe_pattern(
        "test_16b_msb_header.wav",
        0, // no header = false, so the header is written
        0, // MSB rampe
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );
    generate_test_rampe_pattern(
        "test_16b_msb_no_header.wav",
        1, // no header = true
        0, // MSB rampe
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );

    generate_test_rampe_pattern(
        "test_16b_lsb_header.wav",
        0, // no header = false, so the header is written
        1, // LSB rampe
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );
    generate_test_rampe_pattern(
        "test_16b_lsb_no_header.wav",
        1, // no header = true
        1, // LSB rampe
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );




    generate_test_dual_pattern(
        "test_16b_dual_header.wav",
        0, // no header = false, so the header is written
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );
    generate_test_dual_pattern(
        "test_16b_dual_no_header.wav",
        1, // no header = true
        SAMPLE_RATE_11025,
        2,       // number of channels 1=mono, 2=stereo
        16     // 8, 16, 32
    );

    generate_signal_sin(
        "sound_sin_16b_11025_300hz.wav",
        2,                          // duration
        300,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_16b_11025_400hz.wav",
        2,                          // duration
        400,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_16b_11025_500hz.wav",
        2,                          // duration
        500,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );
    generate_signal_sin(
        "sound_sin_16b_11025_600hz.wav",
        2,                          // duration
        600,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        16                          // bits_per_sample
    );


    generate_signal_sin(
        "sound_sin_8b_11025_500hz.wav",
        2,                          // duration
        500,                        // frequence
        0.8,                        // ampli
        SAMPLE_RATE_11025,          // sample_rate
        2,                          // num_channels
        8                           // bits_per_sample
    );

}





