# Hooray
## A raytracing project in C++
### Instaling and running the project
To install and build. First clone the repository
 `  git clone https://github.com/DressedVojtech/Hooray.git && cd Hooray`

Next we need to build the project using cmake:
`mkdir build && cd build && cmake .. && make`

To run the project just exececute the executable.
`./hooray`

### Capibilities
![0](https://user-images.githubusercontent.com/66478269/214893704-b47e0952-edba-4953-b5a6-8d248b6d4f84.png)
![1](https://user-images.githubusercontent.com/66478269/214893709-85f4ca0b-b89c-46e7-9520-d35a7f33b3df.png)
![2](https://user-images.githubusercontent.com/66478269/214893713-a843f063-4be8-4f50-8840-b5315364a232.png)

Right now, the program can render any object made of triangles, which you have to define inside the main function, by creating an object and then populating it with triagnles using the `add_traingle()` function. Then we add the object into the scene and render.
We create a scene by creating a variable of type scene inside the main funciton, like this `scene MyScene;`.
Then we set the resolution of the scene: `MyScene.set_resolution(1920, 1080);`
We define a view-point/camera: `MyScene.set_cam({0, 0, 0}, 200.0)`, this means that the camera is at position 0,0,0 and the focal lenght is 200.0. Note that the camera is always facing the Y axis.
Then we need to add a light source: `MyScene.add_light_source({{10, 10, 10}, 0.375})`, this means that we added a light source at coordinates 10, 10, 10 and the intensity is 37.5%. Note that the instensity can be more thena 100%.
After we set all these values and add an object to the scene, we can render the scene by running the funciton `MyScene.render();`

### Future goals
- Reading safe files from .yaml
- Animation
- Better lighting
- Reading .obj files
- Exporting other image formats then .ppm
