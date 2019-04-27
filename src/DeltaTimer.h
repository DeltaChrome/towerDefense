#pragma once

#include "DataTypes.h"

/**
PLEASE NOTE THIS IS MY FRIENDS DELTATIMER CLASS
UNFORTUNATELY THE CODE WAS TAKEN OFF OF GITHUB SO
THERE IS NO LONGER A LINK THAT I CAN DIRECT YOU TO

HERE IS A NEWER VERSION OF HIS CODE: https://github.com/D3ZOMBKEELA/NovaEngine/blob/master/Nova%20Engine/Nova%20Engine/DeltaTime.h

* The DeltaTimer class starts measuring time immediately and is intended for either profiling or measuring real-world time
*/
class DeltaTimer
{
public:
	explicit DeltaTimer(bool FPS = true);

	void Init();
	void Update();

	F32 GetDeltaTime();
	U32 GetCycleDifference();

	F32 CyclesToSeconds(U32 Cycles);
	U64 SecondsToCycles(F32 Seconds);

private:
	I64 StartTime;
	U32 CycleDifference;
	U32 CyclesPerSecond;
	bool FrameRateTimer;
};