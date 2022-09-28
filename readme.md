# **1.0 Goals**
`	`At the start of this now 5 month jurney my goals were quite simple. All I wanted was a few images of a few reflective spheres on a plane, gaining a bit more experience with programming in C++ and maybe learing to work with a few new libraries. But as it turned out on the way, what I really wanted to do, was something quite a lot more complex.
## **1.1 Current goals for the first release**
The current goals for the first releas of my raytracer hooray are:

- Being able to render shpes made of triangles in any resolution
- Create a safe file for the scenes (.ssf) and the animations (.asf)
- Being able to convert .obj files into objects within the scene (.ssf)
- Render some sample scenes for Github
- Possibly add mirros and light emiting surfaces
- Multithreading (That is splitting the tack between processor cores)
# **2.0 General introduction of RayTracing**
For those of you who don’t know, raytracing is concept in programming, using which you can draw 3D graphics to the screen, arguably in the most realistic way, that todays computers can offer.
1. ## **2.1 How does it work?**
The basic idea behind raytracing, is simulating how light bahves with 3D objects, but backwards. What do you mean by that?

In real life we see, because our eyes get hit by some light ray, which get to the earth from the sun, then sort of jump around and some of them get into our eyes and only then do we see the world around us.

In Theory we could just simulate of that to get a realistic image render on aour computer, but in reality we simply don’t have to computing power to simulate bilions of rays, just to get one image.

Thankfully we don’t have to, because there is a much better approach to this problem: Raytracing. In our theoretical example of simluating billions of rays, there is a problem, and that is, that most of the rays from the Sun actualy don’t end up in your eye, most of them just get scattered around and nerver even go in your direction. The solution to this, is simulating just the rays, which are guranteed to hit your eye, or camera. How would you do that, you say?

To simulate just as much of the rays as we need, you have to start from the end. So what we do, we simulate a ray, which goes away from our camera through a pixel on the screen and then check whether or not it does or does not hit anything (in the case that it does not, we would just show some sort of a background sprite) if it does hit anything we can simulate the ray spliting, or anything we want, but for the sake of simplicity, for now, we would just show the color/texture of the object as the pixel that shot the ray through at the start.

Model of a scene containing a cube made in SketchUp onilne version
# **3.0 Maths**
As in any programming problem the main thing behind it is the math. In this problem we need to calculate intersections between rays and triangles (In HooRay all the objects in the scene have to be made up of triangles). We need to know what a ray is in 3D space and what a triangle is in 3D space. The detect whether or not they are intersecting, if they are we can optionaly calculate some reflectinos or whatever we want, but for now we will just draw the color of the object to the current pixel.
## **3.1 Definitions**
First of all we need a way to define a point in space. We use the carteeshian system of coordinates, whish is kind of the standard nowadays. For storing coordinates within the program I used a class conviniently called vec3

class vec3 {

`	`public:

`		`float x;

`		`float y;

`		`float z;

};

Next we can use this to define a fex other things. Let’s start with defining a ray. In 3D we define a ray by a point at the start of it (The origin of the ray) and a direction vector.

class ray {

`	`public:

`		`vec3 origin;

`		`vec3 direction;

};

The next thing we will need to do is define a triangle, because (at least for now) all the objects in our scenes are going to be made up of triangles. We define a triangle simply by it’s 3 points;

class triangle {

`	`public:

`		`vec3 p0; // While programming we usually count from 0

`		`vec3 p1;

`		`vec3 p2;

};

We will also be in need of some light sources to do some colour calculation later.

Class l\_s {

`	`public:

`		`vec3 position;

};

The last thing we need to define is a point in 2D space, which we will need to add textures to the program later on. To stick with the naming scheme we will name it vec2.

class vec2 {

`	`public:

`		`float x;

`		`float y;

};

That is all of the definitions we need for now.
## **3.2 Ray and Triangle intersections**
The process of detecting intersections between ray and tringles is bacically made up of 2 steps.

- Detecting if the ray intersects with the plane the triangle lies on
- Determening whter the point of intersection point is inside the triangle
### **3.2.1 Ray and Plane intersection**
To determin wether a ray is intersecting with a plane and where that intersection is in 3D space, we first need to know what a plane is. A plane in 3D space can be defined by a point in space, that lies on the plane, and a normal vector. The normal vector(I will just use normal for short) is a vector which is perpendicular to the plane.

**How do we get a plane from a triangle?**

To define a plane, we firt need a point which for sure lies on that plane. For that we can simply choose any one of the points from the triangle, let’s go with p1. Next we will need the normal of the plane. To calculate the normal of the plane the triangle lies on, we will need to calculate the cross product of two of the edges of the triangle. Let U = p0 - p1 and V = p1 – p2, then the normal N = U × V .

