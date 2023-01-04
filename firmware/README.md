How to build
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Clone the repository
3. Run these commands from the root folder:

```shell
# Change directory to firmware
$ cd firmware

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Clean build files
$ pio run --target clean
```