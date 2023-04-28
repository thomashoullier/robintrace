# RobinTrace

![status](https://raw.githubusercontent.com/thomashoullier/badges/master/status-maintained.svg)
![stage](https://raw.githubusercontent.com/thomashoullier/badges/master/stage-alpha.svg)

[![Build Status](https://drone.git-or-miss.com/api/badges/thomashoullier/robintrace/status.svg)](https://drone.git-or-miss.com/thomashoullier/robintrace)
[![codecov](https://codecov.io/gh/thomashoullier/robintrace/branch/master/graph/badge.svg?token=YNL10VWFW2)](https://codecov.io/gh/thomashoullier/robintrace)

RobinTrace is a sequential raytracing API for optical design.
It is implemented in C++.

<img src="doc/images/robintrace-logo.png" alt="RobinTrace logo" width="256"/>

## Documentation
Please refer to the [Doxygen documentation](https://thomashoullier.github.io/robintrace/index.html) (in progress).

In addition, the submodule poaky has its own LaTeX documentation.
It documents mainly the mathematical formulation of the operations and the
corresponding rationale. The API is documented in the doxygen documentation.
The report can be compiled from the LaTeX files in [latex-poaky](latex-poaky).
A compiled version is edited at [Poaky documentation
PDF](https://thomashoullier.com/writeups/robintrace-poaky/robintrace-poaky.html).

## Build
RobinTrace is configured with cmake. By default, only the library is built.
You can enable executable targets by setting the corresponding options.

Switch to a `/build` directory at the root of the project folder. Run:

```shell
cmake -Drobintrace_build_example=ON
      -Drobintrace_build_tests=ON
      -Drobintrace_build_coverage=ON
      -Drobintrace_build_benchmark=ON
      ..
```

This will download the dependencies and prepare the build targets.
The build targets are the following:

* `robintrace_example`: Example file for robintrace usage.
* `robintrace_test`: Test suite.
* `robintrace_benchmark`: Benchmark suite.
* `robintrace_coverage_report`: Code coverage report of the test suite. The
  report may be consulted at `build/robintrace_coverage_report/index.html`.

## Dependencies
We use the following libraries:
* `Eigen3`.

They are downloaded automatically (from online repositories)
through CMake when configuring.

In addition, only for tests:
* `Catch2`
* `Boost`

## Licensing
The software is licensed under MIT, the documentation under CC-BY.
