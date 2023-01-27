#include "ui.h"
#include "scene.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

bool areYouSure(std::string Question) {
    std::string a;
    std::cout << Question;
    std::cin >> a;
    if (a == "y") {
        return true;
    }
    return false;
}


void ui::tui() {
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
    struct RGBA {
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
    std::vector<object_strings> object_strings;
    system("clear");
    std::cout << "Welcome to the TUI of Hooray" << std::endl;
    int counter = 0;
    while(true) {
        std::string prompt = "";
        if (counter == 0) {
            std::cout << "\ncommand (h for help): ";
        } else {
            std::cout << "\ncommand: ";
        }
        std::cin >> prompt;
        std::cout << std::endl;
        if (prompt == "h") {
            counter++;
            std::cout << "Here are the commands and what they do:\nh: help (this)\nc: camera setup\nb: set background color\nf: set fog (Currently doesn't do anything)\no: edit/create an object in the scene\nd: delete object specified by its index\nl: edit the light source (Default is intensity: 100\% and is at 0, 0, 0,)\np: show current setup of the scene\nw: write this buffer data to the scene\nr: render the currently saved data\ns: clear the terminal (only works on linux)\nq: quit the program\n";
            std::cout << "\nWhen you are asked for a number input a number, otherwise the program will not work.\n";
        } else if (prompt == "r") {
            if (areYouSure("Are you sure you want to render this scene? (y/n)\n")) {
                Scene.render();
            }
        } else if (prompt == "d") {
            if (areYouSure("Are you sure you want to delete an object? (y/n)\n")) {
                auto isNumber = [] (std::string s) {
                    std::string::const_iterator it = s.begin();
                    while (it != s.end() && std::isdigit(*it)) ++it;
                    return !s.empty() && it == s.end();
                };
                Deletion:
                std::string deletionIndexString;
                std::cout << "Specify the index of the index of the object you want to delete\n";
                std::cin >> deletionIndexString;
                int deletionIndex;
                if (isNumber(deletionIndexString)) {
                    int l = std::stoi(deletionIndexString);
                    if ((l < 0) || (object_strings.size() < l)) {
                        std::cout << "The entered index: " << deletionIndexString << " is invalid\n";
                        goto Deletion;
                    } else {
                        deletionIndex = l;
                    }
                }  else {
                    std::cout << "The entered index: " << deletionIndex << " is invalid\n";
                    goto Deletion;
                }

                object_strings.erase(object_strings.begin() + deletionIndex);
            }
        } else if (prompt == "w") {
            if (areYouSure("Are you sure you want to apply these changes to the scene? (y/n)\n")) {
                int width = std::stoi(Resolution.width);
                int height = std::stoi(Resolution.height);
                vec3 camera_position = {std::stof(Camera.x), std::stof(Camera.y), std::stof(Camera.z)};
                int focal = std::stof(Camera.focal_length);
                rgb bgColor = {std::stof(background_color.x), std::stof(background_color.y), std::stof(background_color.z)};
                rgba Fog = {std::stof(fog.r), std::stof(fog.g), std::stof(fog.b), std::stof(fog.a)};
                l_s LightSource = {{std::stof(light_source.x), std::stof(light_source.y), std::stof(light_source.z)}, std::stof(intensity)};
                std::vector <object> objects;
                std::cout << "Writing objects...\n";
                for (int i = 0; i < object_strings.size(); i++) {
                    std::cout << (i/object_strings.size())*100 << "%" << std::endl;
                    std::vector<triangle> triangles;
                    std::cout << "Loading triangles from (" << i << ", " << object_strings[i].name << ")\n";
                    for (int j = 0; j < object_strings[i].triangles.size(); j++) {
                        std::cout << (j/object_strings[i].triangles.size()) * 100 << "%" << std::endl;
                        vec3 p0 = {std::stof(object_strings[i].triangles[j].p0.x),std::stof(object_strings[i].triangles[j].p0.y),std::stof(object_strings[i].triangles[j].p0.z)};
                        vec3 p1 = {std::stof(object_strings[i].triangles[j].p1.x),std::stof(object_strings[i].triangles[j].p1.y),std::stof(object_strings[i].triangles[j].p1.z)};
                        vec3 p2 = {std::stof(object_strings[i].triangles[j].p2.x),std::stof(object_strings[i].triangles[j].p2.y),std::stof(object_strings[i].triangles[j].p2.z)};
                        rgb color = {std::stof(object_strings[i].triangles[j].color.x),std::stof(object_strings[i].triangles[j].color.y),std::stof(object_strings[i].triangles[j].color.z)};
                        triangle TRIANGLE = {p0, p1, p2, {0, 0}, {0, 0}, {0, 0}, color, ""};
                        triangles.push_back(TRIANGLE);
                    }
                    objects.push_back({{triangles},{std::stof(object_strings[i].x), std::stof(object_strings[i].y), std::stof(object_strings[i].z)}});
                    if (areYouSure("Are you sure you want to write this data? (y/n)")) {
                        Scene.set_resolution(width, height);
                        Scene.set_cam(camera_position, focal);
                        Scene.set_background(bgColor);
                        Scene.add_light_source(LightSource);
                        Scene.set_fog(Fog);
                        for (int i = 0; i < objects.size(); i++) {
                            Scene.add_object(objects[i]);
                        }
                    }
                } 
            }
        } else if (prompt == "c") {
            if (areYouSure("Do you want to edit the camera settings? (y/n)\n")) {
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
            }
        } else if (prompt == "b") {
            if (areYouSure("Are you sure you want to edit the background color? (y/n)\n")) {
                std::cout << "You will be prompted to input the background color in RGB\n";
                std::cout << "r: ";
                std::cin >> background_color.x;
                std::cout << "g: ";
                std::cin >> background_color.y;
                std::cout << "b: ";
                std::cin >> background_color.z;
            } 
        } else if (prompt == "s") {
            system("clear");
        } else if (prompt == "q") {
            if (areYouSure("Are you sure you want to quit the program? (y/n)\n")) {
                exit(0);
            }
        } else if (prompt == "l") {
            if (areYouSure("Are you sure you want to edit the light source settings? (y/n)\n")) {
                std::cout << "You will be prompted for the coordinates of the light source\n";
                std::cout << "x: ";
                std::cin  >> light_source.x;
                std::cout << "y: ";
                std::cin  >> light_source.y;
                std::cout << "z: ";
                std::cin  >> light_source.z;
                std::cout << "\nSpecify the desired intensity for the light source (0 to 1):";
                std::cin >> intensity;
            }
        } else if (prompt == "f") { 
            if (areYouSure("Are you sure you want to edit the fog? (y/n)\n")) {
                std::cout << "You will be prompted for the color of the fog in RGBA\n";
                std::cout << "r: ";
                std::cin >> fog.r;
                std::cout << "g: ";
                std::cin >> fog.g;
                std::cout << "b: ";
                std::cin >> fog.b;
                std::cout << "a: ";
                std::cin >> fog.a;
            }
        } else if (prompt == "o") {
            if (areYouSure("Are you sure you want to edit or create a new object? (y/n)\n")) {
                auto isNumber = [] (std::string s) {
                    std::string::const_iterator it = s.begin();
                    while (it != s.end() && std::isdigit(*it)) ++it;
                    return !s.empty() && it == s.end();
                };
                IndexInput:
                std::string indexString = "";
                int index;
                if (object_strings.size() == 0) {
                    std::cout << "Create the first object\n";
                    object_strings.push_back({{}, "", ""});
                    index = 0;
                } else if (object_strings.size() >= 1) {
                    std::cout << "Input the index of the object you want to edit.\nIf you want to create a new one input 'n'\n";
                
                    std::cin >> indexString;
                    
                    if (isNumber(indexString)) {
                        int a = std::stoi(indexString);
                        if ((a > object_strings.size()-1) || (a < 0)) {
                            std::cout << "Invalid index\n";
                            goto IndexInput;
                        } else {
                            index = a;
                        }
                    } else if (indexString == "n") {
                        object_strings.push_back({{}, "", ""});
                        index = object_strings.size()-1;
                    } else {
                        std::cout << "Invalid index input\n";
                        goto IndexInput;
                    }
                }
                bool quit = false;
                std::cout << "Welcome to the object creator in Hooray\n";
                int objectCounter = 0;
                while(!quit) {
                    std::string objectPrompt = "";
                    if (objectCounter == 0) {
                        std::cout << "\ncommand (h for help):";
                    } else {
                        std::cout << "\ncommand: ";
                    }
                    std::cin >> objectPrompt;
                    if (objectPrompt == "h") {
                        counter++;
                        std::cout << "Here are the commands for creating object_strings:\nh: help\no: Set the position of the origin this object\nt: edit/add triangle to this object\nd: delete triangle at index\np: print list of triangles\nn: name this object\ns: clear the terminal (Only works on linux)\nq: quit creating this object\n";
                    } else if (objectPrompt == "o") {
                        if (areYouSure("Are you sure you want to edit the position of this object? (y/n)\n")) {
                            std::cout << "You will be prompted for the coordinates of the origin of this object\n";
                            std::cout << "x: ";
                            std::cin >> object_strings[index].x;
                            std::cout << "y: ";
                            std::cin >> object_strings[index].y;
                            std::cout << "z: ";
                            std::cin >> object_strings[index].z;
                        }
                    } else if (objectPrompt == "s") {
                        system("clear");
                    } else if (objectPrompt == "t") {
                        if (areYouSure("Are you sure that you want to create or edit a triangle? (y/n)\n")) {
                            TriangleIndexInput:
                            std::string triangleIndexString = "";
                            int triangleIndex;
                            if (object_strings[index].triangles.size() == 0) {
                                std::cout << "Creating the first triangle\n";
                                object_strings[index].triangles.push_back({"", "", "", "0", "0", "0", ""});
                                triangleIndex = 0;
                            } else if (object_strings[index].triangles.size() >= 1) {
                                std::cout << "Input the index of the triangle you want to edit.\nIf you want to create a new one input 'n'\n";
                                std::cin >> triangleIndexString;
                                if (isNumber(triangleIndexString)) {
                                    int b = std::stoi(triangleIndexString);
                                    if ((b > object_strings.size()-1) || (b < 0)) {
                                        std::cout << "Invalid index\n";
                                        goto TriangleIndexInput;
                                    } else {
                                        triangleIndex = b;
                                    }
                                } else if (triangleIndexString == "n") {
                                    object_strings[index].triangles.push_back({"", "", "", "0", "0", "0", ""});
                                    triangleIndex = object_strings[index].triangles.size()-1;
                                } else {
                                    std::cout << "Invalid index input\n";
                                    goto TriangleIndexInput;
                                }
                            }

                            std::cout << "You will now be prompted for the three points of the triangle (p0, p1, p2)\n";
                            std::cout << "\np0\n";
                            std::cout << "x:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p0.x;
                            std::cout << "y:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p0.y;
                            std::cout << "z:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p0.z;
                            std::cout << "\np1\n";
                            std::cout << "x:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p1.x;
                            std::cout << "y:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p1.y;
                            std::cout << "z:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p1.z;
                            std::cout << "\np2\n";
                            std::cout << "x:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p2.x;
                            std::cout << "y:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p2.y;
                            std::cout << "z:";
                            std::cin >> object_strings[index].triangles[triangleIndex].p2.z;
                            std::cout << "\nPlease input the rgb values for the color of the triangle\n";
                            std::cout << "r: ";
                            std::cin >> object_strings[index].triangles[triangleIndex].color.x;
                            std::cout << "g: ";
                            std::cin >> object_strings[index].triangles[triangleIndex].color.y;
                            std::cout << "b: ";
                            std::cin >> object_strings[index].triangles[triangleIndex].color.z;
                            std::cout << "\nIf you want you can specify a name for the triangle\n(This is only saved for the duration of creating the scene)\n";
                            std::cin >> object_strings[index].triangles[triangleIndex].name;
                        }
                    } else if (objectPrompt == "n") {
                        std::cout << "Specify the name you want to give to this object:";
                        std::cin >> object_strings[index].name;
                    } else if (objectPrompt == "p") {
                        std::cout << "Table of triangles inside this object: (" << object_strings[index].name << "," << index << ")\n";
                        std::cout << std::left << std::setw(10) << "index" << std::setw(15) << "p0" << std::setw(15) << "p1" << std::setw(15) << "p2" << std::setw(15) << "color" << std::left << std::setw(30) << "name" << std::endl;
                        for (int i = 0; i < object_strings[index].triangles.size(); i++) {
                            std::cout << std::left << std::setw(10) << i << std::setw(5) << object_strings[index].triangles[i].p0.x << std::setw(5) << object_strings[index].triangles[i].p0.y << std::setw(5) << object_strings[index].triangles[i].p0.z << std::setw(5) << object_strings[index].triangles[i].p1.x << std::setw(5) << object_strings[index].triangles[i].p1.y << std::setw(5) << object_strings[index].triangles[i].p1.z << std::setw(5) << object_strings[index].triangles[i].p2.x << std::setw(5) << object_strings[index].triangles[i].p2.y << std::setw(5) << object_strings[index].triangles[i].p2.z << std::setw(5) << object_strings[index].triangles[i].color.x << std::setw(5) << object_strings[index].triangles[i].color.y << std::setw(5) << object_strings[index].triangles[i].color.z << std::left << std::setw(30) << object_strings[index].triangles[i].name << std::endl;
                        }
                        std::cout << "\n The position of the origin of this object is: " << object_strings[index].x << ", " << object_strings[index].y << ", " << object_strings[index].z << std::endl;
                    } else if (objectPrompt == "d") {
                        deleteIndexInput:
                        int deleteIndex;
                        std::string deleteIndexString;
                        std::cout << "Please specify the index of the triangle you want to delete.\nIf you don't want to delete a triangle please type 'q':";
                        std::cin >> deleteIndexString;
                        if (isNumber(deleteIndexString)) {
                            int c = std::stoi(deleteIndexString);
                            if((c < 0) || (c > object_strings[index].triangles.size() - 1)) {
                                std::cout << "Invalid index. The triangle does not exist\n";
                                goto deleteIndexInput;
                            } else {
                                deleteIndex = c;
                                object_strings[index].triangles.erase(object_strings[index].triangles.begin() + deleteIndex);
                            }
                        }  else if (deleteIndexString == "q") {
                        } else {
                            std::cout << "Invalid index\n";
                            goto deleteIndexInput;
                        }
                    } else if (objectPrompt == "q") {
                        QuitObject:
                        std::string w;
                        std::cout << "Are you sure you wan t to quit editing this object (" << index << ", " << object_strings[index].name << ")? (y/n)\n";
                        std::cin >> w;
                        if (w == "y") {
                            quit = true;
                        } else if (w == "n") {}
                        else {
                            std::cout << "Unexpected answer: " << w << std::endl;
                            goto QuitObject;
                        }
                    } else {
                        std::cout << "\nInvalid command" << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid command\n";
            }
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
} 

