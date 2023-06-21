#pragma once

#include "Note.hpp"
#include <string>
#include <vector>

class Exercise {
public:
  float CompareTone(std::vector<Note> seq);
  float CompareRythm(int bpm);
  float CompareLenght(std::vector<int32_t> lenght);
  float CompareAmp(std::vector<float> amps);
  explicit Exercise(std::string path);

  static void Serialize(std::string fileName, std::vector<Note> notes,
                        int32_t val, std::vector<int32_t> lenghts,
                        std::vector<float> amps);

protected:
  std::vector<Note> seq;
  std::vector<int32_t> len;
  std::vector<float> ref;
  int bpm;
};
