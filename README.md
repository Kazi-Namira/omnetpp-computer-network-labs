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
- Ques: Create a network of 5 hosts. One of the hosts will create a message and send it to its neighbor. Other hosts will just keep on sending the message to one of their neighbors. Run and record the event log.
- Folder: `lab2_network`
- Description: Network of 5 hosts where one host sends a message to its neighbor; others forward it continuously.
- Features:
  - Event log generation.
  - Demonstrates message propagation in small networks.
- Files:
  - `Host.ned`, `Network.ned`, `Host.cc`, `omnetpp.ini`, `Makefile`
  - Compiled binaries in `out/`
