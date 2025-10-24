#pragma once
#include "raylib.h"
#include <array>
#include <cstring>

class Block {
public:
    unsigned int id; // unique id
    Color color;
    std::array<std::array<bool, 3>, 3> cells;

    int row = 0;
    int col = 0;

    virtual void draw();
    virtual void move(int rows, int cols);
    virtual void rotate_clock();
    virtual void rotate_anti_clock();

    Block() = default;
    virtual ~Block() = default;
};

class Block_L : public Block {
public:
    Block_L();
};
class Block_J : public Block {
public:
    Block_J();
};
class Block_I : public Block {
public:
    Block_I();
};
class Block_S : public Block {
public:
    Block_S();
};
class Block_T : public Block {
public:
    Block_T();
};
class Block_Z : public Block {
public:
    Block_Z();
};
