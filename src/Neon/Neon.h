#pragma once

#include <Neon/NeonCommon.h>

#include <Neon/Math/SBM.h>

namespace Neon {

	class Neon
	{
	public:
		Neon();
		~Neon();

		void Update(float timeDelta);

	protected:

	private:
		set<NeonSystem*> systems;
		set<NeonComponent*> components;
		set<NeonEntity*> entities;
	};

}
