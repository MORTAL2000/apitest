#pragma once

#include "solutions/texturedquadssoln.h"
#include "framework/sparse_bindless_texarray.h"

// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
class TexturedQuadsGLSparseBindlessTextureArray : public TexturedQuadsSolution
{
public:
    TexturedQuadsGLSparseBindlessTextureArray();
    virtual ~TexturedQuadsGLSparseBindlessTextureArray() { }

    virtual bool Init(const std::vector<TexturedQuadsProblem::Vertex>& _vertices,
                      const std::vector<TexturedQuadsProblem::Index>& _indices,
                      const std::vector<TextureDetails*>& _textures,
                      size_t _objectCount);

    virtual void Render(const std::vector<Matrix>& _transforms);
    virtual void Shutdown();

    virtual std::string GetName() const { return "GLSBTA"; }
    virtual bool SupportsApi(EGfxApi _api) const override { return IsOpenGL(_api); }

private:
    GLuint mIndexBuffer;
    GLuint mVertexBuffer;
    GLuint mVertexArray;
    GLuint mProgram;
    GLuint mTransformBuffer;
    GLuint mTexAddressBuffer;
    GLuint mVAO;

    struct UniformLocations {
        GLuint ViewProjection;
        GLuint DrawID;
        UniformLocations() { memset(this, 0, sizeof(*this)); }
    } mUniformLocation;

    std::vector<Texture2D*> mTextures;

    TextureManager mTexManager;
};
