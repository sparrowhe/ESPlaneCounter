#pragma once
#include "EuroScopePlugIn.h"
#include <string>
#include <set>
#include "AssumedACFT.h"
#include "sion.h"

using namespace EuroScopePlugIn;
class CCounterScreen :
    public EuroScopePlugIn::CRadarScreen
{
public:
	bool m_Opened;
	sion::Async thread_pool;
	std::set<AssumedACFT> assumedACFT;
	CCounterScreen(void) {
		m_Opened = true;
		thread_pool.Start();
	};
	virtual void OnAsrContentToBeClosed(void) {
		m_Opened = false;
		// delete will be done when attempting to access
	};
	virtual void OnFlightPlanControllerAssignedDataUpdate(CFlightPlan FlightPlan,
		int DataType);
};

