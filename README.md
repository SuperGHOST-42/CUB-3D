*This project has been created as part of the 42 curriculum by figomes and arpereir*

# Cub3D

Cub3D is a small 3D game inspired by Wolfenstein 3D. It uses raycasting to
render a maze from a first-person perspective.

## Build

`make`

## Run

Start the game with a valid '.cub' map:
`./cub3D maps/teste1.cub`

## Controls

- `W` and `S`: move forward and backward
- `A` and `D`: move left and right
- Left and right arrow keys: rotate the camera
- `Esc`: close the game

## Parsing

This part of the project is responsible for parsing the .cub file and detecting any invalid configuration or map errors before starting the game.

1st: It starts by parsing the textures and colors, calling the appropriate function for each identifier (NO, SO, WE, EA, F, and C). It checks for missing or invalid values and raises an error if the identifier or its content is incorrect.
2nd: Once all textures and colors have been parsed, it searches for the beginning of the map.
3rd: When the first map line is found, every subsequent line belonging to the map is copied and stored.
4th: The stored map is then validated against all required rules. This includes checking for invalid characters, missing or duplicated elements, incorrect RGB values, and whether the map is properly closed/surrounded by walls. If any error is detected, the program exits with an error message. Only after all validations pass is the map considered valid and the game can start.

## Raycasting & MinilibX

This part of the project is responsible for rendering the 3D environment from the player's point of view and handling the graphical interface using MinilibX.

1st: The program initializes MinilibX, creates the game window and loads the textures required for rendering.
2nd: For every vertical column of the screen, a ray is cast from the player's position in the direction of the camera. The ray travels through the map until it hits a wall.
3rd: Once a wall is detected, the distance between the player and the wall is calculated and corrected to avoid the fisheye effect.
4th: Based on the distance to the wall, the height of the wall on the screen is calculated. The corresponding wall texture is then selected depending on the direction of the wall that was hit, and the correct part of the texture is drawn on the screen.
5th: The process is repeated for every column of the window, creating the final 3D perspective of the map.
6th: MinilibX is also responsible for handling keyboard input, closing the window and updating the image displayed on the screen.

## Resources

The following resources were used during the development of this project:

MinilibX documentation — Used as a reference for window management, image handling, keyboard events and rendering.
42 Cub3D subject — Used to understand the project requirements, map format and mandatory features.

AI tools were used as a complementary resource during the development of the project.
They were mainly used for:
Clarifying concepts related to raycasting, DDA and perspective correction.
Understanding and debugging specific C programming issues.
- Discussing possible approaches to map parsing and validation.
- Helping identify potential edge cases and errors in the .cub file.
- Reviewing and improving the README documentation and explanations.

AI was used as a support tool for understanding and debugging rather than as a replacement for implementing the project. The final code was written, tested and integrated by the team.