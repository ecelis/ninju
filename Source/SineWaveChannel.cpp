/*
  ==============================================================================

    SineWaveChannel.cpp
    Created: 9 Nov 2025 2:34:59am
    Author:  ecelis

  ==============================================================================
*/

#include "SineWaveChannel.h"
#include <cmath>


// SineWave::prepare (double sampleRate, const int numChannels)
void
SineWaveChannel::prepare (double sampleRate)
{
  currentSampleRate = static_cast<float> (sampleRate);
  timeIncrement = 1.0f / currentSampleRate;
  // currentTime.resize (numChannels, 0.0f);
}

// SineWave::process (juce::AudioBuffer<float> &buffer)
void
SineWaveChannel::process (float *output, const int numSamples)
{
  // if (currentTime.size () != buffer.getNumChannels ())
  //   return;
  // // y(t) = A.sin(2𝛡ft + Θ)
  // for (int channel = 0; channel < buffer.getNumChannels (); ++channel)
  //   {
  //     auto *output = buffer.getWritePointer (channel); // y
  for (int sample = 0; sample < numSamples; ++sample)
    {
      // output[sample] = amplitude
      //                  * std::sinf (juce::MathConstants<float>::twoPi
      //                               * frequency * currentTime[channel]);
      output[sample] = amplitude
                       * std::sinf (2.0f * std::numbers::pi_v<float>
                                    * frequency * currentTime);
      currentTime = currentTime + timeIncrement; // t
    }
  // }
}