#ifndef CONSTANTS_H
#define CONSTANTS_H

const double PI(3.141592653589793238462643383279502884);
const float PIf(3.141592653589793238462643383279502884f);
const float TINY_VALUE(0.00000001f);
const int MAX_SPIKE_LENGTH(7);
const int MAX_SPIKE_DELAY(32);

#ifdef NDEBUG
const int DEFAULT_NET_SIZE(512);
#else
const int DEFAULT_NET_SIZE(64);
#endif

static const char * LAYER_EXTENSION(".layer");
static const char * SYNAPSE_EXTENSION(".synapse");

#endif
