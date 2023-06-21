#include "ArticulationAmplitude.hpp"

using namespace ArticulationAmplitude;

vecSegs Module::ConvertWavToVector(std::string file) {
  vecSegs result;
  WavHandler handler(file.c_str());
  while (!handler.FinishedReading()) {
    auto seg = std::make_shared<Segment>(probesNo);
    handler.ReadRawData(seg.get());
    result.push_back(seg);
  }
  return result;
}

float Module::CompareWithReference(std::vector<float> input,
                                   std::vector<float> ref) {
  float result = 0;
  for (int i = 1; i < std::min(input.size(), ref.size()); i++) {
    result += (1 - static_cast<float>(std::abs(input[i] - ref[i])) /
                       std::max(input[i], ref[i]));
  }
  return result / input.size();
}

void Module::Calculate(std::vector<std::shared_ptr<Segment>> segments) {
  float lastMax = 0;
  int seg_id = 0;
  for (int i = 0; i < segments.size() - 1; i++) {
    auto seg = segments[i];

    // get max value in current segment (seg)
    auto max = GetMax(*segments[i]);

    // add new sound if new sound detected and no sounds in vector
    if (sounds.size() == 0 && abs(max.value) > THRESHOLD) {
      sounds.push_back(Sound(max.value, max.freq, 0, seg_id));
    }
    // add new sound if new sound detected and vector of sounds is not empty
    else if (sounds.size() > 0) {
      auto lastSound = sounds[sounds.size() - 1];
      auto nextMax = GetMax(*segments[i + 1]);

      if (max.value > lastMax && max.value > nextMax.value) {
        sounds.push_back(Sound(max.value, max.freq,
                               std::abs(lastSound.val - max.value), seg_id));
      }
    }
    lastMax = max.value;
    seg_id++;
  }
}

Module::MaxValue Module::GetMax(Segment &segment) {
  MaxValue result;

  for (auto i = 0; i < probesNo; i++) {
    auto probe = segment.afterFFT[i];
    if (probe > result.value) {
      result.value = probe;
      result.freq = i;
    }
  }

  return result;
}
