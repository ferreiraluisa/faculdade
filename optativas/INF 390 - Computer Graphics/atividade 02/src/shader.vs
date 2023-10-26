#version 130
in vec3 Position;
uniform vec3 Color;
uniform vec4 ortho2d; //add
out vec4 vs_Color;
void main()
{
     // add
     gl_Position = vec4((Position.x - ortho2d[0]) * ortho2d[1] - 1.0, (Position.y - ortho2d[2]) * ortho2d[3] - 1.0, Position.z, 1.0);
     vs_Color = vec4(Color.x, Color.y, Color.z, 1.0);
}
