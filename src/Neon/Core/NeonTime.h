#pragma once

#include <Neon/NeonCommon.h>

using namespace std::chrono;

namespace Neon {

	class NeonTime
	{
	public:
		static time_point<high_resolution_clock> Now();
		static double DeltaNano(const time_point<high_resolution_clock>& t);
		static double DeltaNano(const time_point<high_resolution_clock>& t0, const time_point<high_resolution_clock>& t1);

		static double DeltaMicro(const time_point<high_resolution_clock>& t);
		static double DeltaMicro(const time_point<high_resolution_clock>& t0, const time_point<high_resolution_clock>& t1);

		static double DeltaMili(const time_point<high_resolution_clock>& t);
		static double DeltaMili(const time_point<high_resolution_clock>& t0, const time_point<high_resolution_clock>& t1);


		NeonTime(const string& name);
		void Touch();
		void Stop();

	protected:
		string name;
		time_point<high_resolution_clock> startedTime;
		int touchCount = 0;
		time_point<high_resolution_clock> touchedTime;
	};

}