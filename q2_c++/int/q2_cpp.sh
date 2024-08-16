#!/bin/bash

# Define the C++ source file and the output executable name
SOURCE_FILE="main.cpp"
EXECUTABLE="my_program"

# Compile the C++ source file with clang
clang++ -o $EXECUTABLE $SOURCE_FILE

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    ./$EXECUTABLE
else
    echo "Compilation failed."
fi
