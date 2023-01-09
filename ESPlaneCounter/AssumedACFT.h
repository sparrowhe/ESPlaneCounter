#pragma once
#include <string>
class AssumedACFT
{
public:
	const char * Callsign;
	const char * DEPA;
	const char * ARRA;
	bool operator < (const AssumedACFT& b)const {
		if (strcmp(Callsign,b.Callsign) == 0) return false;
	}
};

