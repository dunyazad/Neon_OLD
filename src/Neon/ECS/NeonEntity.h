#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

	class NeonEntity
	{
	public:
		NeonEntity();
		~NeonEntity();

	protected:
		NeonID id;

	private:
		static NeonID entityID;
	};

}