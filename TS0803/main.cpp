#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int64_t memSize, cmds;

    string inpMethod;
    int64_t inpPos;
    string inpType;

    string inpValueString;
    int64_t inpValue;

    cin >> memSize >> cmds;
    auto* mems = new uint8_t[memSize];
    memset(mems, '\0', memSize);

    for (int cmd = 0; cmd < cmds; ++cmd) {
        cin >> inpMethod >> inpPos >> inpType;

        if (inpMethod == "Set") {
            if (inpType == "String") {
                cin >> ws;
                getline(cin, inpValueString);

                for (size_t i = 0; i < inpValueString.size(); ++i) {
                    if (inpPos + i >= memSize) {
                        cout << "Violation Access.\n";
                        break;
                    }
                    mems[inpPos + i] = inpValueString[i];
                }
            } else if (inpType == "int") {
                cin >> inpValue;

                for (int i = 0; i < 4; ++i, inpValue >>= 8) {
                    if (inpPos + i >= memSize) {
                        cout << "Violation Access.\n";
                        break;
                    }
                    mems[inpPos + i] = inpValue & 0xFF;
                }
            } else if (inpType == "short") {
                cin >> inpValue;

                for (int i = 0; i < 2; ++i, inpValue >>= 8) {
                    if (inpPos + i >= memSize) {
                        cout << "Violation Access.\n";
                        break;
                    }
                    mems[inpPos + i] = inpValue & 0xFF;
                }
            } else if (inpType == "char") {
                cin >> inpValue;
                if (inpPos >= memSize) {
                    cout << "Violation Access.\n";
                    continue;
                }
                mems[inpPos] = inpValue;
            }
        }

        if (inpMethod == "Get") {
            if (inpPos >= memSize) {
                cout << "Violation Access.\n";
                continue;
            }

            if (inpType == "String") {
                for (size_t i = 0; (inpPos + i < memSize) && (*(mems + inpPos + i) != '\0'); ++i) {
                    cout << (static_cast<char>(*(mems + inpPos + i)));
                }
                cout << '\n';
            } else if (inpType == "int") {
                if (inpPos + 3 >= memSize) {
                    cout << "Violation Access.\n";
                    continue;
                }

                int32_t result = 0;
                for (int i = 3; i >= 0; --i) {
                    result = (result << 8) | *(mems + inpPos + i);
                }
                cout << result << '\n';
            } else if (inpType == "short") {
                if (inpPos + 1 >= memSize) {
                    cout << "Violation Access.\n";
                    continue;
                }

                int32_t result = 0;
                for (int i = 1; i >= 0; --i) {
                    result = (result << 8) | *(mems + inpPos + i);
                }
                cout << result << '\n';
            } else if (inpType == "char") {
                cout << static_cast<unsigned int>(mems[inpPos]) << '\n';
            }
        }
    }

    delete[] mems;
}
