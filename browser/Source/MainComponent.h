#pragma once

#include <JuceHeader.h>

#include "WebHistory.h"

class MainComponent : public juce::Component,
                      public juce_litehtml::WebPage::Client,
                      private Button::Listener
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    // juce_litehtml::WebPage::Client
    bool followLink (const URL& url) override;

private:

    void updateButtonsState();

    // juce::Button::Listener
    void buttonClicked (Button* button) override;

    juce_litehtml::WebView webView;
    juce_litehtml::WebPage webPage;

    WebHistory webHistory;

    TextButton backButton;
    TextButton forwardButton;
    TextEditor urlTextEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
