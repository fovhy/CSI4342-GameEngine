#include "ResourceManager.h"

GLTexture ResourceManager:: getTexture(std::string texturePath){
	inited = true;
    return textureCache.getTexture(texturePath);
}
