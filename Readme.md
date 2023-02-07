<img src="https://raw.githubusercontent.com/Aldaviva/volumectl/master/icon.ico" height="23" alt="volumectl icon" /> volumectl
===

[![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/Aldaviva/volumectl/cmake.yml?branch=master&logo=github)](https://github.com/Aldaviva/volumectl/actions/workflows/cmake.yml)

Useful if you want your [Griffin PowerMate](https://en.wikipedia.org/wiki/Griffin_PowerMate) to change your audio volume, but want it to use 1 percentage point increments instead of 2, and you want it to keep working when another program like Remote Desktop Connection is intercepting special keys.

## Requirements
- Windows Vista or later
- [Visual C++ 2015 (14.0) x64 runtime](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170#visual-studio-2015-2017-2019-and-2022)

## Usage

### Increase volume
```ps1
volumectl.exe up
```

The output volume of the default audio output device increases by 1 percentage point.

### Decrease volume
```ps1
volumectl.exe down
```

The output volume of the default audio output device decreases by 1 percentage point.

### Toggle mute
```ps1
volumectl.exe mute
```

The output of the default audio output device is toggled between being muted and unmuted.