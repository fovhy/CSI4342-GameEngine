#pragma once
#include "TextureCache.h"
#include <string>



class ResourceManager{
public:
    GLTexture getTexture(std::string texturePath);

	bool inited = false;
private:
     TextureCache textureCache;

};
