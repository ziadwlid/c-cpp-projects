#include "../include/draw_shapes.h"
#include <draw_shapes.h>
#include <iostream>

void draw_shapes::rectangle(int width, int length) {
    if (width <= 0 || length <= 0)
        return;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << "# ";
        }
        std::cout << "\n";
    }
}
void draw_shapes::square(int length) {
    if (length <= 0)
        return;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << "# ";
        }
        std::cout << "\n";
    }
}

