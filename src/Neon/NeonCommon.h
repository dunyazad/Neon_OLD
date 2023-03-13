#pragma once

#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <vector>
using namespace std;

#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace Neon {
	class Neon;
	class NeonApp;
	class NeonWindow;
	class NeonTime;
	class NeonShader;

	class NeonEntity;
	class NeonComponent;
	class NeonSystem;

	typedef long NeonID;
}

#define SAFE_DELETE(x) if(x != nullptr) { delete x; x = nullptr; }
