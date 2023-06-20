#pragma once

#include "Note.hpp"
#include <string>
#include <vector>

class Exercise {
public:
  float CompareTone(std::vector<Note> seq);
  float CompareRythm(int bpm);
  explicit Exercise(std::string path);

  static void Serialize(std::string fileName, std::vector<Note> notes,
                        int32_t val);

protected:
  std::vector<Note> seq;
  int bpm;
};
