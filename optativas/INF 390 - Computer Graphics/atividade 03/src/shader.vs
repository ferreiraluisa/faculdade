#version 130
in vec3 Position;
uniform vec3 Color;
uniform mat4 ortho2d; //add
uniform mat4 model; //add
out vec4 vs_Color;
void main()
{
     // add
     gl_Position = ortho2d * model * vec4(Position, 1.0);
     vs_Color = vec4(Color.x, Color.y, Color.z, 1.0);
}
