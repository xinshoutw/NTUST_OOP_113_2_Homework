#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <cstdint>
#include <unordered_set>
#include <vector>

class NumberGame {
public:
    NumberGame() = default;
    void SetInput(int32_t inp);
    void ProcessInput();
    void SetFileName(const char* fileName);
    void LoadNumberList();
    void PrintAllValid() const;
    void Reset();

private:
    int32_t inp{};
    const char* fileName{};

    std::unordered_set<int32_t> possibles;
    std::vector<int32_t> founds;
};

#endif // NUMBERGAME_H
