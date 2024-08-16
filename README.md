# Plants vs. Zombies SFML Game

This is a custom implementation of the popular game *Plants vs. Zombies* using the [Simple and Fast Multimedia Library (SFML)](https://www.sfml-dev.org/). The game features various plant and zombie classes, each with unique attributes and abilities.

## Getting Started

### Prerequisites

To build and run this game, you'll need:

- A C++ compiler (e.g., g++, clang++)
- [SFML](https://www.sfml-dev.org/download.php) installed on your system
- [Visual Studio](https://visualstudio.microsoft.com/) (or another IDE of your choice)

### Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/FatimaRana40/Plantsvszombies.git
   cd Plantsvszombies
Install SFML:

Windows:

Download the SFML SDK from the SFML website.
Extract the SDK to a location on your system.
Open Visual Studio and create a new project or open an existing one.
Configure the project to include the SFML headers and link against the SFML libraries:
Right-click on the project in Solution Explorer and select Properties.
Under Configuration Properties, go to VC++ Directories and add the path to the SFML include directory in Include Directories.
Add the path to the SFML lib directory in Library Directories.
Under Configuration Properties -> Linker -> Input, add the SFML libraries (e.g., sfml-graphics-d.lib, sfml-window-d.lib, sfml-system-d.lib) to Additional Dependencies.
macOS:

Install SFML using Homebrew
brew install sfml
Configure your project to link against SFML libraries. You might need to adjust your build settings to include the SFML headers and link the SFML libraries.
Linux:

Install SFML using your package manager. For example, on Ubuntu
sudo apt-get install libsfml-dev
Configure your project to include SFML headers and link the SFML libraries.
Build and Run:

Visual Studio:

Open the .sln file in Visual Studio.
Build the project by selecting Build -> Build Solution from the menu.
Run the project by pressing F5 or selecting Debug -> Start Debugging.
Other IDEs:

Configure the build system to include SFML headers and link SFML libraries.
Compile and run the project using the build tools provided by your IDE.
Features
Plants: Includes Peashooter, Sunflower, Wallnut, and more, each with unique abilities.
Zombies: Various zombie types with different behaviors and strengths.
Gameplay: A turn-based strategy game where you must defend your home from waves of zombies by strategically placing plants.
Levels: Multiple levels with increasing difficulty.
File Structure
main.cpp: The entry point of the game.
header.h: Contains the class declarations and member functions.
Plants.cpp, Zombies.cpp, etc.: Implementation files for different game entities.
Contributing
If you would like to contribute to the project, feel free to fork the repository and submit a pull request. Please ensure that your code follows the existing style and conventions.
Acknowledgments
SFML: The game was built using the Simple and Fast Multimedia Library.
Inspiration: Inspired by the original Plants vs. Zombies game by PopCap Games.
