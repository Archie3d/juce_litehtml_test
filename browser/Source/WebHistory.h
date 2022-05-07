#pragma once

#include "JuceHeader.h"

class WebHistory final
{
public:

    WebHistory();

    bool canGoBack() const;
    bool canGoForward() const;

    URL goBack();
    URL goForward();

    void setURL (const URL& url);

private:

    void truncate();

    std::vector<URL> urls{};
    size_t currentIndex { 0 };
};
