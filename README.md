# Game of Life

It's a personal project who have to goal to recreate many variations of game of life.

## Compilation

Linux :
```
git clone git@github.com:DonatNathan/game-of-life.git
cd game-of-life
make
```

## Launch the game

Linux :
```
./game_of_life <type> <iterations> <width> <height> <...>
```
You can find examples in the start.txt file.

### Arguments
Arg | Description
--- | -----------
type | Choose the variant of the automate
iterations | The number of iteration to do
width | Represent the width of the map
height | Represent the height of the map
... | Position of first alive cells ("x-y")

### Variants
Name | Description
---- | -----------
game_of_life | The basic game
hight_life | Differents rules
day_night | Differents rules
life_34 | Differents rules
