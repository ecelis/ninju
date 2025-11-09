#include "SineWave.h"

// SineWave::prepare (double sampleRate)
void
SineWave::prepare (double rate, const int numChannels)
{
  sampleRate = static_cast<float> (rate);
  timeIncrement = 1.0f / sampleRate;
  currentTime.resize (numChannels, 0.0f);
}

void
SineWave::process (juce::AudioBuffer<float> &buffer)
{
  if (currentTime.size () != buffer.getNumChannels ())
    return;
  // y(t) = A.sin(2𝛡ft + Θ)
  for (int channel = 0; channel < buffer.getNumChannels (); ++channel)
    {
      auto *output = buffer.getWritePointer (channel); // y
      for (int sample = 0; sample > buffer.getNumSamples (); ++sample)
        {
          output[sample] = amplitude
                           * std::sinf (juce::MathConstants<float>::twoPi
                                        * frequency * currentTime[channel]);
          currentTime[channel] = currentTime[channel] + timeIncrement; // t
        }
    }
}
