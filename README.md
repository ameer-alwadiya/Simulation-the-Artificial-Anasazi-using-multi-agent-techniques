# Simulation of the Artificial Anasazi Using Multi-Agent Techniques

## Executive Summary

The Anasazi Model is a classical agent-based model (ABM) used to simulate the population dynamics in the Long-House Valley region. This project builds upon the initial model by Axtell et al. (2002) and introduces two new features: collaborative resources and population reduction. These additions aim to better align the model's projections with historical data.

## Background and Purpose

Agent-based modelling (ABM) and multi-agent systems (MAS) are essential for analyzing complex adaptive systems (CAS). They help represent and study interactions within diverse systems, such as population dynamics and resource management. This project enhances the original Anasazi model to improve its accuracy in predicting historical population changes.

## Model Design

The enhanced model includes:
1. **Collaborative Resources**: Allows agents to seek help from neighbors if their resources are insufficient.
2. **Migration of Young People**: Simulates the migration of young agents when opportunities in the valley diminish.

### Rules of the Model

- **Collaborative Resources**: Agents request help from neighbors when their storage falls below a threshold. Neighbors decide whether to assist based on their own resource availability.
- **Migration of Young People**: Young agents (aged 16-30) may leave the valley if their resources are insufficient and opportunities are dwindling.

### Implementation

- **Collaborative Resources**: Added through `askHelpFromNeighbors()` method in `Model.cpp`.
- **Migration of Young People**: Implemented via `probabilityYoungToLeave()` function in `Household.cpp`.

## How to Run

To run the simulation, follow these steps:

### Prerequisites

Ensure you have the following software installed:
- **C++ Compiler**: Ensure a compatible compiler (e.g., g++, clang++) is installed.
- **MATLAB**: For sensitivity analysis and model evaluation.
- **Python**: For elementary effects and Latin hypercube sampling (Python 3.8 or higher recommended).

### Setting Up

1. **Clone the Repository**

   ```bash
   git clone https://github.com/ameer-alwadiya/Simulation-the-Artificial-Anasazi-using-multi-agent-techniques.git
   cd Simulation-the-Artificial-Anasazi-using-multi-agent-techniques
   ```

2. **Compile the Model**

   Navigate to the directory containing `Model.cpp` and `Household.cpp`, and compile the code:

   ```bash
   g++ -o AnasaziModel Model.cpp Household.cpp -std=c++11
   ```

   Adjust the command based on your compiler and project structure.

3. **Configuration**

   Edit the configuration files to set the parameters for collaborative resources and migration:
   - `model.prop` file contains parameters such as `youngLeave`, `askHelp`, and `acceptToHelp`. Adjust these values as needed.

4. **Run the Simulation**

   Execute the compiled model:

   ```bash
   ./AnasaziModel
   ```

   The simulation will run based on the parameters set in the `model.prop` file.

### Running Sensitivity Analysis

1. **MATLAB Analysis**

   Navigate to the MATLAB scripts directory and run the sensitivity analysis scripts:

   ```matlab
   run('sensitivity_analysis.m')
   ```

2. **Python Analysis**

   Ensure you have the necessary Python libraries installed (`numpy`, `pandas`, `matplotlib`). Run the Python script for elementary effects and Latin hypercube sampling:

   ```bash
   python analysis.py
   ```

### Viewing Results

The simulation results will be output in specified files or directories as defined in the code. Review the generated plots and data files to analyze the model's performance and accuracy.

## Model Analysis

The model includes sensitivity and goodness-of-fit analyses to evaluate the impact of new features and parameter values. Detailed methodology and results can be found in the [Model Analysis](#model-analysis) section.

## Reflection

This project involved significant learning in ABM design, Agile project management, and team collaboration. The final model shows improvements in historical data alignment but also has limitations related to environmental conditions and historical accuracy.

## Conclusion

The enhanced Anasazi model demonstrates progress in simulating historical population changes. It provides new insights and methods for studying complex population dynamics, with room for further refinement and exploration.
