#include "WebHistory.h"

WebHistory::WebHistory()
{
}

bool WebHistory::canGoBack() const
{
    if (urls.empty())
        return false;

    return currentIndex > 0;
}

bool WebHistory::canGoForward() const
{
    return currentIndex + 1 < urls.size();
}

URL WebHistory::goBack()
{
    if (canGoBack())
    {
        --currentIndex;
        return urls.at (currentIndex);
    }

    return {};
}

URL WebHistory::goForward()
{
    if (canGoForward())
    {
        ++currentIndex;
        return urls.at (currentIndex);
    }

    return {};
}

void WebHistory::setURL (const URL& url)
{
    if (urls.empty())
    {
        urls.push_back (url);
        currentIndex = 0;
        return;
    }

    truncate();
    urls.push_back (url);
    ++currentIndex;
}

void WebHistory::truncate()
{
    if (urls.empty())
    {
        currentIndex = 0;
        return;
    }

    urls.resize (currentIndex + 1);
}
