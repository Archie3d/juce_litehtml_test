#include "MainComponent.h"

MainComponent::MainComponent()
    : webView(),
      webPage (&webView)
{
    addAndMakeVisible (webView);

    MessageManager::callAsync([this]() {
        webPage.loadFromURL (String ("file:///index.html"));
    });

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    const auto bounds { getLocalBounds() };
    webView.setBounds (bounds);
}
