#pragma once

#include <Neon/NeonApp.h>
#include <Neon/NeonWindow.h>

namespace Neon {
	NeonApp::NeonApp()
	{
	}

	NeonApp::~NeonApp()
	{
		for (auto& window : windows)
		{
			if (window != nullptr)
			{
				delete window;
				window = nullptr;
			}
		}
	}

	void NeonApp::OnInitialize(function<void()> onInitialize)
	{
		onInitializeFunction = onInitialize;
	}

	void NeonApp::OnUpdate(function<void()> onUpdate)
	{
		onUpdateFunction = onUpdate;
	}

	void NeonApp::OnTerminate(function<void()> onTerminate)
	{
		onTerminateFunction = onTerminate;
	}

	void NeonApp::Run()
	{
		onInitializeFunction();

		bool appFinisihed = false;

		if (windows.empty())
		{
			cout << "You should create a NeonWindow to use NeonApp" << endl;
		}

		while (appFinisihed == false)
		{
			appFinisihed = true;
			for (auto& window : windows)
			{
				if (window->shouldClose() == false)
				{
					appFinisihed = false;
					window->processEvents();

					onUpdateFunction();

					window->swapBuffers();
				}
			}
		}

		onTerminateFunction();
	}

	NeonWindow* NeonApp::CreateNeonWindow(int width, int height, const char* title)
	{
		auto window = new NeonWindow(width, height, title);
		windows.push_back(window);
		return window;
	}
}
