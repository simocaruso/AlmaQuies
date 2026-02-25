#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D al_tex;
uniform vec2 tex_size;     // Size of the texture (width, height)
uniform vec4 outline_color;     // Size of the texture (width, height)
varying vec2 varying_texcoord;

void main() {
    // Get the color of the current pixel
    vec4 current_color = texture2D(al_tex, varying_texcoord.xy);
    float is_colored = sign(current_color.a);

    // Check neighbors
    float step_x = 1.0 / tex_size.x; // size of 1 pixel in UV coordinates
    float step_y = 1.0 / tex_size.y;

    // Check 4 neighbors (up, down, left, right)
    float alpha_up    = texture2D(al_tex, varying_texcoord.xy + vec2(0.0, -step_y)).a;
    float alpha_down  = texture2D(al_tex, varying_texcoord.xy + vec2(0.0, step_y)).a;
    float alpha_left  = texture2D(al_tex, varying_texcoord.xy + vec2(-step_x, 0.0)).a;
    float alpha_right = texture2D(al_tex, varying_texcoord.xy + vec2(step_x, 0.0)).a;

    float is_border = 1.0 - min(alpha_down, min(alpha_left, min(alpha_right, alpha_up)));

    gl_FragColor = outline_color * is_border * is_colored;
}