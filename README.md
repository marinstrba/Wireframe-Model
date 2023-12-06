# FDF - Wireframe Model Project 🌍🖼️

## Overview 📜

FDF (French for "fil de fer", meaning "wireframe") is a graphical project 🎨 focused on creating a simple wireframe model representation of a 3D landscape 🏞️. The project entails linking various points (x, y, z) through line segments to form a landscape model.

![image](https://github.com/marinstrba/Wireframe-Model/assets/129158403/02a14774-2b3f-449a-9111-025967066b20)
![image](https://github.com/marinstrba/Wireframe-Model/assets/129158403/861798d2-3b3d-4698-93bf-bb9fdb779a6a)


## Objectives 🎯

The main objective of this project is to create a 3D representation of a landscape using wireframe modeling 📐. This involves managing graphic elements, handling user inputs 🕹️, and effectively rendering the landscape in 3D.

## Features 🌟

- **Rendering in Isometric Projection**: The project renders the wireframe landscape model in isometric projection for a 3D view 📏.
- **File Parsing**: Ability to read and interpret `.fdf` files, which contain the coordinates of the landscape 🗺️.
- **Graphic Management**: Utilizes MiniLibX, an internal school graphical library, for window management and graphic rendering 🖌️.
- **Interactive Controls**: Allows users to interact with the model using keyboard and mouse ⌨️🖱️.
- **Bonus Features**: Includes additional features like alternate projections, zoom, and model transformations (if implemented) 🔍🔄.

## Usage 🚀

Compile the program using the provided Makefile and run it with an `.fdf` file as an argument.

```bash
$> make
$> ./fdf example.fdf
