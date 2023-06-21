#include "Exercise.hpp"
#include "ArticulationAmplitude.hpp"
#include "proto/track.pb.h"
#include <fstream>

Exercise::Exercise(std::string path) {
  Track track;
  std::fstream input(path, std::ios::in | std::ios::binary);
  track.ParseFromIstream(&input);
  this->bpm = track.bpm();
  this->seq.reserve(track.sequence_size());
  for (size_t i = 0; i < track.sequence_size(); i++) {
    this->seq.push_back(static_cast<Note>(track.sequence(i)));
  }
  for (size_t i = 0; i < track.length_size(); i++) {
    this->len.push_back(track.length(i));
  }
  for (size_t i = 0; i < track.amps_size(); i++) {
    this->ref.push_back(track.amps(i));
  }
}

float Exercise::CompareRythm(int bpm) {
  return (1 - static_cast<float>(std::abs(bpm - this->bpm)) /
                  std::max(bpm, this->bpm));
}

float Exercise::CompareAmp(std::vector<float> amps) {
  return ArticulationAmplitude::Module::CompareWithReference(amps, ref);
}

float Exercise::CompareLenght(std::vector<int32_t> lenght) {
  float running_avg = 0;
  std::cout << lenght.size() << std::endl;
  for (int i = 0; i < lenght.size(); i++) {
    running_avg += (1 - static_cast<float>(std::abs(lenght[i] - this->len[i])) /
                            std::max(lenght[i], this->len[i]));
  }
  return running_avg / lenght.size();
}

float Exercise::CompareTone(std::vector<Note> seq) {
  std::vector<std::vector<int>> dp(this->seq.size() + 1,
                                   std::vector<int>(seq.size() + 1, 0));

  for (int i = 1; i <= this->seq.size(); i++) {
    for (int j = 1; j <= seq.size(); j++) {
      if (this->seq[i - 1] == seq[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  return static_cast<float>(dp[this->seq.size()][seq.size()]) /
         std::max(this->seq.size(), seq.size());
}

void Exercise::Serialize(std::string fileName, std::vector<Note> notes,
                         int32_t val, std::vector<int32_t> lenghts,
                         std::vector<float> amps) {
  Track track;
  std::fstream output(fileName, std::ios::out | std::ios::binary);
  track.set_bpm(val);
  for (size_t i = 0; i < notes.size(); i++) {
    track.add_sequence(static_cast<int32_t>(notes[i]));
  }

  for (size_t i = 0; i < lenghts.size(); i++) {
    track.add_length(lenghts[i]);
  }
  for (size_t i = 0; i < amps.size(); i++) {
    track.add_amps(amps[i]);
  }
  track.SerializeToOstream(&output);
}
