
# LabelFilter

Basic implementation of map/chart decluttering labels algorithm.
It will determine which labels should be shown on the screen, and wchich should not, depending on the labels position, collisions and priority. Labels on the left are prefered.

There are two algorithms provided. "stable" and "showMore".

## Algorithms:

### Stable algorithm

Pros:
 - When label is displayed from far away - it will always be shown on close up
 
Cons:
 - Slightly slower ( 4ms for 1000 labels, 0.25ms for 100 labels )
 - Less labels are displayed (due to collision propagation - look at the end of this document)


Visualization:

![Visualization of the algorithm](img/sneak_peak_visualization_stable.gif "Visualization of stable algorithm")


### showMore algorithm

Pros:
 - Slightly faster (1.6ms for 1000 labels, 0.12ms for 100 labels )
 - No collision propagation - more labels are shown

Cons:
 - labels may show and dissapear at different level



Visualization:

![Visualization of the algorithm](img/sneak_peak_visualization.gif "Visualization of showMore algorithm")


# Compilation

```
mkdir build
cd build
cmake ..
make
```

# Testing
## Console tester

Default tester is build by `make` command. To run it with a default settings - 33 labels in 3 datasets (99 labels total). execute command:

```
 ./build/test/ConsoleTester 
```

You can also modify the number of labels (second param) and datasets (first param).
```
 ./build/test/ConsoleTester [NUMBER_OF_LISTS=3] [NUMBER_OF_LABELS_ON_THE_LIST=33]
```
For example if I want to create 4 groups with 25 labels each i have to execute:
```
 ./build/test/ConsoleTester 4 25
```

Tester is printing all the details of random generated datasets, then filtering them and printing names of all the selected ones.

Then speed test is performed : It repeats 1000x both stable and showMore algorithm to calculate average execution time.

## Visual tester
### Dependences

Visual tester needs to run:
- opencv ( https://opencv.org/ )

install opencv from repository (https://github.com/opencv/opencv/releases) or you OS package manager e.g.:
```
pamac install opencv
```

###Compilation of visual tests:
```
cd build
cmake -DWITH_VISUAL_TESTS=1 ..
make
```

### Testing

```
cd build
./test/VisualTester [NUMBER_OF_LISTS=3] [NUMBER_OF_LABELS_ON_THE_LIST=33]
```

You can zoom with mouse scroll and pan with left mouse button.
Press ESC to exit.


## Why I've used sorting algorithm before collision detection?

![Positioning labels example](img/positioning_labels1.jpg?raw=true "Example 1")
![Positioning labels example](img/positioning_labels2.jpg?raw=true "Example 2")


## Future improvement

![Positioning labels example](img/positioning_labels3.jpg?raw=true "Example 3")
![Positioning labels example](img/positioning_labels4.jpg?raw=true "Example 4")

 - For larger datasets Spartial Hashmap should be considered

Author: Łukasz Bolda