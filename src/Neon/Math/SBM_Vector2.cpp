#include <Neon/Math/SBM_Vector2.h>

namespace Neon
{
    V2::V2()
    {
    }

    V2::V2(float x, float y)
    : x(x), y(y)
    {
    }

    V2::~V2()
    {   
    }

    ostream& V2::operator << (ostream& outputStream)
    {
        outputStream << "(" << this->x << ", " << this->y << ")";
        return outputStream;
    }
}

ostream& operator<<(ostream& outputStream, Neon::V2& v2)
{
    outputStream << "(" << v2.x << ", " << v2.y << ")";
    return outputStream;
}
