/*
  ==============================================================================

    LowpassFilter.cpp
    Created: 25 Feb 2023 2:35:05pm
    Author:  Luke Grayland

  ==============================================================================
*/

#include "LowpassFilter.h"

void LowpassFilter::setCutoffFrequency(float cutoffFrequency) {
    this->cutoffFrequency = cutoffFrequency;
}

void LowpassFilter::setSamplingRate(float samplingRate) {
    this->samplingRate = samplingRate;
}

void LowpassFilter::processBlock(juce::AudioBuffer<float>& audioBuffer, juce::MidiBuffer& midiBuffer) {
    
    dnBuffer.resize(audioBuffer.getNumChannels(), 0.f);
    
    constexpr float PI = 3.14159265359f;
    const float sign = 1.f;
    const auto tan = std::tan(PI * cutoffFrequency / samplingRate);
    const auto a1 = (tan - 1.f) / (tan + 1.f);
    
    for (int channel = 0; channel < audioBuffer.getNumChannels(); ++channel) {
        
        auto channelSamples = audioBuffer.getWritePointer(channel);
        
        for (int i = 0; i < audioBuffer.getNumSamples(); ++i) {
            
            auto inputSample = channelSamples[i];
            
            const auto allpassFilteredSample = a1 * inputSample + dnBuffer[channel];
              
            dnBuffer[channel] = inputSample - a1 * allpassFilteredSample;

            const auto filterOutput = 0.5f * (inputSample + sign * allpassFilteredSample);

            channelSamples[i] = filterOutput;
        }
    }
}
