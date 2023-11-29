#version 330 core

layout(location = 0) in vec3 lPos;
layout(location = 1) in vec2 lTexCoord;

out vec2 shTexCoord;

void main() {
    gl_Position = vec4(lPos.x, lPos.y, lPos.z, 1.0);
    shTexCoord = lTexCoord;
}