Now let’s code that. First we will make a cross product function. Make sure that it is written under the vec3 class code. For those who don’t know what the cross product is: If we take two vectors a and b, then the cross product a × b is a vector perpendicular to them, thus the normal of the plane on which they both lie.

vec3 cross\_product(vec3 A, vec3 B) {

`	`vec3 result;

`	`result.x = B.y \* A.z – B.z \* A.y;

`	`result.y = B.x \* A.z – B.z \* A.x;

`	`result.z = B.x \* A.y – B.y \* A.x;

`	`return result;

}

Next we will need to define what the “-” operator means in the context of subtracting two 3 dimensional vectors. We will do that using operator overloading in C++.

class vec3 {

`	`public:

`		`float x;

`		`float y;

`		`float z;

`		`vec3 operator – (vec3 A) {

`			`vec3 result;

`			`result.x = x - A.x;

`			`result.y = y - A.y;

`			`result.z = z - A.z;

`			`return result;

`		`}

};

Thanks to that the program now knows how to subtract vectors. For the sake of consistency let’s do that for the other three operations, like so:

class vec3 {

`	`public:

`		`float x;

`		`float y;

`		`float z;

`		`vec3 operator – (vec3 A) {

`			`vec3 result;

`			`result.x = x - A.x;

`			`result.y = y - A.y;

`			`result.z = z - A.z;

`			`return result;

`		`}

`		`vec3 operator + (vec3 A) {

`			`vec3 result;

`			`result.x = x + A.x;

`			`result.y = y + A.y;

`			`result.z = z + A.z;

`			`return result;

`		`}

`		`vec3 operator \* (vec3 A) {

`			`vec3 result;

`			`result.x = x \* A.x;

`			`result.y = y \* A.y;

`			`result.z = z \* A.z;

`			`return result;

`		`}

`		`vec3 operator / (vec3 A) {

`			`vec3 result;

`			`result.x = x / A.x;

`			`result.y = y / A.y;

`			`result.z = z / A.z;

`			`return result;

`		`}

};

Now we have all we need to calculate the normal of a triangle. Let’s create a normal() function in the triangle class, so that we can use it later.

class triangle {

`	`public:

`		`vec3 p0; // While programming we usually count from 0

`		`vec3 p1;

`		`vec3 p2;



`		`vec3 normal() {

`			`vec3 U = p0 – p1;

`			`vec3 V = p1 – p2;

`			`vec3 result = cross\_product(U, V);

`			`return result;

`		`}

};

Now for the main point of this subchapter. How do we detect if a ray and a plane are intersecting.

A ray in 3D space is mathematicaly:

P = O + t\*D

P being any point on the ray, O being the origin, D the direction vector and t is distance along the ray.

Now we will calculate t, whch in our case is the distance to the intersection point P from the ray origin.

Note: If t is smaller than 0, that means that the intersection point with the plane is behind the ray origin(behind the camera), so by that we know, that the triangle is not visible

N being the plane normal, O the origin of the ray and D the direction vector of the ray and d is the dot product of the normal and p0

Those two dots in the equaion don’t represent multiplication, but rather the dot product of the two vectors, unlike the cross product, the dot product gives us a real number, not a vector. So let’s add a dot\_product() function under the cross\_product\_function in our code.

float dot\_product(vec3 A, vec3 B) {

`	`float result = A.x \* B.x + A.y \* B.y + A.z \* B.z;

`	`return result;

}

Note: If a dot product is equal to zero, that means that the two vectors are perpendicular to each other. So if the dot product of the normal and the ray direction is equal to zero, that means that they are perpendicular and so the plane and the ray never intersect.

You might be asking, what can we do with the t, that we now know how to calculate. Well we can find the intersection point with it. Basically, we take the ray equation:

P = O + t\*D

And using that, we can get the intersection point by just substituting for t.
### **3.2.2 Is point inside triangle?**
Now we have an intersection point P, about which we know that it is on the plane on which the triangle lies. But...

**How do we detect if the point is inside the triangle, not just on the plane?**

There are many ways to do that. I chose the arguably simplest one.

All you need to do while using this method is to add three angles together, those are:

p0Pp1 + p0Pp2 + p1Pp2

And check whether or not the result is equal to 360° (or 2π rad)

If it is, than the point is inside the triangle, if it isn’t than the oposite is true.

A ~ p0, B ~ p1, C ~ p2, D ~ P

But how?

We can claculate these angles, if we treat the points of the triangle as vectors. And then claculate the angle between those vectors. So, we need a method to get the angle between two vectors. Here it is:

The || || is a symbol used for the magnitude of a vector (Basicaly its size)

How did we get this formula?

