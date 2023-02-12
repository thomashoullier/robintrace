# RobinTrace

![status](https://raw.githubusercontent.com/thomashoullier/badges/master/status-maintained.svg)
![stage](https://raw.githubusercontent.com/thomashoullier/badges/master/stage-alpha.svg)

[![Build Status](https://drone.git-or-miss.com/api/badges/thomashoullier/poaky/status.svg)](https://drone.git-or-miss.com/thomashoullier/poaky)
[![codecov](https://codecov.io/gh/thomashoullier/poaky/branch/master/graph/badge.svg?token=YNL10VWFW2)](https://codecov.io/gh/thomashoullier/poaky)

RobinTrace is a sequential raytracing API for optical design.
It is implemented in C++.

<img src="doc/images/robintrace-logo.png" alt="RobinTrace logo" width="256"/>

## Documentation
Please refer to the Doxygen documentation (TODO).

In addition, the submodule poaky has its own LaTeX documentation.
The report can be compiled from the LaTeX files in `doc`. A compiled version is
edited at [Poaky documentation
PDF](https://thomashoullier.com/writeups/robintrace-poaky/robintrace-poaky.html).

## Build
RobinTrace is configured with cmake. By default, only the library is built.
You can enable executable targets by setting the corresponding options.

Switch to a `/build` directory at the root of the project folder. Run:

```shell
cmake -Dpoaky_build_tests=ON
      -Dpoaky_build_benchmark=ON
      -Dpoaky_build_coverage=ON ..
```

This will download the dependencies and prepare the build targets.
The build targets are the following:

* `poaky_test`: Test suite.
* `poaky_benchmark`: Benchmark suite.
* `poaky_coverage_report`: Code coverage report of the test suite. The report
  may be consulted at `build/poaky_coverage_report/index.html`.

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
