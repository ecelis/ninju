/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
NinjuAudioProcessorEditor::NinjuAudioProcessorEditor (NinjuAudioProcessor &p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
  // addAndMakeVisible (&square);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  juce::MemoryInputStream imageStream (BinaryData::patito_ninja98_png,
                                       BinaryData::patito_ninja98_pngSize,
                                       false);
  tapLogo = juce::ImageFileFormat::loadFrom (imageStream);

  // addAndMakeVisible (frequencySlider);

  setSize (400, 400);
}

NinjuAudioProcessorEditor::~NinjuAudioProcessorEditor () {}

//==============================================================================
void
NinjuAudioProcessorEditor::paint (juce::Graphics &g)
{
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll (getLookAndFeel ().findColour (
      juce::ResizableWindow::backgroundColourId));

  if (tapLogo.isValid ())
    {
      const auto bounds = getLocalBounds ();
      const auto imageWidth = tapLogo.getWidth () / 3;
      const auto imageHeight = tapLogo.getHeight () / 3;

      const auto x = 10;
      const auto y = 10;

      g.drawImage (tapLogo, x, y, imageWidth, imageHeight, 0, 0,
                   tapLogo.getWidth (), tapLogo.getHeight ());
    }
  // g.setColour (juce::Colours::white);
  // g.setFont (juce::FontOptions (15.0f));
  // g.drawFittedText ("Hello World!", getLocalBounds (),
  //                   juce::Justification::centred, 1);
}

void
NinjuAudioProcessorEditor::resized ()
{
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  // frequencySlider.setBounds (100, 200, 200, 200);
}
