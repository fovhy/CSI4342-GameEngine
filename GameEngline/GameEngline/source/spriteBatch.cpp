#include "spriteBatch.h"
#include <algorithm>


SpriteBatch::SpriteBatch(){
	
}
SpriteBatch::~SpriteBatch(){

}

void SpriteBatch::init(){
    createVertexArray();
}

void SpriteBatch::begin(GlyphSortType sortType){
    sortType_ = sortType;
    renderBatches_.clear();
    for(int i = 0; i < glyphs_.size(); ++i){
        delete glyphs_[i];
    }
    glyphs_.clear();
}
void SpriteBatch::end(){
    sortGlyphs();
    createRenderBatches();
}
void SpriteBatch::sortGlyphs(){
    switch(sortType_){
    case GlyphSortType::BACK_TO_FRONT:
        std::stable_sort(glyphs_.begin(), glyphs_.end(), compareBacktoFront);
        break;
    case GlyphSortType::FRONT_TO_BACK:
        std::stable_sort(glyphs_.begin(), glyphs_.end(), compareFrontToBack);
        break;
    case GlyphSortType::TEXTURE:
        std::stable_sort(glyphs_.begin(), glyphs_.end(), compareTexture);
        break;
    }
}

void SpriteBatch::draw(const glm::vec4& destRect, const glm::vec4& uvRect, const GLuint& texture, 
	const float& depth, const Color& color){
    Glyph* newGlyph = new Glyph;
    newGlyph->texture = texture;
    newGlyph->depth = depth;

    newGlyph->topLeft.color = color;
    newGlyph->topLeft.setPosition(destRect.x, destRect.y + destRect.w);
    newGlyph->topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

    newGlyph->bottomLeft.color = color;
    newGlyph->bottomLeft.setPosition(destRect.x, destRect.y);
    newGlyph->bottomLeft.setUV(uvRect.x, uvRect.y);

    newGlyph->bottomRight.color = color;
    newGlyph->bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
    newGlyph->bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

    newGlyph->topRight.color = color;
    newGlyph->topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
    newGlyph->topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);

    glyphs_.push_back(newGlyph);

}

void SpriteBatch::renderBatches(){

    glBindVertexArray(vao_);
    for(int i = 0; i < renderBatches_.size(); i++){
        glBindTexture(GL_TEXTURE_2D, renderBatches_[i].texture);

        glDrawArrays(GL_TRIANGLES, renderBatches_[i].offset, renderBatches_[i].numVertices);

    }

    glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches(){
    // This vector will store all vertices
    std::vector <Vertex> vertices;

    vertices.resize(glyphs_.size() * 6);

    if(glyphs_.empty())
        return;
    int offset = 0;
    int counter = 0;

    renderBatches_.emplace_back(offset, 6, glyphs_[0]->texture);

    vertices[counter++] = glyphs_[0]->topLeft;
    vertices[counter++] = glyphs_[0]->bottomLeft;
    vertices[counter++] = glyphs_[0]->bottomRight;
    vertices[counter++] = glyphs_[0]->bottomRight;
    vertices[counter++] = glyphs_[0]->topRight;
    vertices[counter++] = glyphs_[0]->topLeft;

    offset += 6;

    for(int i = 1; i < glyphs_.size(); ++i){
        if(glyphs_[i]->texture != glyphs_[i-1]->texture){
            renderBatches_.emplace_back(offset, 6, glyphs_[i]->texture);
        }else{
            renderBatches_.back().numVertices += 6;
        }
        vertices[counter++] = glyphs_[i]->topLeft;
        vertices[counter++] = glyphs_[i]->bottomLeft;
        vertices[counter++] = glyphs_[i]->bottomRight;
        vertices[counter++] = glyphs_[i]->bottomRight;
        vertices[counter++] = glyphs_[i]->topRight;
        vertices[counter++] = glyphs_[i]->topLeft;
        offset+=6;
    }
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

    glBindBuffer(GL_ARRAY_BUFFER, 0);


}

void SpriteBatch::createVertexArray(){
    if(vao_ == 0){
        glGenVertexArrays(1, &vao_);
    }
    glBindVertexArray(vao_);
    if(vbo_ == 0){
        glGenBuffers(1, &vbo_);
    }
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    // this is position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

    // This is the color attribute pointer

    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    // this is for uv attribute

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    glBindVertexArray(0);

}
