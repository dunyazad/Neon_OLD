#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

	class NeonApp
	{
	public:
		NeonApp(int width = 1024, int height = 768, const string& windowTitle = "NeonApp");
		~NeonApp();

		void OnInitialize(function<void()> onInitialize);
		void OnUpdate(function<void(float)> onUpdate);
		void OnTerminate(function<void()> onTerminate);

		void Run();
		
		inline const string& GetResourceRoot() const { return resourceRoot; }
		inline void SetResourceRoot(const string& root) { resourceRoot = root; }

	protected:

	private:
		function<void()> onInitializeFunction;
		function<void(float)> onUpdateFunction;
		function<void()> onTerminateFunction;

		NeonWindow* window = nullptr;

		string resourceRoot;

		map<NeonID, NeonEntity*> entities;
		map<NeonID, NeonComponent*> components;
		map<NeonID, NeonSystem*> systems;
	};

}
