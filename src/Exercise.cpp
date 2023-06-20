#include "Exercise.hpp"
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
}

float Exercise::CompareRythm(int bpm) {
  return (1 - static_cast<float>(std::abs(bpm - this->bpm)) /
                  std::max(bpm, this->bpm));
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
                         int32_t val) {
  Track track;
  std::fstream output(fileName, std::ios::out | std::ios::binary);
  track.set_bpm(val);
  for (size_t i = 0; i < notes.size(); i++) {
    track.add_sequence(static_cast<int32_t>(notes[i]));
  }

  track.SerializeToOstream(&output);
}
