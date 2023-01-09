#include "pch.h"
#include "CPlaneCounter.h"
#include <string>
#include "CCounterScreen.h"

CPlaneCounter::CPlaneCounter(void)
    : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
        "Plane Counter Tool",
        "1.0.0",
        "Dezheng He & Rudi Zhang",
        "AGPLv3")
{
    // add your initialization here
    DisplayUserMessage("MESSAGE", "PlaneCounter",
        ("PlaneCounter plugin loaded! For more info please contact dezheng.he@rudicloud.com"),
        1, 0, 0, 0, 0);
}

CRadarScreen* CPlaneCounter::OnRadarScreenCreated(const char* sDisplayName, bool NeedRadarContent, bool GeoReferenced, bool CanBeSaved, bool CanBeCreated)
{
    CCounterScreen* screen = new CCounterScreen();
    m_ScreenStack.push(screen);
    return screen;
}

CPlaneCounter* pCounterPlugIn = NULL;

void __declspec (dllexport)
EuroScopePlugInInit(EuroScopePlugIn::CPlugIn** ppPlugInInstance)
{
    // allocate
    *ppPlugInInstance = pCounterPlugIn = new CPlaneCounter;
}

void __declspec (dllexport)
EuroScopePlugInExit(void)
{
    delete pCounterPlugIn;
}
