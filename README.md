<p align="center">
  <a href="https://42lyon.fr/">
    <img src="https://github.com/llecoq/Cub3d/blob/master/assets/final%20grade.png" alt="cub3D" width=200 height=170>
  </a>

  <h2 align="center">cub3D</h2>

  <p align="center">
    My first RayCaster with miniLibX
    <br>
    This project is inspired by the world-famous eponymous 90’s game, which
    was the first FPS ever. It will enable you to explore ray-casting.
    <br>
    <br>
    <a href="https://github.com/llecoq/Cub3d/blob/master/assets/en.subject.pdf">English Subject </a>
    |
    <a href="https://github.com/llecoq/Cub3d/blob/master/assets/fr.subject.pdf"> Sujet en Francais</a>
  </p>
</p>


<p align="center">
    <img src="https://github.com/llecoq/Cub3d/blob/master/in_game_screenshot.bmp" alt="cub3D" width=750 height=600>
  </a>


## Table of contents

- [Quick start](#quick-start)
- [What's included](#whats-included)
- [Creators](#creators)

## What's included

```
cub3d
├── Makefile
├── assets
│   ├── en.subject.pdf
│   ├── final grade.png
│   ├── fr.subject.pdf
│   ├── maps
│   │   ├── map.cub
│   │   └── test.cub
│   ├── sound
│   │   ├── ded.mp3
│   │   ├── door.mp3
│   │   ├── explode.mp3
│   │   ├── flute.mp3
│   │   ├── quack.mp3
│   │   └── velo.mp3
│   └── xpm
│       ├── [... homemade textures ...]
│       └── wood.XPM
├── in_game_screenshot.bmp
├── includes
│   ├── cub3d.h
│   ├── minilibx
│   │   ├── [...]
│   │   └── mlx_xpm.c
│   └── struct.h
├── libft
│   ├── [...]
│   └── libft.h
├── mlx
│   └── libmlx.dylib
└── srcs
    ├── commands
    │   ├── actions.c
    │   ├── control.c
    │   ├── key_press.c
    │   └── move.c
    ├── graphic
    │   ├── bonk.c
    │   ├── cub3d.c
    │   ├── data_sprite.c
    │   ├── draw_image.c
    │   ├── draw_sprite.c
    │   ├── draw_texture.c
    │   ├── find_plan.c
    │   ├── find_sky.c
    │   ├── find_sprite.c
    │   ├── find_valid.c
    │   ├── get_sprite_plan.c
    │   ├── life_death.c
    │   ├── load_skybox.c
    │   ├── load_sprite.c
    │   ├── load_texture.c
    │   ├── load_weapon.c
    │   └── ray_casting.c
    ├── main.c
    ├── parsing
    │   ├── color_fc.c
    │   ├── error.c
    │   ├── init_flags.c
    │   ├── map_check.c
    │   ├── parsing.c
    │   ├── store_plan.c
    │   ├── store_sprite.c
    │   └── texture.c
    └── utils
        ├── calculs.c
        ├── clear_lst.c
        ├── clear_memory.c
        ├── copy_tab.c
        ├── frame_rate.c
        ├── ft_calloc_plan.c
        ├── inter_map.c
        ├── list_plan.c
        ├── save_bmp.c
        └── utils.c
```


## Quick start

printf with some bonus.

My first "big" project as I was learning basics of programmation and C.

- Clone repo :
    ```
    git clone https://github.com/llecoq/ft_printf.git
    ```
- Get inside the root of the directory :
    ```
    cd ft_printf
    ```
- Compile mandatory part
    ```
    make
    ```
- Compile mandatory + bonus part
    ```
    make bonus
    ```
- Force clean
    ```
    make fclean
    ```
## Creators

**llecoq**

- <https://github.com/llecoq>
