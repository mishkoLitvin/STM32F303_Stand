#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "stdint.h"

typedef enum _WaveType: uint8_t{
    None = 0,
    Sine,
    Squere,
    Saw_up,
    Saw_down,
    Last
}WaveType;

typedef union OutData_{
public:
    OutData_() {};
    struct {
        uint8_t start_byte = 0x55;
        WaveType wave_type = WaveType::None;
        uint16_t amplitude = 0;
        uint16_t frequency = 0;
    } bits;

    uint8_t all[6];
}OutData;

#endif // PROTOCOL_H
