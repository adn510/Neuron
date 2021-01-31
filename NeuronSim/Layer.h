#ifndef LAYER_H
#define LAYER_H

#include <stdint.h>
#include <string>

class Layer
{
public:
	Layer(int width, int height);
	virtual ~Layer();

	virtual void tick() = 0;
	virtual std::string typeName() = 0;
	virtual void paint(uint32_t * image, int rowStep, int left, int top, int width, int height) = 0;
	virtual void paint(uint32_t * image) = 0;

	virtual void resize(int width, int height);
	int width() { return mWidth; }
	int height() { return mHeight; }

protected:
	int mWidth;
	int mHeight;
};

#endif