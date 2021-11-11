# Yet another Sand-Sim
I have elected to use raylib, a fantastically simple yet powerful library geared toward videogame development. Raylib acts as an interface to OpenGL that is more approachable to 
hobbyist game developers. I highly recommend checking raylib out at https://www.raylib.com/index.html.

This sand-sim is like most 2D cellular automata. The program uses a 2D matrix for **_this_world_** and one for **_next_world_**. Simple conditional checks are performed on each 
cell in **_this_world_** and applied to **_next_world_**. After all cells are updated, the program prints **_next_world_**. Lastly, before starting the loop over, **_next_world_** is copied to **_this_world_**.

The **Cell.h** is the top-level class that is inherited by the **Solid.h** class and **Liquid.h** class. The **Solid.h** class defines how solids interact with the world. Likewise, the **Liquid.h** class describes how liquids are updated each loop. Each game element, such as water, dirt, or sand, inherits the appropriate parent class. 

## Emergent behavior
One of the main reasons I started this project was to feed my fascination with emergent behavior. We will look at a few of my favorite examples with this simulation. All these behaviors below were not explicitly programed into the simulation, but rather the result of a whole greater than the sum of its parts. 

### Splashes!
The first example has to do with solids colliding with liquids. The code responsible for this event simply swaps a water or oil cell with a sand cell, in yellow. One would think this would merely shift the liquid upward, where it would fall straight back down. However, looking at the below gif shows more complex behavior of splashing when large numbers of sand cells hit the water, "throwing" the liquid cells in every which direction. Furthermore, the splash of water is more spread apart than the more viscous oil splash.

[![Image from Gyazo](https://i.gyazo.com/f548051ca3316f81c735abaad4a6835b.gif)](https://gyazo.com/f548051ca3316f81c735abaad4a6835b)

### Ripples!
When testing the simulation with liquids of different densities, I saw a behavior I could not have predicted. The different liquids, water, oil, and gasoline (blue, black, and brown, respectively) have different densities and viscosities. I assumed this would have only affected how liquids settled in solution and the flow speed across solids. However, these simple rules allow for different ripple types based on a liquid and its neighbors. In the gif below, you can see how the thicker oil prevents the gasoline from evening out quickly like the water does. On the right side, the gasoline alone ripples and finds a new equilibrium quickly.

[![Image from Gyazo](https://i.gyazo.com/0f2f51c6197dff07dd36ff73800916f3.gif)](https://gyazo.com/0f2f51c6197dff07dd36ff73800916f3)

## Wrapping up
This README only showcases a few of the features this simulation offers. It has been a great way to strengthen my programming and design skills. Hopefully you find this small hobby project interesting, I sure have. I plan to explore multithreading and chunking the simulation to achieve better performance in the future. Thank you all for your time!

[![Image from Gyazo](https://i.gyazo.com/921c50042b19151b311f954fba460236.gif)](https://gyazo.com/921c50042b19151b311f954fba460236)
