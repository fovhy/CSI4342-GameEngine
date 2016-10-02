#pragma once
#include <vector>
#include "Vertex.h"
#include <glm/glm.hpp>

enum class GlyphSortType{
    NONE,
    FRONT_TO_BACK,
    BACK_TO_FRONT,
    TEXTURE
};

// this struct is simply a sprite for a squre
struct Glyph {
    Vertex topLeft;
    Vertex bottomLeft;
    Vertex topRight;
    Vertex bottomRight;

    GLuint texture;
    float depth;
};

class RenderBatch{
public:
    RenderBatch(GLuint offset, GLuint numVertices, GLuint texture)
        : offset(offset),
          numVertices(numVertices),
          texture(texture){}
    GLuint offset;
    GLuint numVertices;
    GLuint texture;
};

class SpriteBatch{
public:
    SpriteBatch();
    ~SpriteBatch();

    void init();

    void begin(GlyphSortType = GlyphSortType::TEXTURE);
    void end();

    void draw(const glm::vec4& destRect, const glm::vec4& uvRect, const GLuint& texture, const float& depth, const Color& color = Color(255, 255,255,255));

    void renderBatches();

    void sortGlyphs();

private:
    static bool compareFrontToBack(Glyph* a, Glyph* b){
        return a->depth < b->depth;
    }

    static bool compareBacktoFront(Glyph* a, Glyph* b){
        return b->depth < a->depth;
    }

    static bool compareTexture(Glyph* a, Glyph* b){
        return (a->texture > b-> texture);
    }

    void createVertexArray();
    void createRenderBatches();
    GlyphSortType sortType_;
    GLuint vbo_;
    GLuint vao_;
    std::vector<Glyph*> glyphs_;
    std::vector<RenderBatch> renderBatches_;


};
