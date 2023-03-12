#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

	class NeonApp
	{
	public:
		NeonApp();
		~NeonApp();

		void OnInitialize(function<void()> initialize);
		void OnFrame(function<void()> frame);
		void OnTerminate(function<void()> terminate);

		void Run();
		
		NeonWindow* CreateNeonWindow(int width, int height, const char* title);
	protected:

	private:
		function<void()> onInitializeFunction;
		function<void()> onFrameFunction;
		function<void()> onTerminateFunction;

		list<NeonWindow*> windows;
	};

}