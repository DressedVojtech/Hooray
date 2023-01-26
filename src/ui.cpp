#include "ui.h"
#include "scene.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

void ui::tui() {
    std::string d;
    std::cout << "Would you like to load a safe file of a scene (.yaml) (y/n)" << std::endl;
    std::cin >> d;
    if (d == "y") {
        std::cin >> path;
    } else if (d == "n") {
        std::string b;
        std::cout << "Do you want to create a scene from scratch? (y/n)" << std::endl;
        std::cin >> b;
        if (b == "y") {
            struct camera {
                std::string x = "0";
                std::string y = "0";
                std::string z = "0";
                std::string focal_length = "200";
            } Camera;
            struct resolution {
                std::string width = "1920";
                std::string height = "1080";
            } Resolution;
            struct vector {
                std::string x = "0";
                std::string y = "0";
                std::string z = "0";
            }background_color, light_source;
            std::string intensity = "1";
            struct rgba {
                std::string r = "200";
                std::string g = "200";
                std::string b = "200";
                std::string a = "0.1";
            }fog;
            struct triangle_strings {
                vector p0;
                vector p1;
                vector p2;
                vector color;
                std::string name;                
            };
            struct object_strings {
                std::vector<triangle_strings> triangles;
                std::string x;
                std::string y;
                std::string z;
                std::string name;
            };
            std::vector<object_strings> objects;

            std::cout << "Welcome to the scene creator. Type h for help" << std::endl;
            while(true) {
                std::string prompt = "";
                std::cout << "\ncommand (h for help):";
                std::cin >> prompt;
                std::cout << std::endl;
                    if (prompt == "h") {
                        std::cout << "Scene creator for Hooray. Here are the commands:\nh: help (this)\nc: camera setup\nb: set background color\nf: set fog (Currently doesn't do anything)\no: edit/create an object in the scene\nl: edit the light source (Default is intensity: 100\% and is at 0, 0, 0,)\np: show current setup of the scene\nw: write this buffer data to the scene\nr: render the currently saved data\nq: quit the program\n";
                    } else if (prompt == "w") {
                        Writing:
                        std::string a;
                        std::cout << "Are you sure you want to apply these changes to the scene? (y/n)" << std::endl;
                        std::cin >> a;
                        if (a == "n") {
                            break;
                        } else if (a == "y") {
                            int width = std::stoi(Resolution.width);
                            int height = std::stoi(Resolution.height);
                            
                        } else {
                            goto Writing;
                        }
                    } else if (prompt == "c") {
                        std::cout << "You will be prompted for the coordinates of the camera. Input only the numbers\n";
                        std::cout << "x: ";
                        std::cin >> Camera.x;
                        std::cout << "y: ";
                        std::cin >> Camera.y;
                        std::cout << "z: ";
                        std::cin >> Camera.z;
                        std::cout << "Please input the focal length for your camera as a number: ";
                        std::cin >> Camera.focal_length;
                        std::cout << "Width of the image: ";
                        std::cin >> Resolution.width;
                        std::cout << "Height of the image: ";
                        std::cin >> Resolution.height;
                    } else if (prompt == "b") {
                        std::cout << "You will be prompted to input the background color in RGB\n";
                        std::cout << "r: ";
                        std::cin >> background_color.x;
                        std::cout << "g: ";
                        std::cin >> background_color.y;
                        std::cout << "b: ";
                        std::cin >> background_color.z; 
                    } else if (prompt == "q") {
                        Quitting:
                        std::string sure;
                        std::cout << "Are you sure you want to quit the program? (y/n)\n";
                        std::cin >> sure;
                        if (sure == "y") {
                            exit(0);
                        } else if (sure == "n") {
                        } else {
                            goto Quitting;
                        }
                    } else if (prompt == "l") {
                        std::cout << "You will be prompted for the coordinates of the light source\n";
                        std::cout << "x: ";
                        std::cin  >> light_source.x;
                        std::cout << "y: ";
                        std::cin  >> light_source.y;
                        std::cout << "z: ";
                        std::cin  >> light_source.z;
                        std::cout << "\nSpecify the desired intensity for the light source (0 to 1):";
                        std::cin >> intensity;
                    } else if (prompt == "f") { 
                        std::cout << "You will be prompted for the color of the fog in RGBA\n";
                        std::cout << "r: ";
                        std::cin >> fog.r;
                        std::cout << "g: ";
                        std::cin >> fog.g;
                        std::cout << "b: ";
                        std::cin >> fog.b;
                        std::cout << "a: ";
                        std::cin >> fog.a;
                    } else if (prompt == "o") {
                        auto isNumber = [] (std::string s) {
                            std::string::const_iterator it = s.begin();
                            while (it != s.end() && std::isdigit(*it)) ++it;
                            return !s.empty() && it == s.end();
                        };
                        IndexInput:
                        std::string indexString = "";
                        int index;
                        if (objects.size() == 0) {
                            std::cout << "Create the first object\n";
                            objects.push_back({{}, "", ""});
                            index = 0;
                        } else if (objects.size() >= 1) {
                            std::cout << "Input the index of the object you want to edit.\nIf you want to create a new one input 'n'\n";
                        
                            std::cin >> indexString;
                            
                            if (isNumber(indexString)) {
                                int a = std::stoi(indexString);
                                if ((a > objects.size()-1) || (a < 0)) {
                                    std::cout << "Invalid index\n";
                                    goto IndexInput;
                                } else {
                                    index = a;
                                }
                            } else if (indexString == "n") {
                                objects.push_back({{}, "", ""});
                                index = objects.size()-1;
                            } else {
                                std::cout << "Invalid index input\n";
                                goto IndexInput;
                            }
                        }
                        bool quit = false;
                        std::cout << "Welcome to the object creator in Hooray\n";
                        while(!quit) {
                            std::string objectPrompt = "";
                            std::cout << "\ncommand (h for help):";
                            std::cin >> objectPrompt;
                            if (objectPrompt == "h") {
                                std::cout << "Object creator/editor for the scene creator inside Hooray commands:\nh: help\nt: edit/add triangle to this object\nd: delete triangle at index\np: print list of triangles\nn: name this object\nq: quit creating this object\n";
                            } else if (objectPrompt == "t") {
                                    TriangleIndexInput:
                                    std::string triangleIndexString = "";
                                    int triangleIndex;
                                    if (objects[index].triangles.size() == 0) {
                                        std::cout << "Creating the first triangle\n";
                                        objects[index].triangles.push_back({"", "", "", "0", "0", "0", ""});
                                        triangleIndex = 0;
                                    } else if (objects[index].triangles.size() >= 1) {
                                        std::cout << "Input the index of the triangle you want to edit.\nIf you want to create a new one input 'n'\n";
                                        std::cin >> triangleIndexString;
                                        if (isNumber(triangleIndexString)) {
                                            int b = std::stoi(triangleIndexString);
                                            if ((b > objects.size()-1) || (b < 0)) {
                                                std::cout << "Invalid index\n";
                                                goto TriangleIndexInput;
                                            } else {
                                                triangleIndex = b;
                                            }
                                        } else if (triangleIndexString == "n") {
                                            objects[index].triangles.push_back({"", "", "", "0", "0", "0", ""});
                                            triangleIndex = objects[index].triangles.size()-1;
                                        } else {
                                            std::cout << "Invalid index input\n";
                                            goto TriangleIndexInput;
                                        }
                                    }

                                    std::cout << "You will now be prompted for the three points of the triangle (p0, p1, p2)\n";
                                    std::cout << "\np0\n";
                                    std::cout << "x:";
                                    std::cin >> objects[index].triangles[triangleIndex].p0.x;
                                    std::cout << "y:";
                                    std::cin >> objects[index].triangles[triangleIndex].p0.y;
                                    std::cout << "z:";
                                    std::cin >> objects[index].triangles[triangleIndex].p0.z;
                                    std::cout << "\np1\n";
                                    std::cout << "x:";
                                    std::cin >> objects[index].triangles[triangleIndex].p1.x;
                                    std::cout << "y:";
                                    std::cin >> objects[index].triangles[triangleIndex].p1.y;
                                    std::cout << "z:";
                                    std::cin >> objects[index].triangles[triangleIndex].p1.z;
                                    std::cout << "\np2\n";
                                    std::cout << "x:";
                                    std::cin >> objects[index].triangles[triangleIndex].p2.x;
                                    std::cout << "y:";
                                    std::cin >> objects[index].triangles[triangleIndex].p2.y;
                                    std::cout << "z:";
                                    std::cin >> objects[index].triangles[triangleIndex].p2.z;
                                    std::cout << "\nPlease input the rgb values for the color of the triangle\n";
                                    std::cout << "r: ";
                                    std::cin >> objects[index].triangles[triangleIndex].color.x;
                                    std::cout << "g: ";
                                    std::cin >> objects[index].triangles[triangleIndex].color.y;
                                    std::cout << "b: ";
                                    std::cin >> objects[index].triangles[triangleIndex].color.z;
                                    std::cout << "\nIf you want you can specify a name for the triangle\n(This is only saved for the duration of creating the scene)\n";
                                    std::cin >> objects[index].triangles[triangleIndex].name;
                                }
                                else if (objectPrompt == "n") {
                                    std::cout << "Specify the name you want to give to this object:";
                                    std::cin >> objects[index].name;
                                }
                                else if (objectPrompt == "p") {
                                    std::cout << "Table of triangles inside this object: (" << objects[index].name << "," << index << ")\n";
                                    std::cout << std::left << std::setw(10) << "index" << std::setw(15) << "p0" << std::setw(15) << "p1" << std::setw(15) << "p2" << std::setw(15) << "color" << std::left << std::setw(30) << "name" << std::endl;
                                    for (int i = 0; i < objects[index].triangles.size(); i++) {
                                        std::cout << std::left << std::setw(10) << i << std::setw(5) << objects[index].triangles[i].p0.x << std::setw(5) << objects[index].triangles[i].p0.y << std::setw(5) << objects[index].triangles[i].p0.z << std::setw(5) << objects[index].triangles[i].p1.x << std::setw(5) << objects[index].triangles[i].p1.y << std::setw(5) << objects[index].triangles[i].p1.z << std::setw(5) << objects[index].triangles[i].p2.x << std::setw(5) << objects[index].triangles[i].p2.y << std::setw(5) << objects[index].triangles[i].p2.z << std::setw(5) << objects[index].triangles[i].color.x << std::setw(5) << objects[index].triangles[i].color.y << std::setw(5) << objects[index].triangles[i].color.z << std::left << std::setw(30) << objects[index].triangles[i].name;
                                    }
                                }
                                else if (objectPrompt == "d") {
                                    deleteIndexInput:
                                    int deleteIndex;
                                    std::string deleteIndexString;
                                    std::cout << "Please specify the index of the triangle you want to delete.\nIf you don't want to delete a triangle please type 'q':";
                                    std::cin >> deleteIndexString;
                                    if (isNumber(deleteIndexString)) {
                                        int c = std::stoi(deleteIndexString);
                                        if((c < 0) || (c > objects[index].triangles.size())) {
                                            std::cout << "Invalid index. The triangle does not exist\n";
                                            goto deleteIndexInput;
                                        } else {
                                            deleteIndex = c;
                                            objects[index].triangles.erase(objects[index].triangles.begin() + deleteIndex);
                                        }
                                    }  else if (deleteIndexString == "q") {
                                    } else {
                                        std::cout << "Invalid index\n";
                                        goto deleteIndexInput;
                                    }
                                }
                                else if (objectPrompt == "q") {
                                    quit = true;
                                }
                                else {
                                    std::cout << "\nInvalid command" << std::endl;
                                }
                            }
                    } else {
                        std::cout << "Invalid command\n";
                    }
                }
            } else if (b == "n") {}
    } else {}
} 

