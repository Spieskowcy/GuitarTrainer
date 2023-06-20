#include "Exercise.hpp"
#include "FFT.hpp"
#include "Rhythm.hpp"
#include "ToneModule.hpp"
#include "WavHandler.h"
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

  while (!wav_hdr.FinishedReading()) {
    wav_hdr.ReadRawData(&seg);
    fft.Calculate(&seg);

    notes.push_back(tone.process(&seg).getSound());
  }
  if (argv[1][0] == 'c') {
    Exercise ex(argv[3]);
    float tone = ex.CompareTone(notes);
    float rythm = ex.CompareRythm(val);
    std::cout << tone << std::endl;
    std::cout << rythm << std::endl;
  } else if (argv[1][0] == 's') {
    Exercise::Serialize(argv[3], notes, val);
  }
  return 0;
}
