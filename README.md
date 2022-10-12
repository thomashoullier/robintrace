# Poaky
Poaky is a raytracing engine for optical design. It is implemented
in C++.

## Scope
The scope for the implementation starts at low level components and gradually
moves upwards in abstraction. The main focus is on low level performance.

## Build
Switch to a `/build` directory at the root of the project folder. Run:

```shell
cmake ..
cmake --build .
```

## Coverage report
We use the cmake module
[CodeCoverage](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake),
with the GCOVR tool.

Build the report with

```shell
make coverage_report
```

## Licensing
The software is licensed under MIT, the documentation under CC-BY.
