#pragma once

#include <Neon/Core/NeonApp.h>
#include <Neon/Core/NeonWindow.h>
#include <Neon/Core/NeonTime.h>

namespace Neon {
	NeonApp::NeonApp()
	{
	}

	NeonApp::~NeonApp()
	{
		for (auto& window : windows)
		{
			SAFE_DELETE(window)
		}
	}

	void NeonApp::OnInitialize(function<void()> onInitialize)
	{
		onInitializeFunction = onInitialize;
	}

	void NeonApp::OnUpdate(function<void(NeonWindow*, float)> onUpdate)
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

		if (windows.empty())
		{
			cout << "You should create a NeonWindow to use NeonApp" << endl;
		}

		NeonTime time("main");
		auto now = time.Now();
		auto lastTime = now;

		while (appFinisihed == false)
		{
			auto now = time.Now();
			auto timeDelta = time.DeltaMili(lastTime, now);

			appFinisihed = true;
			for (auto& window : windows)
			{
				if (window->ShouldClose() == false)
				{
					appFinisihed = false;

					window->MakeCurrent();
					window->ProcessEvents();

					if (onUpdateFunction != nullptr)
					{
						onUpdateFunction(window, timeDelta);
					}

					window->SwapBuffers();
				}
			}

			lastTime = now;
		}

		if (onTerminateFunction != nullptr)
		{
			onTerminateFunction();
		}
	}

	NeonWindow* NeonApp::CreateNeonWindow(int width, int height, const char* title)
	{
		auto window = new NeonWindow(width, height, title);
		windows.push_back(window);
		return window;
	}
}
