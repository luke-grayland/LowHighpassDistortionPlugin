//
//  LowpassHighpassFilter.cpp
//  LowpassHighpassFilter - AU
//
//  Created by Luke Grayland on 18/02/2023.
//  Copyright © 2023 LazyGrayPlugins. All rights reserved.
//

#include "LowpassHighpassFilter.hpp"

void LowpassHighpassFilter::setHighpass(bool highpass) {
    this->highpass = highpass;
};

void LowpassHighpassFilter::setCutoffFrequency(float cutoffFrequency) {
    this->cutoffFrequency = cutoffFrequency;
};

void LowpassHighpassFilter::setSamplingRate(float samplingRate) {
    this->samplingRate = samplingRate;
};

void LowpassHighpassFilter::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    constexpr auto PI = 3.141592653589f;
    dnBuffer.resize(buffer.getNumChannels(), 0.f); //resizes all pass buffer to numebr of channels
    const auto sign = highpass ? -1.f : 1.f;
    
    const auto tan = std::tan(PI * cutoffFrequency / samplingRate);
    const auto a1 = (tan - 1.f) / (tan + 1.f);
    
    for (auto channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto channelSamples = buffer.getWritePointer(channel);
        for (auto i = 0; buffer.getNumSamples(); ++i)
        {
            const auto inputSample = channelSamples[i];
            const auto allpassFilteredSample = a1 * inputSample + dnBuffer[channel];
            
            const auto filterOutput = 0.5f * (inputSample + sign * allpassFilteredSample);
            
            channelSamples[i] = filterOutput;
        }
    }
};
