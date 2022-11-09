
# LabelFilter

Basic implementation of map/chart decluttering labels algorithm.
It will determine which labels should be shown on the screen, and wchich should not, depending on the labels position, collisions and priority.

## Visualization:
![Visualization of the algorithm](img/sneak_peak_visualization.gif "Visualization 1")

# Compilation

```
mkdir build
cd build
cmake ..
make
```

# Testing environment (visual):
## Dependences

- opencv ( https://opencv.org/ )

install opencv from repository (https://github.com/opencv/opencv/releases) or you OS package manager e.g.:
```
pamac install opencv
```

## Testing

```
./test/LabelFilterTest ../test/img/map.png
```


## Why I've used sorting algorithm before collision detection?

![Positioning labels example](img/positioning_labels1.jpg?raw=true "Example 1")
![Positioning labels example](img/positioning_labels2.jpg?raw=true "Example 2")


## Future improvement

![Positioning labels example](img/positioning_labels3.jpg?raw=true "Example 3")
![Positioning labels example](img/positioning_labels4.jpg?raw=true "Example 4")


Author: Łukasz Bolda