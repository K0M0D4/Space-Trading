#version 330 core

out vec4 FragColor;

in vec2 shTexCoord;

uniform vec4 inColor;
uniform sampler2D inTexture;
uniform int enableTexture;

void main() {
    if(enableTexture != 0) {
        FragColor = texture(inTexture, shTexCoord) * inColor;
    } else {
        FragColor = inColor;
    }
}
