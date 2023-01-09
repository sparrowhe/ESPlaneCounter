#pragma once

#include <stack>
#include <set>

#include "EuroScopePlugIn.h"

#include "CCounterScreen.h"
#include "AssumedACFT.h"

using namespace EuroScopePlugIn;
class CPlaneCounter :
    public EuroScopePlugIn::CPlugIn
{
public:
    CPlaneCounter(void);
    virtual CRadarScreen* OnRadarScreenCreated(const char* sDisplayName, bool NeedRadarContent, bool GeoReferenced, bool CanBeSaved, bool CanBeCreated);
    std::stack<CCounterScreen*> m_ScreenStack;
};



