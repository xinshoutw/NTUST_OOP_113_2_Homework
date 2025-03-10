////////////////////////////////////////////////////////////////////////////////
/// @brief A drawing game on ASCII canvas.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

uint64_t kBorderHeight;
uint64_t kBorderWidth;
bool* kCanvas;

/**
 * @brief Draw kCanvas, true to be 'X', false(default) to be '*'.
 */
void DrawCanvas() {
    for (int y = 0; y < kBorderHeight; ++y) {
        for (int x = 0; x < kBorderWidth; ++x) {
            if (kCanvas[y * kBorderWidth + x]) {
                std::cout.put('X');
            } else {
                std::cout.put('*');
            }
        }
        std::cout.put('\n');
    }
    std::cout.put('\n');
}

/**
 * @brief Get inputs, check boarders, update canvas, draw canvas.
 */
void ProcessDrawSquare() {
    int64_t length;
    int64_t x1, y1;
    std::cin >> length >> x1 >> y1;

    // check borders
    if ((x1 < 0) || (y1 < 0) || (x1 + length > kBorderWidth) || (y1 + length > kBorderHeight)) {
        std::cout << "Out of range.\n\n";
        return;
    }

    for (int y = 0; y < length; ++y) {
        std::fill_n(kCanvas + (x1 + (y1 + y) * kBorderWidth), length, true);
    }

    DrawCanvas();
}

/**
 * @brief Get inputs, check boarders, update canvas, draw canvas.
 */
void ProcessDrawLine() {
    int64_t x1, y1;
    int64_t x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    // check borders
    if ((x1 < 0) || (x1 >= kBorderWidth) || (y1 < 0) || (y1 >= kBorderHeight) || (x2 < 0) || (x2 >= kBorderWidth) || (y2 < 0) || (y2 >= kBorderHeight)) {
        std::cout << "Out of range.\n\n";
        return;
    }

    if (x1 == x2) { // vertical
        const int64_t up_y = std::min(y1, y2);
        const int64_t down_y = std::max(y1, y2);

        for (int64_t y = up_y; y <= down_y; ++y) {
            kCanvas[x1 + y * kBorderWidth] = true;
        }
    } else if (y1 == y2) { // horizon
        const int64_t x_left = std::min(x1, x2);
        const int64_t x_right = std::max(x1, x2);
        std::fill_n(kCanvas + (y1 * kBorderWidth + x_left), x_right - x_left + 1, true);
    } else {
        // use vector to make (x1, y1) approach to (x2, y2)
        const int64_t distance = x2 - x1 + 1;
        const int64_t x_offset = (x2 - x1) > 0 ? 1 : -1; // point1 -> point2
        const int64_t y_offset = (y2 - y1) > 0 ? 1 : -1; // point1 -> point2
        int64_t new_x1 = x1;
        int64_t new_y1 = y1;

        for (int i = 0; i < distance; ++i) {
            kCanvas[new_x1 + new_y1 * kBorderWidth] = true;
            new_x1 += x_offset;
            new_y1 += y_offset;
        }
    }

    DrawCanvas();
}

/**
 * @brief Get inputs, check boarders, update canvas, draw canvas.
 */
void ProcessDrawTriangle() {
    int64_t length;
    int64_t x1, y1;
    char facing[3]; // include '\0'
    std::cin >> length >> x1 >> y1 >> facing;

    // check borders
    if ((x1 < 0) || (y1 < 0)) {
        std::cout << "Out of range.\n\n";
        return;
    }

    if (facing[0] == 'R') {
        if (x1 + length > kBorderWidth) {
            std::cout << "Out of range.\n\n";
            return;
        }
    } else {
        if ((x1 - length) < -1) {
            std::cout << "Out of range.\n\n";
            return;
        }
    }

    if (facing[1] == 'D') {
        if (y1 + length > kBorderHeight) {
            std::cout << "Out of range.\n\n";
            return;
        }
    } else {
        if ((y1 - length) < -1) {
            std::cout << "Out of range.\n\n";
            return;
        }
    }

    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length - y; ++x) {
            kCanvas[(y1 + ((facing[1] == 'D') ? y : -y)) * kBorderWidth + (x1 + ((facing[0] == 'R') ? x : -x))] = true;
        }
    }

    DrawCanvas();
}

int main() {
    std::cin >> kBorderWidth >> kBorderHeight;
    kCanvas = new bool[kBorderHeight * kBorderWidth]{false};

    std::string input_draw_type;

    // read until EOF
    while (std::cin >> input_draw_type) {
        if (input_draw_type == "S") {
            ProcessDrawSquare();
        } else if (input_draw_type == "L") {
            ProcessDrawLine();
        } else if (input_draw_type == "T") {
            ProcessDrawTriangle();
        } else if (input_draw_type == "EXIT") {
            break;
        }
    }

    return 0;
}
