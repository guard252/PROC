//#pragma once
//#include <cassert> 
//#include <vector>
//#include <glew/glew.h>
//#include "../Types.h"
//namespace GFX
//{
//    struct LayoutElement {
//        GLuint count;
//        GLuint type;
//        GLuint normalized;
//        GLuint type_size;
//    };
//
//    class VertexLayout {
//    private:
//        std::vector<LayoutElement> elements;
//        GLuint stride{ 0 };
//    public:
//        template<typename T>
//        void Push(GLuint count, GLuint normalized = GL_FALSE)
//        {
//            elements.push_back(LayoutElement{ count, ApiType<T>(), normalized, sizeof(T) });
//            stride += count * sizeof(T);
//        }
//
//
//
//        GLuint GetStride() const { return stride; }
//
//        const std::vector<LayoutElement>& GetElements() const { return elements; }
//    };
//
//   
//}
//
//
