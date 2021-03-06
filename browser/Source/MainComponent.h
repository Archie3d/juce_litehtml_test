#pragma once

#include <JuceHeader.h>

#include "WebHistory.h"

class MainComponent : public juce::Component,
                      public juce_litehtml::WebPage::Client,
                      private Button::Listener,
                      private TextEditor::Listener
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

    void updateURLTextEditor();

    // juce::Button::Listener
    void buttonClicked (Button* button) override;

    // juce::TextEditor::Listener
    void textEditorReturnKeyPressed (TextEditor&) override;

    juce_litehtml::WebView webView;
    juce_litehtml::WebPage webPage;

    WebHistory webHistory;

    TextButton backButton;
    TextButton forwardButton;
    TextButton reloadButton;
    TextEditor urlTextEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
