#pragma once
#include "DLLHeader.h"
namespace GFX
{
	class PROC_API IBindable
	{
	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}
