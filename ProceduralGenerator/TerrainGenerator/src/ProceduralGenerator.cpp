#include <iostream>
#include <string>

#include "Application/Application.h"
#include "Application/GUI/GUILayer.h"
#include "Logger/Logger.h"
#include "Application/GUI/GUIParameterSet.h"
#include "Application/GUI/GUIParameter.h"

#include "GFXPrimitives/ShaderProgram.h"
#include "GFXPrimitives/VertexArray.h"
#include "GFXPrimitives/VertexBuffer.h"

class TerrainGenApp : public Application
{
public:
	TerrainGenApp(std::string name) : Application(name) {}
    virtual void Run()
    {
		glClearColor(0.2, 0.3, 0.5, 1);
		float data[] = { -0.5, -0.5,
						  0,    0.8,
						  0.5, -0.5 };
		GFX::VertexBuffer buff(data, sizeof data);
		GFX::VertexArray vao;
		GFX::VertexLayout layout;
		layout.Push<float>(2);
		vao.AddBuffer(buff, layout);
		GFX::VertexShader vert("src/shaders/vertex.glsl");
		GFX::FragmentShader frag("src/shaders/fragment.glsl");
		vert.CreateShader();
		frag.CreateShader();

		GFX::ShaderProgram<GFX::VertexShader, GFX::FragmentShader> program(vert, frag);
		program.Bind();
		program.SetUniform4f("u_color", glm::vec4(0, 0, 1, 1));

		while (m_is_running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));

			for (Layer* layer : m_layer_stack)
			{
				layer->OnUpdate();
			}


			m_window->OnUpdate();
		}

    }
};

int main()
{
    int a = 0;
    float b = 0;
    glm::vec2 vec = { 0.1, 0.2 };
    Logger::Init("Test");
	TerrainGenApp procedural_generator("Name");
	//Application procedural_generator = Application::Get();
    GUIParameterSet* params = new GUIParameterSet;
    params->AddParameter(new VectorSlider<float, 2>("Vec", 0, 1, vec));
    params->AddParameter(new SimpleSlider<int>("IntSlider", 0, 1, a));
    procedural_generator.PushLayer(params);
    procedural_generator.Run();

}