#pragma once

#include <juce_audio_basics/juce_audio_basics.h>

#ifndef SINEWAVE_H
#define SINEWAVE_H

class SineWave
{
private:
  float amplitude = 0.2f;   // A
  float frequency = 440.0f; // f
  float currentSampleRate = 0.0f;
  float timeIncrement = 0.0f;
  //   float currentTime = 0.0f; // t
  std::vector<float> currentTime;

public:
  //   void prepare (double sampleRate);
  void prepare (double sampleRate, int numChannels);
  void process (juce::AudioBuffer<float> &buffer);
  float
  getAmplitude () const
  {
    return amplitude;
  }
  float
  getFrequency () const
  {
    return frequency;
  }
  void
  setAmplitude (const float newAmplitude)
  {
    amplitude = newAmplitude;
  }
  void
  setFrequency (const float newFrequency)
  {
    frequency = newFrequency;
  }
};

#endif // SINEWAVE_H