# OMNeT++ Computer Network Labs

This repository contains my computer network lab projects implemented using **OMNeT++ 6.3**.

## Projects

### 1. ALOHA Simulation (alo_ha)
- Ques: Implement pure ALOHA using the simulator and measure its performance by analyzing the throughout.
- Folder: `alo_ha`
- Description: Implements **Pure ALOHA protocol** simulation.
- Features:
  - Multiple hosts sending packets randomly.
  - Measures throughput.
- Files:
  - `AlohaHost.ned`, `AlohaNetwork.ned`, `AlohaHost.cc`, `omnetpp.ini`, `Makefile`
  - Compiled binaries in `out/`

### 2. Lab2 – Host to Host Message Passing (lab2)
- Folder: `lab2_network`
- Description: Network of 5 hosts where one host sends a message to its neighbor; others forward it continuously.
- Features:
  - Event log generation.
  - Demonstrates message propagation in small networks.
- Files:
  - `Host.ned`, `Network.ned`, `Host.cc`, `omnetpp.ini`, `Makefile`
  - Compiled binaries in `out/`
