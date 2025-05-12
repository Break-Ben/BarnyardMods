# Barnyard Mods
[OpenBarnyard](https://github.com/InfiniteC0re/OpenBarnyard) | [Barnyard Launcher](https://github.com/InfiniteC0re/BarnyardLauncher) | [Discord](https://discord.gg/3bMq8hWvFX)

My mods made for the video game Barnyard.

Project created for [OpenBarnyard](https://github.com/InfiniteC0re/OpenBarnyard), using [InfiniteC0re's Mod Template](https://github.com/InfiniteC0re/Barnyard-Mod-Template). Requires BYModLoader to use.

## Notes
> [!IMPORTANT]
> **SUPPORT THE DEVELOPERS OF THE TOSHI ENGINE**
> 
> We do not own the Toshi Engine in any way, shape or form, and this project would not have been possible had they not developed TOSHI in the first place. The Toshi Engine is currently owned by [THQ Nordic](https://www.thqnordic.com); we highly urge you to follow & support their projects if you like this project!

> [!WARNING]
> **DO NOT USE THIS DECOMPILATION PROJECT AS A MEANS TO PIRATE BARNYARD OR ANY OTHER TOSHI GAMES!**
> 
> We do not condone using this project as a means for piracy in any form. This project was made with love and care for the source material and was created for purely educational purposes. 

## Mods
- **[CheatMenu](https://github.com/Break-Ben/BarnyardMods/tree/main/CheatMenu)** - A cheat/mod menu that gives you access to some traditional game hacks, such as increased movement speed.

## Installation
1. Install the [OpenBarnyard](https://github.com/InfiniteC0re/OpenBarnyard) modloader (WIP)
2. Download the DLL of a mod from the [releases](https://github.com/Break-Ben/BarnyardMods/releases) and add it to the `Mods/` directory of your OpenBarnyard installation

## Building
1. Create an `OpenBarnyard/` folder
2. Create a `Game/` folder in `OpenBarnyard/`
3. Copy original game files, `Bahnschrift.ttf` and the `BYardModLoader.exe` (get it from the Winter Mod or somewhere else) file into `Game/`
4. Clone this repository into `OpenBarnyard/`
5. The structure should look like this:

    ```
    .
    └── OpenBarnyard/
        ├── Game/
        │   ├── BYardModLoader.exe
        │   ├── Bahnschrift.ttf
        │   ├── Barnyard.exe
        │   └── ...
        └── BarnyardMods/
    ```
6. CD into `BarnyardMods/`
7. Run `GenerateProjects-WIN-VS2022.bat` to generate project files
8. Open the generated solution file