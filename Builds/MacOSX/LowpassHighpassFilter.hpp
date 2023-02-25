//
//  LowpassHighpassFilter.hpp
//  LowpassHighpassFilter - AU
//
//  Created by Luke Grayland on 18/02/2023.
//  Copyright © 2023 LazyGrayPlugins. All rights reserved.
//

#ifndef LowpassHighpassFilter_hpp
#define LowpassHighpassFilter_hpp

#include <stdio.h>
#include <vector>
#include "JuceHeader.h"

class LowpassHighpassFilter
{
public:
    void setHighpass(bool highpass);
    void setCutoffFrequency(float cutoffFrequency);
    void setSamplingRate(float samplingRate);
    
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&);
    
private:
    bool highpass;
    float cutoffFrequency;
    float samplingRate;
    std::vector<float> dnBuffer;
};


#endif /* LowpassHighpassFilter_hpp */
