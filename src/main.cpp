#include "ArticulationAmplitude.hpp"
#include "ArticulationLength.hpp"
#include "Exercise.hpp"
#include "FFT.hpp"
#include "Rhythm.hpp"
#include "ToneModule.hpp"
#include "WavHandler.h"
#include <cmath>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
  size_t probeSize = 1024 * 16;
  float sampleRate = 44100;
  WavHandler wav_hdr(argv[2]);
  Segment seg(probeSize);
  FFT fft(probeSize);
  ToneModule tone(probeSize, sampleRate);
  std::vector<Note> notes;
  Rhythm rhythmM;
  rhythmM.ReadSegments(argv[2]);
  int val = rhythmM.CalculateBPM();
  ArticulationLength articulationLength(1024, argv[2]);

  ArticulationAmplitude::Module amp(probeSize / 16);
  auto mainData = amp.ConvertWavToVector(argv[2]);
  auto fftModule = FFT(probeSize / 16);
  for (int i = 0; i < mainData.size(); i++) {
    fftModule.Calculate(mainData[i].get());
  }
  amp.Calculate(mainData);
  std::vector<float> amps;
  for (auto s : amp.sounds) {
    amps.push_back(s.diff);
  }

  std::vector<int32_t> lenghts;
  for (auto l : articulationLength.sounds) {
    lenghts.push_back(l->Length());
  }
  while (!wav_hdr.FinishedReading()) {
    wav_hdr.ReadRawData(&seg);
    fft.Calculate(&seg);

    notes.push_back(tone.process(&seg).getSound());
  }
  if (argv[1][0] == 'c') {
    Exercise ex(argv[3]);
    float tone = ex.CompareTone(notes);
    float rythm = ex.CompareRythm(val);
    float len = ex.CompareLenght(lenghts);
    float a = ex.CompareAmp(amps);
    if (std::isnan(len) || len < 0 || len > 1)
      len = .5;
    if (std::isnan(a) || a < 0 || a > 1)
      a = .5;
    std::cout << tone << std::endl;
    std::cout << rythm << std::endl;
    std::cout << (len + a) / 2 << std::endl;
  } else if (argv[1][0] == 's') {
    Exercise::Serialize(argv[3], notes, val, lenghts, amps);
  }
  return 0;
}
