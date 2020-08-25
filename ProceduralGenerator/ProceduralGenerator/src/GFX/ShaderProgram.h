#pragma once

namespace GFX
{
	constexpr inline int INFOLOG_SIZE = 512;

	class Shader
	{
	protected:
		GLuint m_ID;
		std::string m_path;
	protected:
		// Every shader MUST be written in a separate file
		std::string RetrieveSrcFromFile(std::string_view file_path);
		virtual void GenerateShaderID(std::string_view src) = 0;
		virtual std::string Type() const = 0;
		void Compile(std::string_view src) const;
	public:
		Shader(std::string_view path_to_src);
		virtual ~Shader() = default;
		GLuint get_ID() const { return m_ID; }
		virtual void CreateShader();
	};
	
	class VertexShader final : public Shader
	{
		virtual void GenerateShaderID(std::string_view src) override;
	public:
		VertexShader(std::string_view src) : Shader(src) {}
		virtual std::string Type() const override 
		{
			return "VertexShader";
		}
	};

	class FragmentShader final : public Shader
	{
		virtual void GenerateShaderID(std::string_view src) override;
	public:
		FragmentShader(std::string_view src) : Shader(src) {}
		virtual std::string Type() const override 
		{
			return "FragmentShader";
		}
	};
	
	class ComputeShader final : public Shader
	{
		virtual void GenerateShaderID(std::string_view src) override;
		ComputeShader(std::string_view src) : Shader(src) {}
	public:
		virtual std::string Type() const override 
		{
			return "ComputeShader";
		}
	};

	
	template <class T>
	concept ShaderType = std::is_base_of<Shader, T>::value;

	// ShaderProgram allows you to define shader pipeline yourself
	template <ShaderType ... S>
	class ShaderProgram : public IBindable
	{
	private:
		GLuint m_renderer_ID;
	private:
		void ProcessShaders(const S&... rest)
		{
			(void)std::initializer_list<int>{ (glAttachShader(m_renderer_ID, rest.get_ID()), 0)... };
		}
		void DeleteShaders(const S&... rest)
		{
			(void)std::initializer_list<int>{ (glDeleteShader(rest.get_ID()), 0)...};
		}
	public:
		ShaderProgram(const S&... rest)
		{
			GLCall(m_renderer_ID = glCreateProgram());
			ProcessShaders(rest ...);
			GLCall(glLinkProgram(m_renderer_ID));

			int success;
			char info_log[INFOLOG_SIZE];
			GLCall(glGetProgramiv(m_renderer_ID, GL_LINK_STATUS, &success));
			if (!success)
			{
				GLCall(glGetProgramInfoLog(m_renderer_ID, INFOLOG_SIZE, NULL, info_log));
				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << std::endl;
			}
		}

		virtual void Bind() const override
		{
			GLCall(glUseProgram(m_renderer_ID));
		}
		virtual void UnBind() const override
		{
			GLCall(glUseProgram(0));
		}

		//Uniforms:
	private:
		std::unordered_map<std::string, GLint> m_cached_uniforms;
	private:
		GLint GetUniformLocation(std::string_view name)
		{
			if (auto pair = m_cached_uniforms.find(name.data()); 
				pair != m_cached_uniforms.end())
			{
				return pair->second;
			}
			else
			{
				GLCall(GLint location = glGetUniformLocation(m_renderer_ID, name.data()));
				assert(location != -1);
				m_cached_uniforms.insert(std::make_pair(name, location));
				return location;
			}
		}
	public:
		void SetUniform1f(std::string name, float value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform1f(location, value));
		}
		void SetUniform2f(std::string_view name, glm::fvec2 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform2f(location, value.x, value.y));
		}
		void SetUniform3f(std::string_view name, glm::fvec3 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform3f(location, value.x, value.y, value.z));
		}
		void SetUniform4f(std::string_view name, glm::fvec4 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform4f(location, value.x, value.y, value.z, value.w));
		}

		void SetUniform1i(std::string_view name, int value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform1i(location, value));
		}
		void SetUniform2i(std::string_view name, glm::ivec2 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform2i(location, value.x, value.y));
		}
		void SetUniform3i(std::string_view name, glm::ivec3 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform3i(location, value.x, value.y, value.z));
		}
		void SetUniform4i(std::string_view name, glm::ivec4 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniform4i(location, value.x, value.y, value.z, value.w));
		}

		void SetUniformMatrix4x4(std::string name, glm::mat4 value)
		{
			GLint location = GetUniformLocation(name);
			GLCall(glUniformMatrix4fv(location, value));
		}

		

	};

	
	

}