#version 130
out vec4 FragColor;
in vec4 vs_Color;
in vec3 vs_Normal;
in vec4 vs_Position;
uniform vec3 Ambient;
uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform float Shininess;
uniform float Strength;
void main()
{
    vec3 lightDirection = normalize(LightPosition - vec3(vs_Position));
    vec3 EyeDirection = normalize(vec3(0.0,0.0,0.0) - vec3(vs_Position));
    vec3 halfVector = normalize(lightDirection + EyeDirection);
    float diffuse = max(0.0, dot(vs_Normal, lightDirection));
    float specular = max(0.0, dot(vs_Normal, halfVector));
    if (diffuse == 0.0)
        specular = 0.0;
    else
        specular = pow(specular, Shininess) * Strength;
    vec3 scatteredLight = Ambient + LightColor * diffuse;
    vec3 reflectedLight = LightColor * specular;
    vec3 rgb = min(vs_Color.rgb * scatteredLight + reflectedLight, vec3(1.0));
    FragColor = vec4(rgb, vs_Color.a);
}
