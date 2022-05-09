#include "MainComponent.h"

MainComponent::MainComponent()
    : webView(),
      webPage(),
      backButton ("<"),
      forwardButton (">"),
      reloadButton ("O")
{
    backButton.addListener (this);
    forwardButton.addListener (this);
    reloadButton.addListener (this);
    urlTextEditor.addListener (this);

    webView.setPage(&webPage);
    addAndMakeVisible (webView);
    addAndMakeVisible (backButton);
    addAndMakeVisible (forwardButton);
    addAndMakeVisible (reloadButton);
    addAndMakeVisible (urlTextEditor);

    webPage.setClient (this);

    MessageManager::callAsync([this]() {
        webPage.getLoader().purgeCache();
        webPage.followLink (URL ("https://en.wikipedia.org/wiki/Main_Page"));
    });

    setSize (800, 600);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (Colour (0x66, 0x66, 0x66));
}

void MainComponent::resized()
{
    auto bounds { getLocalBounds() };
    auto navigationBarBounds { bounds.removeFromTop (32) };
    navigationBarBounds.reduce (4, 4);

    backButton.setBounds (navigationBarBounds.removeFromLeft (24));
    navigationBarBounds.removeFromLeft (4);
    forwardButton.setBounds (navigationBarBounds.removeFromLeft (24));
    navigationBarBounds.removeFromLeft (24);
    navigationBarBounds.removeFromRight (28);
    reloadButton.setBounds(navigationBarBounds.removeFromRight (24));
    navigationBarBounds.removeFromRight (4);
    urlTextEditor.setBounds (navigationBarBounds);

    webView.setBounds (bounds);
}

bool MainComponent::followLink (const URL& url)
{
    webHistory.setURL (url);
    urlTextEditor.setText (url.toString (true), false);

    updateButtonsState();

    return true;
}

void MainComponent::updateButtonsState()
{
    backButton.setEnabled (webHistory.canGoBack());
    forwardButton.setEnabled (webHistory.canGoForward());
}

void MainComponent::updateURLTextEditor()
{
    urlTextEditor.setText (webPage.getURL().toString (true), false);
}

void MainComponent::buttonClicked (Button* button)
{
    if (button == &backButton)
        webPage.loadFromURL (webHistory.goBack());
    else if (button == &forwardButton)
        webPage.loadFromURL (webHistory.goForward());
    else if (button == &reloadButton)
    {
        // Force reload purging the load cache
        webPage.getLoader().purgeCache();
        webPage.reload();
    }

    updateButtonsState();
    updateURLTextEditor();
}

void MainComponent::textEditorReturnKeyPressed (TextEditor&)
{
    webPage.followLink (URL (urlTextEditor.getText()));
}
