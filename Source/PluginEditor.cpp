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
    : AudioProcessorEditor (&p), processorRef (p),
      freqSliderAttachment (processorRef.getState (), "freqHz",
                            frequencySlider),
      playButtonAttachment (processorRef.getState (), "play", playButton)
{
  // addAndMakeVisible (&square);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  juce::MemoryInputStream imageStream (BinaryData::patito_ninja98_png,
                                       BinaryData::patito_ninja98_pngSize,
                                       false);
  tapLogo = juce::ImageFileFormat::loadFrom (imageStream);

  frequencySlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
  frequencySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 100, 50);
  // frequencySlider.setRange (0.0f, 1.0f, 0.01f);
  // frequencySlider.setValue (0.5f);
  addAndMakeVisible (frequencySlider);

  frequencyLabel.setJustificationType (juce::Justification::centred);
  addAndMakeVisible (frequencyLabel);

  playButton.setButtonText ("Playing");
  playButton.setToggleState (true,
                             juce::NotificationType::dontSendNotification);
  playButton.setClickingTogglesState (true);
  playButton.setColour (juce::TextButton::ColourIds::buttonOnColourId,
                        juce::Colours::green);
  playButton.setColour (juce::TextButton::ColourIds::buttonColourId,
                        juce::Colours::red);
  playButton.onClick = [this] ()
    {
      const bool isPlaying = playButton.getToggleState ();
      playButton.setButtonText (isPlaying ? "Playing" : "Stopped");
    };
  addAndMakeVisible (playButton);

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
  frequencyLabel.setBounds (getWidth () / 2 - 50, getHeight () / 2 - 120, 100,
                            20);
  frequencySlider.setBounds (getWidth () / 2 - 50, getHeight () / 2 - 100, 100,
                             200);
  playButton.setBounds (getWidth () / 2 - 50, getHeight () / 2 + 120, 100, 20);
}
