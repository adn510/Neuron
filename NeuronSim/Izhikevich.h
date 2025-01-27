#ifndef IZHIKEVICH_H
#define IZHIKEVICH_H

#include "Net.h"

#include "NeuronIzhikevich.h"

class ConfigPresets;

// An implementation of the Layer class for Izhikevich neurons.
// Izhikevich as 4 configurable parameters and each neuron has
// two state variables.
class Izhikevich : public Net<NeuronIzhikevich>
{
public:
	// Construct an Izhikevich layer with a given size
	Izhikevich(int width, int height);
	// Copy Constructor
	Izhikevich(const Izhikevich & other);
	// Destructor
	virtual ~Izhikevich();

	// The indetifying name for this type of layer
	// This is static for access via LayerFactory
	static std::string name();
	// The identifying name for this type of layer
	std::string typeName() { return name(); }
	// Set the configuration data
	void setConfig(const ConfigSet & config);
	// Get the configuration data
	ConfigSet getConfig();
	// Get the available preset configurations for this layer type
	// This is static for access via LayerFactory
	static const ConfigPresets & presets();
	// Get the available preset configurations for this layer type
	const ConfigPresets & getPresets();
	// Take a pointer to the start of an array of pixels and populate them
	// with the state of the neurons. The pixels should be in ABGR order.
	// Each specialization of Net will interpret its state in its own colour
	// scheme.
	void paintState(uint32_t * image) override;
	// Reset all cells in this layer to a state which is hopefully
	// queiscent and stable (v = mC, u = mC * mB)
	void clear();
	// Perform the logical processing specific to Izhikevich neurons
	void tick();

private:
	float mA;  //< Recovery time scale
	float mB;  //< Recovery sensitivity
	float mC;  //< Post-spike reset value
	float mD;  //< Post-spike recovery reset
};

#endif
