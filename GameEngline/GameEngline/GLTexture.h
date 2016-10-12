#pragma once
#include <GL/glew.h>
#include <boost/serialization/access.hpp>

struct GLTexture{
    GLuint id;
    int width;
    int height;
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & id & width & height;
	}
};
