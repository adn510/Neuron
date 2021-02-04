#include "Layer.h"

#include <sstream>

#include "ConfigPresets.h"
#include "SpikeProcessor.h"

static uint32_t nextName = 1;

using namespace std;

Layer::Layer(int width, int height) :
	mWidth(width),
	mHeight(height),
	mUserData(0)
{
	stringstream str;
	str << "Layer " << nextName;
	mName = str.str();
	// Let's just assume we never make 2^32 layers in one run.
	++nextName;
}

Layer::~Layer()
{

}

void Layer::resize(int width, int height)
{
	mWidth = width;
	mHeight = height;
}

void Layer::selectPreset(const std::string & name)
{
	setConfig(getPresets()[name]);
}
