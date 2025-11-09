#include "Square.h"

void
Square::paint (juce::Graphics &g)
{
    g.fillAll (juce::Colours::yellow);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Yay world", getLocalBounds (),
                      juce::Justification::centred, 1);
}

void
Square::resized ()
{
}