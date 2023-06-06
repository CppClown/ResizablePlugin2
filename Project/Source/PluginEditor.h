/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ResizablePluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ResizablePluginAudioProcessorEditor (ResizablePluginAudioProcessor&);
    ~ResizablePluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ResizablePluginAudioProcessor& audioProcessor;

    // Counts how often the resized() was called.
    int mNumberOfCallsToResized { 0 };
    juce::TextEditor mTextEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ResizablePluginAudioProcessorEditor)
};
