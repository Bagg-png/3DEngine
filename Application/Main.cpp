#include "Engine.h"
#include <glad/glad.h>
#include <sdl.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <iostream>

//Renderer.h
// delete #include texture
//#include <glad/glad.h>
//if not go to Engine and check additional include directories
// private:
// SDL_GLContext context;
// 
// Renderer.cpp
//
//include <SDL_image.h>
//Shutdown()
// SDL_GL_DeleteContext(context)
//SDL_DestroyWindow(window);
//IMG_Quit()
//TTF_QUIT()
//SDL_QUIT()

//Create()
// window = ( ?, ?, ?, SDL_WINDOW_OPENGL)

//Enigine Main
//Copy sdl_GL_SetAtributes to renderer.cpp Create()
//delete sdl context

//Renderer.cpp
//BegineFrame()
//glClearColor(0,0,0,1);
//glClear(GL_COLOR_BUFFER_BIT);
// 
// Endframe()
// SDL_GL_SwapWindow(window);
// 
// main.cpp (this) delete everything before vertex shader
// 
// Add Existing Item (glad.c) to graphics
// thirdparty/glad/src/glad.c

// vertices
//const float vertices[] =
//{
//    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
//    -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f
//};
//
//const GLuint indices[] =
//{
//    0, 2, 1,
//    0, 3, 2
//};

// vertex shader
const char* vertexSource = R"(
    #version 430 core 
    layout(location = 0) in vec3 position;
    layout(location = 1) in vec3 color;

    out vec3 fs_color;
    uniform float scale;

    void main()
    {
        fs_color = color;
        gl_Position = vec4(position * scale, 1.0);
    }
)";



// fragment
const char* fragmentSource = R"(
    #version 430 core
    in vec3 fs_color;
    out vec4 outColor;
 
    uniform vec3 tint;

    void main()
    {
        outColor = vec4(fs_color, 1.0) * vec4(tint, 1.0);
    }
)";



int main(int argc, char** argv)
{
    /*int result = SDL_Init(SDL_INIT_VIDEO);
    if (result != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }



    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    if (window == nullptr)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }



    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    


    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetSwapInterval(1);



    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!gladLoadGL())
    {
        SDL_Log("Failed to create OpenGL context");
        exit(-1);
    }*/

    ag::Engine engine;
    engine.StartUp();
    engine.Get<ag::Renderer>()->Create("OpenGL", 800, 600);



   ag::SeedRandom(static_cast<unsigned int>(time(nullptr)));
   ag::SetFilePath("../resources");

    // set vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);



    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        char buffer[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        std::cout << buffer;
    }



    // set fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);



    GLint status;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        char buffer[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
        std::cout << buffer;
    }



    // create shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);


    //
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //vertex array
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //create vertedc buffer
    GLuint vbo;
    glGenBuffers(1, &vbo);


    //
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //set vertex data into the vertex buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint ebo; //element buffer object
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    //color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //uniform
    GLuint location = glGetUniformLocation(shaderProgram, "scale");
    float time = 0;

    GLuint tintLocation = glGetUniformLocation(shaderProgram, "tint");
    glm::vec3 tint{ 1.0f, 0.5f, 0.5f };

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);



        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }
        }



        SDL_PumpEvents();
        

        time += 0.0001f;
        glUniform1f(location, std::sin(time));
        glUniform3fv(tintLocation, 1, &tint[0]);

        engine.Get<ag::Renderer>()->BeginFrame();
        //glClearColor(0.85f, 0.85f, 0.85f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glDrawArrays(GL_LINES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        engine.Get<ag::Renderer>()->EndFrame();
    }


    return 0;
}