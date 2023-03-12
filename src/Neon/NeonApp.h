#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

	class NeonApp
	{
	public:
		NeonApp();
		~NeonApp();

		void OnInitialize(function<void()> onInitialize);
		void OnUpdate(function<void()> onUpdate);
		void OnTerminate(function<void()> onTerminate);

		void Run();
		
		NeonWindow* CreateNeonWindow(int width, int height, const char* title);

		inline const string& GetResourceRoot() const { return resourceRoot; }
		inline void SetResourceRoot(const string& root) { resourceRoot = root; }

	protected:

	private:
		function<void()> onInitializeFunction;
		function<void()> onUpdateFunction;
		function<void()> onTerminateFunction;

		list<NeonWindow*> windows;

		string resourceRoot;
	};

}