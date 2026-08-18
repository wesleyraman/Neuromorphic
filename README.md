# Neuromorphic
# SpikeCore ⚡

`SpikeCore` is a high-performance C++20 simulation engine designed for event-driven Neuromorphic Computing. It models Leaky Integrate-and-Fire (LIF) neuron populations using cache-friendly data structures to maximize throughput.

## 🛠️ Tech Stack & Concepts
* **Language:** C++20
* **Build System:** CMake
* **Architecture Pattern:** Structure-of-Arrays (SoA) for SIMD vectorization & cache locality
* **Domain:** Neuromorphic Engineering & Spiking Neural Networks (SNNs)

## 🚀 Performance & Architecture

Unlike traditional Object-Oriented implementations (`vector<Neuron>`), `SpikeCore` organizes network state into contiguous memory blocks (`Structure-of-Arrays`). This prevents CPU cache misses and enables compiler auto-vectorization during membrane decay and spike threshold evaluations.

$$U_i[t] = \beta U_i[t-1] + I_i[t] - S_i[t-1] V_{th}$$

### Baseline Benchmarks (Sequential C++)
* **Network Size:** 100,000 Neurons
* **Timesteps:** 1,000
* **Hardware:** intel i7
* **Execution Time:** ~

## 📦 Building and Running

### Prerequisites
* C++20 compatible compiler (GCC 10+, Clang 11+, or MSVC 2019+)
* CMake 3.18+

### Build Steps
```bash
git clone [https://github.com/your-username/SpikeCore.git](https://github.com/your-username/SpikeCore.git)
cd SpikeCore
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
./spike_core
