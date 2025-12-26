# godot-cpp-example

This is my attempt at producing the most minimal godot-cpp example possible, allowing people to learn by abstractions. 
The idea is to offload as much work as possible to CMake and vcpkg, allowing us to focus on what actually matters: understanding GDExtension.

There are other projects which attempt to set up a good template or base for working with GDExtension, and they are probably objectively "better", but they also try to do a lot, 
like enforcing best practices, setting up CI, and so on. This can easily overwhelm a new learner, and it becomes difficult to understand which parts are actually mandatory, and which are not.

This project sets up vcpkg, pulls in godot-cpp using vcpkg, and contains the most minimal code possible to register a single custom node type.

# Requirements

* CMake >= 3.24
* A C++20 compliant compiler

# Building

```
cmake -B build
cmake --build build
```

# Usage

Copy `build/libmy_gd_extension.so` (or equivalent file for your platform) as well as `my_gd_extension.gdextension` and place them in the `bin` folder of your Godot project (create it if it does not exist).

For example:

```
[znurre@znurre simple]$ tree
.
├── bin
│   ├── libmy_gd_extension.so
│   └── my_gd_extension.gdextension
├── icon.svg
├── icon.svg.import
└── project.godot

2 directories, 6 files
````

Then reload your Godot project in the editor. If everything works, you should now see `MyNode` in the list of available nodes.

Good luck!
