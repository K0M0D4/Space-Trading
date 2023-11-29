#pragma once

#include "stb_image.h"

#include <string>

class Texture {
public:
    Texture();

    void load(const std::string& filepath, bool isPixelArt);

    unsigned int getID();

private:
    unsigned int m_texture{};

};
