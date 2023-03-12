#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {

    class NeonShader {
    public:
        NeonShader(const string& vertexPath, const string& fragmentPath);
        ~NeonShader();

        void use();
        void setInt(const string& name, int value);
        void setFloat(const string& name, float value);

    private:
        unsigned int m_ID;

        void checkCompileErrors(unsigned int shader, const string& type);
    };
 
}
