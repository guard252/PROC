#pragma once
#include <iostream>
#include <glew/glew.h>
#ifdef _DEBUG
#define EnableDebugOutput() glEnable( GL_DEBUG_OUTPUT );\
                            glDebugMessageCallback(CustomDebugCallback, 0)
#else 
#define EnableDebugOutput()
#endif

#ifdef _DEBUG
#define GLCall(x)\
    GLClearError();\
    x;\
    {\
        if(GLenum err; (err = glGetError()) != GL_NO_ERROR)\
        {\
            std::cout << "Error code: " << err << '\n' <<\
                         "Line: " << __LINE__ << '\n' <<\
                         "File: " << __FILE__ << '\n' <<\
                         "Called by: " << #x << '\n';\
            __debugbreak();\
        }\
    }
#else 
#define GLCall(x) x;
#endif
    

inline void CustomDebugCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    using namespace std;
    cout << "---------------------opengl-callback-start------------" << endl;
    cout << "message: " << message << endl;
    cout << "type: ";
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        cout << "ERROR";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        cout << "DEPRECATED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        cout << "UNDEFINED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        cout << "PORTABILITY";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        cout << "PERFORMANCE";
        break;
    case GL_DEBUG_TYPE_OTHER:
        cout << "OTHER";
        break;
    }
    cout << endl;

    cout << "id: " << id << endl;
    cout << "severity: ";
    switch (severity) {
    case GL_DEBUG_SEVERITY_LOW:
        cout << "LOW";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        cout << "MEDIUM";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        cout << "HIGH";
        break;
    }
    cout << endl;
    cout << "---------------------opengl-callback-end--------------\n\n";
}

inline void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}