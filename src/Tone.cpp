#include "Tone.hpp"
#include <cmath>

Note Tone::getSound(){
    int note = std::round(12.0 * std::log(freq / 440.0) / std::log(2));
    return static_cast<Note>((69 + note) %12);
}

float Tone::getOffset(){
    return 440.0 * std::pow(2, (static_cast<int>(getSound())-69)/12);
}

float Tone::getFrequency(){
    return freq;
}
