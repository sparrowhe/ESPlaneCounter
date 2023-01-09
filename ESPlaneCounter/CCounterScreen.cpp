#include "pch.h"
#include "CCounterScreen.h"

void CCounterScreen::OnFlightPlanControllerAssignedDataUpdate(CFlightPlan FlightPlan,
	int DataType) {
	if (!FlightPlan.IsValid()) return;
	if (FlightPlan.GetState() == FLIGHT_PLAN_STATE_ASSUMED) {
		//if (!FlightPlan.GetFlightPlanData().IsReceived()) return;
		CFlightPlanData tempFPData = FlightPlan.GetFlightPlanData();
		std::string Callsign = FlightPlan.GetCallsign();
		std::string DEPA = tempFPData.GetOrigin();
		std::string ARRA = tempFPData.GetDestination();
		std::string msg = "http://127.0.0.1:9901/rep?" + Callsign + "_" + DEPA + "_" + ARRA;
		sion::Fetch(msg);
		//assumedACFT.insert(AssumedACFT(FlightPlan.GetCallsign(), tempFPData.GetOrigin(), tempFPData.GetDestination()));
	}
}