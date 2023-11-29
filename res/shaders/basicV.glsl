#version 330 core

layout(location = 0) in vec3 lPos;

void main() {
    gl_Position = vec4(lPos.x, lPos.y, lPos.z, 1.0);
}