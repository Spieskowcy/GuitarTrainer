#pragma once
#include "Segment.hpp"
#include "WavHandler.h"
#include <memory>
#include <vector>

namespace ArticulationAmplitude {

struct Sound {
  Sound(float val, float freq, float diff, int seg_id)
      : val(val), freq(freq), diff(diff), segment_id(seg_id){};
  float val;
  float freq;
  float diff;
  int segment_id;
};
using vecSegs = std::vector<std::shared_ptr<Segment>>;

class Module {
public:
  vecSegs ConvertWavToVector(std::string file);
  static float CompareWithReference(std::vector<float> input,
                                    std::vector<float> ref);

  Module(int probesNo) : probesNo(probesNo){};

  std::vector<Sound> sounds;
  void Calculate(vecSegs segments);

private:
  struct MaxValue {
    float value = 0.0f;
    float freq = 0.0f;
  };

  MaxValue GetMax(Segment &segment);
  int probesNo;
  float THRESHOLD = 0;
};

} // namespace ArticulationAmplitude
