#pragma once

#include <Neon/Core/NeonApp.h>
#include <Neon/Core/NeonWindow.h>
#include <Neon/Core/NeonTime.h>

namespace Neon {
	NeonApp::NeonApp(int width, int height, const string& windowTitle)
	{
		window = new NeonWindow(width, height, windowTitle);
	}

	NeonApp::~NeonApp()
	{
		SAFE_DELETE(window)
	}

	void NeonApp::OnInitialize(function<void()> onInitialize)
	{
		onInitializeFunction = onInitialize;
	}

	void NeonApp::OnUpdate(function<void(float)> onUpdate)
	{
		onUpdateFunction = onUpdate;
	}

	void NeonApp::OnTerminate(function<void()> onTerminate)
	{
		onTerminateFunction = onTerminate;
	}

	void NeonApp::Run()
	{
		bool appFinisihed = false;

		if (onInitializeFunction != nullptr)
		{
			onInitializeFunction();
		}

		NeonTime time("main");
		auto now = time.Now();
		auto lastTime = now;

		while (appFinisihed == false)
		{
			auto now = time.Now();
			auto timeDelta = time.DeltaMili(lastTime, now);

			appFinisihed = true;
			if (window->ShouldClose() == false)
			{
				appFinisihed = false;

				//window->MakeCurrent();
				window->ProcessEvents();

				if (onUpdateFunction != nullptr)
				{
					onUpdateFunction((float)timeDelta);
				}
			}

			window->SwapBuffers();

			lastTime = now;
		}

		if (onTerminateFunction != nullptr)
		{
			onTerminateFunction();
		}
	}
}
