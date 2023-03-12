#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

    class NeonShader {
    public:
        NeonShader(const char* vertexPath, const char* fragmentPath);
        ~NeonShader();

        void use();
        void setInt(const char* name, int value);
        void setFloat(const char* name, float value);

    private:
        unsigned int m_ID;

        void checkCompileErrors(unsigned int shader, const char* type);
    };
 
}
