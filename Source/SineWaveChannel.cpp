/*
  ==============================================================================

    SineWaveChannel.cpp
    Created: 9 Nov 2025 2:34:59am
    Author:  ecelis

  ==============================================================================
*/

#include "SineWaveChannel.h"
#include <cmath>

void
SineWaveChannel::prepare (double rate)
{
  sampleRate = static_cast<float> (rate);
  timeIncrement = 1.0f / sampleRate;
}

void
SineWaveChannel::process (float *output, const int numSamples)
{
  // y(t) = A.sin(2𝛡ft + Θ)
  for (int sample = 0; sample < numSamples; ++sample)
    {
      output[sample] = amplitude
                       * std::sinf (2.0f * std::numbers::pi_v<float>
                                    * frequency * currentTime);
      currentTime = currentTime + timeIncrement; // t
    }
  // }
}