/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "CCMouseEventDelegate.h"
#include "ccMacros.h"

namespace   cocos2d {

    //------------------------------------------------------------------
    //
    // CCMouseEventHandle
    //
    //------------------------------------------------------------------
    CCMouseEventDelegate* CCMouseEventHandle::getDelegate()
    {
        return m_pDelegate;
    }

    CCMouseEventHandle::~CCMouseEventHandle()
    {
        m_pDelegate->MouseDestroy();
    }

    void CCMouseEventHandle::setDelegate(CCMouseEventDelegate *pDelegate)
    {
        if (pDelegate)
        {
            pDelegate->MouseKeep();
        }

        if (m_pDelegate)
        {
            m_pDelegate->MouseDestroy();
        }
        m_pDelegate = pDelegate;
    }

    bool CCMouseEventHandle::initWithDelegate(CCMouseEventDelegate *pDelegate)
    {
        CCAssert(pDelegate != NULL, "It's a wrong delegate!");

        m_pDelegate = pDelegate;
        pDelegate->MouseKeep();

        return true;
    }

    CCMouseEventHandle* CCMouseEventHandle::handlerWithDelegate(CCMouseEventDelegate *pDelegate)
    {
        CCMouseEventHandle* pHandler = new CCMouseEventHandle;

        if (pHandler)
        {
            if (pHandler->initWithDelegate(pDelegate))
            {
                pHandler->autorelease();
            }
            else
            {
                CC_SAFE_RELEASE_NULL(pHandler);
            }
        }

        return pHandler;
    }

}
