#ifndef ARGS_H
#define ARGS_H

enum action_t
{
    EXIT,
    LOAD,
    SAVE,
    MOVE,
    SCALE,
    ROTATE
};

struct trans_args_t
{
    double x, y, z;
};

struct args_t
{
    action_t action;
    trans_args_t tr_args;
    const char *name;
};

#endif // ARGS_H
