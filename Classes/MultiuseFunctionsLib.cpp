#include "MultiuseFunctionsLib.h"
#include <cmath>
#include <memory>

auto AddInaccuracy(int offset)->float {
    return (((rand()%offset)-offset/2)*3.14/180); // ~pi/180 because angles for bullets are in radians
}

auto generatetex(int width, int height) -> sf::Texture {
    sf::Texture texture;
    //sf::Uint8* pixels = new sf::Uint8[width * height * 4]; // * 4 because pixels have 4 components (RGBA)
    std::unique_ptr<sf::Uint8[]> pixels = std::make_unique<sf::Uint8[]>(width * height * 4); //changed to smart pointer to feel smarter
    for (int i = 0; i < width * height * 4; i += 4)
    {
        pixels[i]     = std::rand() % 256; // Red component
        pixels[i + 1] = std::rand() % 256; // Green component
        pixels[i + 2] = std::rand() % 256; // Blue component
        pixels[i + 3] = 255; // Alpha component
    }
    texture.create(width,height);
    texture.update(pixels.get());
    return texture;
}