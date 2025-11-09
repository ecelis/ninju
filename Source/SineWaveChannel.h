/*
  ==============================================================================

    SineWaveChannel.h
    Created: 9 Nov 2025 2:34:59am
    Author:  ecelis

  ==============================================================================
*/

#pragma once
#include <numbers>

class SineWaveChannel
{
private:
  float amplitude = 0.2f;   // A
  float frequency = 440.0f; // f
  float currentSampleRate = 0.0f;
  float timeIncrement = 0.0f;
  float currentTime = 0.0f; // t

public:
  //   void prepare (double sampleRate);
  void prepare (double sampleRate);
  void process (float *output, int numSamples);
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
