/*
  ==============================================================================

    LowpassHighpassFilter.h
    Created: 19 Feb 2023 9:09:19am
    Author:  Luke Grayland

  ==============================================================================
*/

#pragma once

#include <vector>
#include "JuceHeader.h"

class LowpassHighpassFilter {
public:
  void setHighpass(bool highpass);
  void setCutoffFrequency(float cutoffFrequency);
  void setSamplingRate(float samplingRate);

  void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
  bool highpass;
  float cutoffFrequency;
  float samplingRate;

  // allpass filters' buffers: 1 sample per channel
  std::vector<float> dnBuffer;
};
