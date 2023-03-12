#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

    class NeonWindow
    {
    public:
        NeonWindow(int width, int height, const char* title);
        ~NeonWindow();

        bool shouldClose();
        void processEvents();
        void swapBuffers();

    private:
        GLFWwindow* m_Window;
    };

}