The definition of a dot product is a · b = ||a|| \* ||b|| \* cos α
From that we can get deduct the equation for the angle α, which we need.

Let’s just add a quick method for getting the magnitude of a vector and and a function for the angle between two vectors. Inside the vec3 class under all the previous functions add:

class vec3 {

`	`public:

`		`// Some code …

`		`float magnitude() {

`			`return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2);

`		`}

};

And under the vec3 class add this function:

float angle(vec3 A, vec3 B) {

`	`float result = acos(dot\_product(A, B)/(A.magnitude() \* B.magnitude());

`	`return result;

}

Now we need to do this for all of the points. But there is a bit of a twist, we cannot just put the points as they are into the equation, that is because this method is for getting the angle between two vectors and in this context the vectors start at the origin (0, 0, 0), so first we will have to deduct P from all the points, by that we essantialy move the triangle to the origin. and then put them into the equation and get the angle.
## **3.2.3 Create a intersection() function for later**
So now we have a everything we need to detect an intersection between a ray and a triangle, now let’s make a function for it, because we will need to do this a lot of times.

class triangle {

`	`public:

`		`vec3 p0;

`		`vec3 p1;

`		`vec3 p2;



`		`vec3 normal() {

`			`vec3 U = p0 – p1;

`			`vec3 V = p1 – p2;

`			`vec3 result = cross\_product(U, V);

`			`return result;

`		`}



`		`struct vec3b {

`			`vec3 P;

`			`bool hit;

`		`};

`		`vec3b intersetion(ray Ray) {

`			`vec3 P = {-1, -1, -1};

`			`if (dot\_product(N, Ray.direction == 0) return {{P}, false};

`			`float t = - (dot\_product(normal(), Ray.origin) + dot\_product(N, p0))/dot\_product(N, Ray.direction);

`			`P = Ray.origin + t\*Ray.direction;

`			`if (t < 0) return {{P}, false};

`			`if ((angle(p0 – P, p1 – P) / 180 \* PI) + (angle(p1 – P, p2 – P) / 180 \* PI) + (angle(p0 – P, p2 – P) / 180 \* PI) == 360) {

`			`return {{P}, true};

`			`}

`			`return {{P}, false};

`		`}

};

**Explanation of what we have coded:**

What we have just coded is an intersection function. First it takes a ray, which we call Ray inside the function. Afterwards we declare the variable P of type vec3 and set it’s value to -1, -1, -1. The second step is to check if the dot product of the normal of the plane a nd the direction of the Ray is 0 (If the normal and the direction are perpendicular), if so than we return P with the negative values and false (The ray and the triangle do not intersect). Then we calculate t, which is the distance of the intersection point from the camera position, or phrased differently, the distance we have to travel along the Ray to get to the intersection point with the plane on which the traingle lies on. Using t we can calculate P by using the ray eqaution from earlier. Then we have to check if t is negative, if it is, that means that the intersection point is behind the camera, so we don’t have to care about it, so we return P and false, because there is no valid intersection. Now the last check: Using the .angle() function we can calculate the different angles add them up and check if they are equal to 360 degrees, if that is true, than Hooray we have an intersection with the triangle: We return P and true, because there is a valid intersection. The last line of code is there in case there isn’t an intersection with the triangle, in that case: return P and false.
## **3.3 Objects**
There is one last thing we need to do before we get to defining a scene, creating our formats for animations and scenes and finally tracing some rays. We need to define an object.

class object {

`	`public:

`		`std::vector <triangle> triangles;

`		`vec3 position;



`	`void add\_triangle(triangle Triangle) {

`		`triangles.push\_back(Triangle);

`	`}

};

how we handle objects in our scenes is pretty simple, each object contains of multiple trianles, for which we have created a std::vector, you can think of a std::vector as an expandable list of anything you want, in our case: triangles. The triangles inside the std::vector have a coordinates relative to 0,0,0 of the object, because of that we have another variable of type vec3 called position, which tells us, where the 0, 0, 0 coordinates of the object are located within the scene. The last thing we have defined inside the class is a function called add\_triangle(), that takes a trianlge and adds it to the end of the std::vector of triangles.
# **4.0 Scenes**
The way that we are going to render things to the screen is using scenes. A scene will contain all the information we need to render the scene: the position of the camera, all the light sources, the screen resolution, the distance of the screen from the camera and an std::vector of all the objects and the triangles. We will have a separate std::vector of triangles that will contain the triangles from the objects, because it is much more practical to have them in a seperate vector than having them inside the objects for accesibility.

class scene {

`	`public:

`		`std::vector <object> objects;

`		`std::vector <triagnle> triangles;

`		`int screen\_width;

`		`int screen\_height;

`		`float distance;

`		`std::vector <l\_s> light\_sources;

};
