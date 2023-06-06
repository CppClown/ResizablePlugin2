/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
using namespace juce;


//==============================================================================
ResizablePluginAudioProcessorEditor::ResizablePluginAudioProcessorEditor (ResizablePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //-------- Text editor.

    mTextEditor.setReadOnly(true);
    mTextEditor.setFont(Font("Consolas", 16.f, Font::FontStyleFlags::plain));
    mTextEditor.setMultiLine(true);
    addAndMakeVisible(mTextEditor);

    //-------- Set size and limits.
   
    const auto minWidth = 500.f;
    const auto minHeight = 375.f;
    const auto maxWidth = 1240.f;
    const auto maxHeight = 930.f;
    
    setResizable(false, true);
    
    if (auto componentBoundsConstrainer = getConstrainer())
    {
        componentBoundsConstrainer->setSizeLimits(
            roundToInt(minWidth), roundToInt(minHeight),
            roundToInt(maxWidth), roundToInt(maxHeight));

        componentBoundsConstrainer->setFixedAspectRatio(4.f / 3.f);
    }
    
    setSize(minWidth, minHeight);
}

ResizablePluginAudioProcessorEditor::~ResizablePluginAudioProcessorEditor()
{
}

//==============================================================================
void ResizablePluginAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void ResizablePluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    mNumberOfCallsToResized++;

    mTextEditor.setBounds(getLocalBounds());
    mTextEditor.insertTextAtCaret("Calls to resized(): " + String(mNumberOfCallsToResized) 
        + ", approximateScaleFactor = " + String(getApproximateScaleFactorForComponent(this)));
    mTextEditor.insertTextAtCaret("\n");
}
