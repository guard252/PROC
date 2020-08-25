#include "pch.h"
#include "ShaderProgram.h"
namespace GFX
{
	std::string Shader::RetrieveSrcFromFile(std::string_view file_path)
	{
		std::ifstream ifs(file_path.data());
		assert(ifs.is_open());
		std::string src((std::istreambuf_iterator<char>(ifs)),
						 std::istreambuf_iterator<char>());
		return src;
	}
	void Shader::Compile(std::string_view src) const
	{
		const char* src_str = src.data();
		GLCall(glShaderSource(m_ID, 1, &src_str, NULL));
		GLCall(glCompileShader(m_ID));
	}

	Shader::Shader(std::string_view path_to_src): m_path{path_to_src} {}

	void Shader::CreateShader()
	{
		std::string src = RetrieveSrcFromFile(m_path);
		GenerateShaderID(src);
		Compile(src);
		int success;
		char info_log[INFOLOG_SIZE];
		glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(m_ID, INFOLOG_SIZE, NULL, info_log);
			LOGE("Error in {}. Compilation failed. Info log:\n{}", Type(), info_log);
		};
	}
	void VertexShader::GenerateShaderID(std::string_view src)
	{
		GLCall(m_ID = glCreateShader(GL_VERTEX_SHADER));
	}
	void FragmentShader::GenerateShaderID(std::string_view src)
	{
		GLCall(m_ID = glCreateShader(GL_FRAGMENT_SHADER));
	}
	void ComputeShader::GenerateShaderID(std::string_view src)
	{
		GLCall(m_ID = glCreateShader(GL_COMPUTE_SHADER));
	}
}