/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LowpassHighpassFilterAudioProcessorEditor::LowpassHighpassFilterAudioProcessorEditor (LowpassHighpassFilterAudioProcessor& p,
                                                                                      juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(cutoffFrequenySlider);
    cutoffFrequenySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    cutoffFrequencyAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(vts, "cutoff_frequency", cutoffFrequenySlider));
    
    addAndMakeVisible(cutoffFrequencyLabel);
    cutoffFrequencyLabel.setText("Cutoff Frequency", juce::dontSendNotification);
    
    addAndMakeVisible(highpassButton);
    highpassAttachment.reset(new juce::AudioProcessorValueTreeState::ButtonAttachment(vts, "highpass", highpassButton));
    
    addAndMakeVisible(highpassButtonlabel);
    highpassButtonlabel.setText("Highpass", juce::dontSendNotification);
    
    
    setSize (200, 400);
}

LowpassHighpassFilterAudioProcessorEditor::~LowpassHighpassFilterAudioProcessorEditor()
{
}

//==============================================================================
void LowpassHighpassFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void LowpassHighpassFilterAudioProcessorEditor::resized()
{
    cutoffFrequenySlider.setBounds(15, 35, 100, 300);
    cutoffFrequencyLabel.setBounds(cutoffFrequenySlider.getX() + 30, cutoffFrequenySlider.getY() - 30, 200, 50);
    
    highpassButton.setBounds(10, 10, 50, 100);
    highpassButtonlabel.setBounds(highpassButton.getX() + 5, highpassButton.getX() - 5, 50, 50);
}
