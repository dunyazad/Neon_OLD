#pragma once

#include <Neon/NeonCommon.h>

namespace Neon {
    class V2 {
    public:
        V2();
        V2(float x, float y);
        ~V2();

    ostream& operator << (ostream& outputStream);

//    protected:
        float x = 0.0f;
        float y = 0.0f;
    };
}

ostream& operator<<(ostream& outputStream, Neon::V2& v2);