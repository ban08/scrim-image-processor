# scrim-image-processor

A small command language for editing PNG images: write a script of operations, run it, and get a transformed image out.

## What it does

Interprets **`.scrim`** scripts — a tiny image-processing language. A script opens or creates an image and applies a sequence of 19 operations, then saves the result. Operations include fill, invert, to-grayscale, horizontal/vertical mirror, crop, resize, scale-up, rotate left/right, move, slide, replace-colour, add (compositing) and chaining scripts together.

Two executables are built:

- `runscrim` — runs a `.scrim` script.
- `tester` — runs the whole `scrims/` suite and diffs each output against the expected image.

## Stack

C++17, CMake, [stb_image](https://github.com/nothings/stb) for PNG I/O. Compiled with `-Wall -pedantic -Werror` and AddressSanitizer / UndefinedBehaviorSanitizer enabled.

## How to run

```bash
cmake -S project -B build
cmake --build build
./build/runscrim project/scrims/crop1.scrim   # run one script
./build/tester                                 # run the full test suite
```

The test suite passes all **69** cases.

## What I built

Group project of three for the Programming course (2024/25). I wrote the large majority of the codebase — the image model, the PNG wrapper, the script parser, the command classes and the test driver — with teammates contributing specific commands (including the rotate operations).

## What I would do differently

The sanitizers still report memory leaks on some commands (for example `RotateRight`), because a few operations allocate a new image without freeing the old one. I would move the image ownership onto RAII types (`std::unique_ptr`) so those leaks cannot happen, and add unit tests per command rather than only whole-script comparisons.
