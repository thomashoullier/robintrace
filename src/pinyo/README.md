# Pinyo
Pinyo is part of the RobinTrace project. It is the API layer above Poaky.

## Documentation
Pinyo does not contain mathematical concepts which warrant justification,
as Poaky does. As such, the most important documentation is the API
documentation (TO BE WRITTEN).

## Build
Pinyo is configured with cmake. By default, only the library is built.
You can enable executable targets by setting the corresponding options.
Switch to a `/build` directory at the root of the project folder. Run:

```shell
cmake -Dpinyo_build_main=ON
      -Dpinyo_build_tests=ON
      -Dpinyo_build_benchmark=ON
      -Dpinyo_build_coverage=ON ..
```

This will download the dependencies and prepare the build targets.
The build targets are the following:

* `pinyo_main`: Manual example file for trying out code.
* `pinyo_test`: Test suite.
* `pinyo_benchmark`: Benchmark suite.
* `pinyo_coverage_report`: Code coverage report of the test suite. The report
  may be consulted at `build/pinyo_coverage_report/index.html`.

## Dependencies
The following libraries are dependencies for tests:
* `Catch2`.

They are downloaded automatically (from online repositories) through CMake when
configuring.

## Licensing
The software is licensed under MIT.
