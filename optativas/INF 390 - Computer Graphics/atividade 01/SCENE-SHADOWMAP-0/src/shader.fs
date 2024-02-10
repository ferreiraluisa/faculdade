#version 330

struct LightProperties {
   bool isEnabled;
   bool isLocal;
   bool isSpot;
   vec3 ambient;
   vec3 color;
   vec3 position;
   vec3 coneDirection;
   float spotCosCutoff;
   float spotExponent;
   float constantAttenuation;
   float linearAttenuation;
   float quadraticAttenuation;
};

out vec4 FragColor;
in vec4 vs_Color;
in vec3 vs_Normal;
in vec4 vs_Position;
in vec2 vs_TexCoord;



// the set of lights to apply, per invocation of this shader
const int MaxLights = 8;
uniform LightProperties Lights[MaxLights];

uniform float Shininess;
uniform float Strength;
uniform sampler2D gSampler;
//0 NO TEXTURE, 1 REPLACE, 2 MODULATE
uniform int Texture_combiner;


void main()
{
    vec3 EyeDirection = normalize(vec3(0.0,0.0,0.0) - vec3(vs_Position));
    
    vec3 scatteredLight = vec3(0.0); // or, to a global ambient light
    vec3 reflectedLight = vec3(0.0);
   // loop over all the lights
   for (int light = 0; light < MaxLights; ++light) {
      if (! Lights[light].isEnabled)
         continue;
      vec3 halfVector;
      vec3 lightDirection = Lights[light].position;
      float attenuation = 1.0;
      // for local lights, compute per-fragment direction,
      // halfVector, and attenuation
      if (Lights[light].isLocal) {
         lightDirection = lightDirection - vec3(vs_Position);
         float lightDistance = length(lightDirection);
         lightDirection = lightDirection / lightDistance;
         attenuation = 1.0 /(Lights[light].constantAttenuation + Lights[light].linearAttenuation* lightDistance + Lights[light].quadraticAttenuation * lightDistance* lightDistance);

         if (Lights[light].isSpot) {
            float spotCos = dot(lightDirection,-Lights[light].coneDirection);
            if (spotCos < Lights[light].spotCosCutoff)
               attenuation = 0.0;
            else
            attenuation *= pow(spotCos,Lights[light].spotExponent);
         }
         halfVector = normalize(lightDirection + EyeDirection);
      } else {
         halfVector = normalize(normalize(lightDirection) + EyeDirection);
      }
      float diffuse = max(0.0, dot(vs_Normal, lightDirection));
      float specular = max(0.0, dot(vs_Normal, halfVector));
      if (diffuse == 0.0)
         specular = 0.0;
      else
         specular = pow(specular, Shininess) * Strength;
      // Accumulate all the lights’ effects
      scatteredLight += Lights[light].ambient * attenuation + Lights[light].color * diffuse * attenuation;
      reflectedLight += Lights[light].color * specular * attenuation;
   }

   vec3 rgb = min(vs_Color.rgb * scatteredLight + reflectedLight,vec3(1.0));
   vec3 texel = texture2D(gSampler, vs_TexCoord.st).rgb;
   if (Texture_combiner == 0){
      FragColor = vec4(rgb,1.0);
   }else if (Texture_combiner == 1){
      FragColor = vec4(texel,1.0);
   }else{
      FragColor = vec4( min(texel * scatteredLight + reflectedLight,vec3(1.0)),1.0);
   }
   

}
