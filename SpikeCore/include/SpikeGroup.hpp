#pragma once
#include <vector>
#include <cstdint>
#include <cstddef>

class SpikeGroup {
public:
    size_t num_neurons;
    
    // Contiguous memory blocks (SoA Pattern)
    std::vector<float> voltage;
    std::vector<float> decay;
    std::vector<float> threshold;
    std::vector<uint8_t> spikes; // 1 if fired, 0 otherwise

    SpikeGroup(size_t count, float default_decay = 0.9f, float default_threshold = 1.0f)
        : num_neurons(count),
          voltage(count, 0.0f),
          decay(count, default_decay),
          threshold(count, default_threshold),
          spikes(count, 0) {}

    // Advances the entire neuron group by one discrete time step
    void step(const std::vector<float>& input_current) {
        for (size_t i = 0; i < num_neurons; ++i) {
            // Leak & Integration: U[t] = decay * U[t-1] + I[t]
            voltage[i] = (voltage[i] * decay[i]) + input_current[i];

            // Spike Generation & Subtractive Reset
            if (voltage[i] >= threshold[i]) {
                spikes[i] = 1;
                voltage[i] -= threshold[i]; // Reset mechanism
            } else {
                spikes[i] = 0;
            }
        }
    }
};
