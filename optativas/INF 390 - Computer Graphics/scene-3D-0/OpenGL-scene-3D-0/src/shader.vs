#version 130
in vec3 Position;
uniform vec3 Color;
uniform mat4 Ortho2D;
uniform mat4 Model;
out vec4 vs_Color;
void main()
{
     gl_Position = Ortho2D*Model*vec4(Position, 1.0);
     vs_Color = vec4(Color.x,Color.y, Color.z, 1.0);

}