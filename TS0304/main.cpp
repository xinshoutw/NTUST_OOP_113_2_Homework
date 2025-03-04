#include <cassert>
#include <iostream>
#include <cstdint>
#include <iomanip>

uint64_t kBorderHeight;
uint64_t kBorderWidth;
bool* kCanvas;

void DrawCanvas() {
    for (int y = 0; y < kBorderHeight; ++y) {
        for (int x = 0; x < kBorderWidth; ++x) {
            if (kCanvas[y * kBorderWidth + x]) {
                std::cout << "X";
            } else {
                std::cout << "*";
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void ProcessDrawSquare() {
    int64_t length;
    int64_t x1, y1;
    std::cin >> length >> x1 >> y1;

    // border check
    if ((x1 < 0) ||
        (y1 < 0) ||
        (x1 + length > kBorderWidth) ||
        (y1 + length > kBorderHeight)
    ) {
        std::cout << "Out of range.\n\n";
        return;
    }

    for (int y = 0; y < length; ++y) {
        std::fill_n(kCanvas + (x1 + (y1 + y) * kBorderWidth), length, true);
    }

    DrawCanvas();
}

void ProcessDrawLine() {
    int64_t x1, y1;
    int64_t x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;


    // border check
    if ((x1 < 0) || (x1 >= kBorderWidth) ||
        (y1 < 0) || (y1 >= kBorderHeight) ||
        (x2 < 0) || (x2 >= kBorderWidth) ||
        (y2 < 0) || (y2 >= kBorderHeight)
    ) {
        std::cout << "Out of range.\n\n";
        return;
    }

    // assert line is always in vertical or horizon
    assert(x1 == x2 || y1 == y2);

    if (x1 == x2) { // vertical
        const int64_t up_y = std::min(y1, y2);
        const int64_t down_y = std::max(y1, y2);

        for (int64_t y = up_y; y <= down_y; ++y) {
            kCanvas[x1 + y * kBorderWidth] = true;
        }
    } else { // horizon
        const int64_t x_left = std::min(x1, x2);
        const int64_t x_right = std::max(x1, x2);
        std::fill_n(kCanvas + (y1 * kBorderWidth + x_left), x_right - x_left + 1, true);
    }

    DrawCanvas();
}

void ProcessDrawTriangle() {
    int64_t length;
    int64_t x1, y1;
    char facing[3]; // include '\0'
    std::cin >> length >> x1 >> y1 >> facing;

    // border check
    if ((x1 < 0) || (y1 < 0)) {
        std::cout << "Out of range1.\n\n";
        return;
    }

    if (facing[0] == 'R') {
        if (x1 + length > kBorderWidth) {
            std::cout << "Out of range2.\n\n";
            return;
        }
    } else {
        if ((x1 - length) < -1) {
            std::cout << "Out of range3.\n\n";
            return;
        }
    }

    if (facing[1] == 'D') {
        if (y1 + length > kBorderHeight) {
            std::cout << "Out of range4.\n\n";
            return;
        }
    } else {
        if ((y1 - length) < -1) {
            std::cout << "Out of range5.\n\n";
            return;
        }
    }

    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length - y; ++x) {
            kCanvas[
                (y1 + ((facing[1] == 'D') ? y : -y)) * kBorderWidth +
                (x1 + ((facing[0] == 'R') ? x : -x))
            ] = true;
        }
    }

    DrawCanvas();
}

int main() {
    std::cin >> kBorderWidth >> kBorderHeight;
    kCanvas = new bool[kBorderHeight * kBorderWidth]{false};

    char input_draw_type;
    while (std::cin >> input_draw_type) {
        switch (input_draw_type) {
        case 'S': {
            ProcessDrawSquare();
            break;
        }
        case 'L': {
            ProcessDrawLine();
            break;
        }
        case 'T': {
            ProcessDrawTriangle();
            break;
        }
        default: ;
        }
    }

    return 0;
}
