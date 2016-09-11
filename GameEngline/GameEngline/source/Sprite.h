#pragma once
#include <GL/glew.h>
#include <cstddef>
#include "GLTexture.h"
#include "ResourceManager.h"
#include "Vertex.h"
#include <string>

class Sprite{
public:
    Sprite();
    ~Sprite();
    void init(float x, float y, float width, float height, std::string texturePath);
    void draw();

private:
    float x;
    float y;
    float width;
    float height;
    GLTexture texture;
    GLuint vboID = 0;
    ResourceManager spriteManager;

};
