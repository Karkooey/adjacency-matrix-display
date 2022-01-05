# Adjacency matrix

> Interactive adjacency matrix


### Setup

* MacOS:
	* Homebrew ([https://brew.sh](https://brew.sh))
	* make (`brew install make`)
	* SDL2 (`brew install sdl2`)
    * make the program with `make` in the same directory as the Makefile
    * then `make run`
* Ubuntu:
    * Make sure SDL2 is installed
    * `apt-get install libsdl2-dev`
    * build by going to the `sdl2-proj/.` directory then run `make`

* Fedora:
    * `dnf install SDL2`
    * `dnf install SDL2-devel`
    * `make`

### Controls

* `click` (the matrix top-left) to make a connection between nodes.
* `right-click` to disconnect.
* `click` a node (pink/red) to select:
	* `click` to move the node to that spot.
	* `click` another node to connect the two.
* `right-click` to unselect the node.
* Press `space-bar` to randomly place all nodes

### Gallery

![adj-mat](https://user-images.githubusercontent.com/68668573/104797195-20a85580-5821-11eb-9277-f097413a8974.png)


