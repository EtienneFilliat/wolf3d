# wolf3d :wolf:
This project was one of my first graphical projects from my first year at EPITECH (2016-2017).

The goal was to create a first-person view inside of a maze by using [raycasting](https://en.wikipedia.org/wiki/Ray_casting).

<br>

Language: **C**

Group size: **1**

Compilation: **on GNU/Linux via Makefile**

Project duration: **~1 month** (12/12/2016 - 15/01/2017)

### Required library: **CSFML** graphic library
To install it: 
* on Debian / Ubuntu: `sudo apt-get install libcsfml-dev`
* on Arch Linux: `sudo pacman -S csfml`
* on other distributions, download it [here](https://www.sfml-dev.org/download/csfml/)
* or see [Docker](#-whale--docker--where-the-fun-realy-is) section

<br>

## Usage
```
  USAGE
    ./wolf3d map

  DESCRIPTION

    map     file representing the level you wanna play, containing '0' for flat area and '1' for walls.
            The map may also contain other essentials informations who will be usefull in order to have
            a great experience in game.

    Etienne FILLIAT {Tek 1.}

```
<br>

## Authorized functions for this project:

C Math library (-lm), `open`, `close`, `read`, `write`, `malloc`, `free`, `socket`, `close`, `bind`, `sendto`, `recvfrom`, all libdl’s functions

### CSFML functions:

`sfRenderWindow_isOpen`, `sfRenderWindow_pollEvent`, `sfRenderWindow_waitEvent`, `sfRenderWindow_clear`, `sfRenderWindow_drawSprite`, `sfRenderWindow_display`, `sfRenderWindow_create`, `sfRenderWindow_destroy`, `sfRenderWindow_close`, `sfTexture_create`, `sfTexture_updateFromPixels`, `sfTexture_destroy`, `sfSprite_create`, `sfSprite_setTexture`, `sfSprite_destroy`, all of System module’s functions, all of Window module’s functions, all of Audio module’s functions

## :whale: Docker, where the fun realy is

For the fun I created a `Dockerfile` to install and run the wolf3d in your browser.

To do so run:

```
docker build -t wolf3d .
docker run -d -p 5901:5901 -p 6901:6901 --user 1000 wolf3d
```

Once the Docker is running, connect to it via http://localhost:6901/?password=vncpassword

On the `Desktop` you should see a wolf3d folder on it, double click it then right click on the window and `Open Terminal Here` then you will be able to compile it with `make`

Finally run `./wolf3d map` to launch the game.