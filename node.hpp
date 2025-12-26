#pragma once

#include <godot_cpp/classes/node.hpp>

class MyNode : public godot::Node
{
    GDCLASS(MyNode, godot::Node);

public:
    MyNode();

protected:
    static void _bind_methods() {}
};
