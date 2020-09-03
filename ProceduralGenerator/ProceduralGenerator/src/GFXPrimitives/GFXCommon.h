#pragma once

namespace GFX
{
	class IBindable
	{
	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}
