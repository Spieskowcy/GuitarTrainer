#pragma once
#include "Exercise.hpp"
#include "proto/track.pb.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <fstream>

class ExerciseLocal : public Exercise {
public:
  ExerciseLocal(std::vector<Note> seq, int bpm) : Exercise(std::string()) {
    this->seq = seq;
    this->bpm = bpm;
  }
};

TEST(Exercise, Rhythm1) {
  ExerciseLocal el(std::vector<Note>(), 120);

  ASSERT_FLOAT_EQ(el.CompareRythm(120), 1);
}
TEST(Exercise, Rhythm2) {
  ExerciseLocal el(std::vector<Note>(), 30);

  ASSERT_NEAR(el.CompareRythm(25), .829, .01);
}

TEST(Exercise, Tone1) {
  using enum Note;
  ExerciseLocal el(std::vector<Note>{C, CS, D, DS, E, F, FS, G, GS, A, AS, B},
                   30);

  ASSERT_FLOAT_EQ(el.CompareTone(std::vector<Note>{C, CS, D, DS, E, F, FS, G,
                                                   GS, A, AS, B}),
                  1);
}

TEST(Exercise, Tone2) {
  using enum Note;
  ExerciseLocal el(std::vector<Note>{CS, D, DS, E}, 30);

  ASSERT_FLOAT_EQ(el.CompareTone(std::vector<Note>{DS, E, F, FS}), .5);
}

TEST(Exercise, Parser) {
  using enum Note;
  Track track;
  track.set_bpm(120);
  std::vector<Note> tmp{C, CS, D, DS, E, F, FS, G, GS, A, AS, B};
  std::transform(
      tmp.begin(), tmp.end(),
      google::protobuf::RepeatedFieldBackInserter(track.mutable_sequence()),
      [](Note n) { return static_cast<int>(n); });
  std::fstream output("test.track",
                      std::ios::out | std::ios::trunc | std::ios::binary);
  track.SerializeToOstream(&output);
  output.close();

  Exercise ex("test.track");
  ASSERT_FLOAT_EQ(ex.CompareRythm(120), 1);
  ASSERT_FLOAT_EQ(ex.CompareTone(std::vector<Note>{C, CS, D, DS, E, F, FS, G,
                                                   GS, A, AS, B}),
                  1);
}
