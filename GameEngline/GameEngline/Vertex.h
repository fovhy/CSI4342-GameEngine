#pragma once
#include <GL/glew.h>
struct Position{
    float x;
    float y;
};

struct Color{
	Color() = default;  // still have a default constructor 
	Color(GLint r, GLint g, GLint b, GLint a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};
struct ColorRGBA8 {
	ColorRGBA8() : r(0), g(0), b(0), a(0) { }
	ColorRGBA8(GLubyte R, GLubyte G, GLubyte B, GLubyte A) :
		r(R), g(G), b(B), a(A) { }
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
};

struct UV{
    float u;
    float v;
};
struct Vertex{
    Position position;
    Color color;
    UV uv;

    void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a){
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }

    void setPosition(float x, float y){
        position.x = x;
        position.y = y;
    }

    void setUV(float u, float v){
        uv.u = u;
        uv.v = v;
    }
};


