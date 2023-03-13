#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

    class NeonWindow
    {
    public:
        NeonWindow(int width, int height, const string& title, NeonWindow* sharingWindow = nullptr);
        ~NeonWindow();

        bool ShouldClose();
        void MakeCurrent();
        void ProcessEvents();
        void Update(float timeDelta);
        void SwapBuffers();

        inline void UseVSync(bool use) { vSync = use; glfwSwapInterval(use ? 1 : 0); }
        inline bool IsUsingVSync() const { return vSync; }

    private:
        GLFWwindow* glfwWindow = nullptr;
        bool vSync = true;
    };

}
