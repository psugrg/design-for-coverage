# Design guidelines for better tests

The case here is to be able to fully cover the code inside of this class using tests.

## Development environment

The project can be compile using the Docker-based development environment.

### Create Docker image

> [!IMPORTANT]
>
> - Export `UID` to expose the user id as an environment variable by calling `export UID=${UID}`[^1].

Run the following command to compile and run the complete suite

```sh
docker compose build && docker compose up -d
```

[^1]: This should be done even if there's an automatic Bash `UID` read only variable present since it is ignored by the docker.

## Code Formatting

Code formatting is based on
[clang-format](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
utility. It uses the `./.clang-format` file containing the style configuration.
The code formatting operation will not be triggered by build but can
be manually/automatically triggered by the IDE.

### Configuration in VS Code

Hit `Ctrl+Shift+P` and search for `Open User Settings`.
Search for `format` and select `Editor: Format On Save`.

## Static Analysis

Static analysis is done using [cppcheck](https://github.com/danmar/cppcheck)
tool. Custom target `scheck` is handling the static analysis process. This
target is a part of the `ALL` group which means that it'll be run automatically
by make when `make` or `make all` command is executed.

### Static Analysis Usage

- Run `make scheck` in the `./build` folder to start static analysis manually.

### SonarQube

[SonarQube](https://marketplace.visualstudio.com/items?itemName=SonarSource.sonarlint-vscode) is a very usefull on-the-fly static analysis tool for your Visual Studio Code.

## Unit Tests

Unit tests are using [GoogleTest](https://github.com/google/googletest)
framework. This project uses an installed version of the *GoogleTest* framework.

### Unit Tests Usage

- Run `ctest -VV` in the `./build` folder to start tests.

## Code Coverage

Code coverage analysis is done using the
[gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) as the coverage testing
utility and the [gcovr](https://github.com/gcovr/gcovr) for presentation.

### Code Coverage Usage

- Navigate to the build folder.
- Run `cmake -DCMAKE_BUILD_TYPE=Coverage ..` to configure coverage build.
- Run `make` to build the application.
- Run `ctest -VV` to test the application.
- Run `make coverage` to get the coverage results.
