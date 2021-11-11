# Yet another Sand-Sim
Here, you will find my ongoing exploration into what is possible with cellular automata through the develoupment of a sand-sim. This is a self driven educational 
project I work on in my spare time. Currently, I have a varity of solids and liquids that interact on a simple physical level, such as desnisty and inertia. I am planning to 
expand this model to incude more robust interactions, like conbustion and corrosion. 

## Under the hood
I have elected to use raylib, a fantaticly simple yet powerful library geard toward videogame development. Raylib acts as an interface to OpenGL that is more aproachable to 
hobbyist game developers. I highly reccomend checking raylib out at https://www.raylib.com/index.html.

This sand-sim is like most 2D cellular automatas. The program uses a 2D matrix for **_this_world_** and one for **_next_world_**. Simple conditional checks are preformed on each 
cell in **_this_world_** and applied to **_next_world_**. After all cells are updated, the program prints  **_next_world_**. Lastly, before starting the loop over, **_next_world_** is copied to **_this_world_**.

The **Cell.h** is the top level class that is inherited by the **Solid.h** class and **Liquid.h** class. The **Solid.h** class defines how solids interact with the world. Likewise, the **Liquid.h** class describes how liquids are updated each loop. Each game element, such as water, dirt, or sand, inherits the approiate parent class. 

## Emergent


