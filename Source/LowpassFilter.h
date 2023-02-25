/*
  ==============================================================================

    LowpassFilter.h
    Created: 25 Feb 2023 2:35:05pm
    Author:  Luke Grayland

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class LowpassFilter {
    
public:
    void setCutoffFrequency(float cutoffFrequency);
    void setSamplingRate(float samplingrate);
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);
    
private:
    float cuttoffFrequency;
    float samplingRate;
    std::vector<float> dnBuffer;
};
