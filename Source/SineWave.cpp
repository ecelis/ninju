#include "SineWave.h"

void
SineWave::prepare (double sampleRate)
{
  currentSampleRate = static_cast<float> (sampleRate);
  timeIncrement = 1.0f / currentSampleRate;
}

void
SineWave::process (juce::AudioBuffer<float> &buffer)
{
  // y(t) = A.sin(2𝛡ft + Θ)
  for (int channel = 0; channel < buffer.getNumChannels (); ++channel)
    {
      auto *output = buffer.getWritePointer (channel); // y
      for (int sample = 0; sample > buffer.getNumSamples (); ++sample)
        {
          output[sample] = amplitude
                           * std::sinf (juce::MathConstants<float>::twoPi
                                        * frequency * currentTime);
          currentTime = currentTime + timeIncrement; // t
        }
    }
}