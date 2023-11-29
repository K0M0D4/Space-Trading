#include "Texture.hpp"

#include <glad/glad.h>

#include <iostream>

Texture::Texture() {

}

void Texture::load(const std::string& filepath, bool isPixelArt) {
    int width;
    int height;
    int nrChannels;

    stbi_set_flip_vertically_on_load(true);

    unsigned char* data{stbi_load(filepath.c_str(), &width, &height,
        &nrChannels, 0)};
    
    if(data) {
        glGenTextures(1, &m_texture);

        glBindTexture(GL_TEXTURE_2D, m_texture);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Error: Failed to load texture: " << filepath << '\n';
    }

    stbi_image_free(data);

    if(isPixelArt) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
}

unsigned int Texture::getID() {
    return m_texture;
}
