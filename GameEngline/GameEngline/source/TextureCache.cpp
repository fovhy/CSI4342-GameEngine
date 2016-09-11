#include "TextureCache.h"
#include "ImageLoader.h"


 GLTexture TextureCache::getTexture(std::string texturePath){
        //find the texture
        auto iterator = textureMap.find(texturePath);
        if(iterator == textureMap.end()){
            GLTexture newTexture = ImageLoader::loadPNG(texturePath);
            textureMap.insert(make_pair(texturePath, newTexture));
            return newTexture;
        }
        return iterator->second;
    }
