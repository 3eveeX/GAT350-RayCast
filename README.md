GAT350-RayCast is a CPU-based ray tracer built for learning and experimentation.
It renders fully ray-traced scenes including diffuse, reflective, and refractive materials, with support for anti-aliasing, shadows, and multiple light types.
The project is written in C++ and designed to be lightweight and easy to study.



**Features**

 - Full CPU ray tracing pipeline

 - Lambertian (diffuse), metallic, and dielectric materials

 - Perfect reflection and refraction handling

 - Configurable camera with FOV, aperture, and depth-of-field

 - Multi-sample anti-aliasing

 - Random sampling for soft edges and smoother results

 - Sphere primitives

 - Multiple materials per scene



**Installation**
_**Prerequisites**_:

Make sure you have the following installed:

Visual Studio 2022 (or newer)

C++17 or later toolset

SDL3 

GLM


_**Setting Up in Visual Studio**_:

Open the .sln file in Visual Studio.

Ensure the project uses:

x64 configuration

Debug or Release build

Add required include directories:

SDL2 include path

GLM include path

Link SDL2 libraries (if displaying rendered output):

SDL2.lib

SDL2main.lib

Build the project using Build → Build Solution.

**Technical Details**

Lambertian (Diffuse):

 - Random hemisphere scattering

 - Soft, realistic diffuse colour falloff

Metal (Reflective):

 - Perfect mirror

Dielectric (Glass):

 - True physical refraction

**Lighting**

Shadow rays

Multiple rays per pixel

Hemisphere sampling

While not using a traditional Phong or Gouraud pipeline (those apply to rasterisation), the ray tracer implicitly computes:

Diffuse term

Specular term

Transparency/refraction

You can configure the number of rays per pixel:

1 sample → jagged edges

10 samples → acceptable smoothness

100+ samples → nearly noise-free

Sampling is randomised per pixel for soft global illumination effects.


**Attribution**

This project uses:

SDL2 – Simple DirectMedia Layer

GLM – OpenGL Mathematics Library

Concepts inspired by:

Peter Shirley’s Ray Tracing in One Weekend

All third-party assets, libraries, and code references belong to their respective owners.



**Conclusion**

Thank you for checking out GAT350-RayCast!
The project is entirely open to extension—feel free to fork the repo, experiment with new materials, and contribute improvements.

If you have ideas or want help expanding the renderer (BVH, textures, more primitives, multithreading), just ask!
