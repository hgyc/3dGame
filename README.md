# 3D Galaxian (C/OpenGL)

Classic arcade shooter Galaxian, reimagined in 3D space. The project is written primarily in C to demonstrate skills in low-level graphics programming, memory management, and real-time performance optimization.

> Project Goal: Study the graphics pipeline (OpenGL), game loop architecture, and state management using a systems programming language.

## Technical Stack

| Component | Technology |
|-----------|------------|
| Language | C (Core logic, Rendering), C++ (Helpers) |
| Graphics | OpenGL (Raw API usage) |
| Memory Management | Manual allocation (Stack/Heap), structural approach |

## Project Architecture
The project is divided into modules to ensure code cleanliness and testability:

## Key Technical Decisions
Game Loop Pattern: Implementation of a stable loop with a fixed timestep for frame-rate independence.
Entity Management: Use of structures (struct) for object state storage without heavy OOP, optimizing CPU cache usage.
Memory Safety: Strict control of memory allocation to prevent leaks and segmentation faults, critical for C applications.
Performance
Optimized rendering (draw call batching where applicable).
Minimal dynamic allocation in the game loop (Zero-allocation runtime).
