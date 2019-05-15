#pragma once

#include "Bang/Array.h"
#include "Bang/BangDefines.h"
#include "BangGraphics/GL.h"
#include "BangGraphics/GLObject.h"

namespace Bang
{
class IBO;
class VBO;

class VAO : public GLObject
{
public:
    VAO();
    virtual ~VAO() override;

    void Bind() const override;
    void UnBind() const override;

    void SetVBO(const VBO *vbo,
                uint location,
                uint dataComponentsCount,
                GL::VertexAttribDataType dataType,
                bool dataNormalized = false,
                uint dataStride = 0,
                uint dataOffset = 0);
    void SetVertexAttribDivisor(uint location, uint divisor);
    void SetIBO(IBO *ibo);

    void RemoveVBO(uint location);

    IBO *GetIBO() const;
    bool IsIndexed() const;
    int GetVBOCount() const;
    GL::BindTarget GetGLBindTarget() const override;
    const VBO *GetVBOByLocation(uint location) const;

private:
    Array<const VBO *> p_vbos;
    IBO *p_ibo = nullptr;
};
}
