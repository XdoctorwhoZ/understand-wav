#include "wav_mini.h"





int write_header(
    uint8_t* buffer,
    int32_t sampleRate,
    int32_t frameCount,
    int32_t num_channels,           // number of channels 1=mono, 2=stereo
    int32_t bits_per_sample         // 8, 16, 32
    );


void generate_signal_sin(
    const char* filename,
    double duration,            // seconds
    double frequency,           //
    double amplitude,           // min 0 => max 1
    int32_t sample_rate,
    int32_t num_channels,       // number of channels 1=mono, 2=stereo
    int32_t bits_per_sample     // 8, 16, 32
);



