# Source SDK 2013 EX-Ten-ded

Source code for Source SDK 2013.

Contains the game code for Half-Life 2: Deathmatch.

## Build instructions

Clone the repository using the following command:

`git clone https://github.com/yungDoom/source-sdk-2013-extended`

**You need [Git](https://git-scm.com/) in order to execute this command.**

### Windows

Requirements:
 - Source SDK 2013 Multiplayer installed via Steam
 - Visual Studio 2022 with the following workload and components:
   - Desktop development with C++:
     - MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
     - Windows 11 SDK (10.0.22621.0) or Windows 10 SDK (10.0.19041.1)
 - Python 3.13 or later

Open `everything.sln` which will be used to build your mod.

Then, on the menu bar, go to `Build > Build Solution`, and wait for everything to build.

You can then select the `Launcher Main (Mod Name)` project you wish to run, right click and select `Set as Startup Project` and hit the big green `> Local Windows Debugger` button on the tool bar in order to launch your mod.

Then Go into properties of that project, and under `Debugging`, find the `Command` and set it to `..\..\game\mod_hl2mp_win64.exe`.<br>
This will allow you to run your mod directly from Visual Studio.


### Linux

Requirements:
 - Source SDK 2013 Multiplayer installed via Steam
 - podman

Inside the cloned directory, navigate to `src`, run:
```bash
./buildallprojects
```

This will build all the projects related to the SDK and your mods automatically against the Steam Runtime.

You can then, in the root of the cloned directory, you can navigate to `game` and run your mod by launching the build launcher for your mod project, eg:
```bash
./mod_hl2mp
```

*Mods that are distributed on Steam MUST be built against the Steam Runtime, which the above steps will automatically do for you.*

## License

The SDK is licensed to users on a non-commercial basis under the [SOURCE 1 SDK LICENSE](LICENSE), which is contained in the [LICENSE](LICENSE) file in the root of the repository.

For more information, see [Distributing your Mod](#markdown-header-distributing-your-mod).
