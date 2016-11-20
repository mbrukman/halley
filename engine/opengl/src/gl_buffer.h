#pragma once

#include "halley_gl.h"
#include <gsl/gsl>

namespace Halley
{
	class GLBuffer
	{
	public:
		GLBuffer();
		~GLBuffer();

		void bind();
		void init(GLenum target);
		void setData(gsl::span<const gsl::byte> data);
		
	private:
		GLenum target = 0;
        GLuint name = 0;
		size_t size = 0;
	};
}
