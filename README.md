# Just a simple todo-program
This is a simple console-based to-do list program. It allows you to create, view, and manage tasks, and saves them to a JSON file for persistence.

# Dependencies
This project uses the **nlohmann/json** library for JSON operations.
Make sure you have it installed before building the project.

# Build
This project supports both CMake and Make. To build and run the program:
``` bash
mkdir Build && cd Build
cmake ..
make
./todo
```