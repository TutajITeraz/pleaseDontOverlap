

## Compilation

```
mkdir build
cd build
cmake ..
make
```

# Testing environment:
## Installation

```
pip install dearpygui
```

## Testing

```
python ./test/tester.py
```


# Testing environment c++:
## Dependencies

- imgui v1.88 from https://github.com/ocornut/imgui/releases

```
mkdir deps
cd deps
git clone https://github.com/ocornut/imgui
```

install imgui on your system for example:
```
pamac install imgui
```

## Testing

```
python ./test/tester.py
```


