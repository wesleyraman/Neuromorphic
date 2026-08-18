#include <iostream>
#include <chrono>
#include "SpikeGroup.hpp"

int main() {
    constexpr size_t NUM_NEURONS = 100'000;
    constexpr size_t TIMESTEPS = 1'000;

    SpikeGroup neurons(NUM_NEURONS);
    std::vector<float> current(NUM_NEURONS, 0.35f); // Constant input current

    auto start_time = std::chrono::high_resolution_clock::now();

    size_t total_spikes = 0;
    for (size_t t = 0; t < TIMESTEPS; ++t) {
        neurons.step(current);
        for (uint8_t spike : neurons.spikes) {
            total_spikes += spike;
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;

    std::cout << "--- SpikeCore Baseline Benchmarks ---\n"
              << "Neurons: " << NUM_NEURONS << "\n"
              << "Timesteps: " << TIMESTEPS << "\n"
              << "Total Spikes: " << total_spikes << "\n"
              << "Execution Time: " << elapsed.count() << " ms\n";

    return 0;
}
