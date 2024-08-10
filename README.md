# FdF

FdF, short for "fil de fer" in French, which means wireframe model. This project represents a landscape as a 3D object, in which all surfaces are outlined in lines, and mainly in isometric projection.

In the project, [MLX42](https://github.com/codam-coding-college/MLX42) graphics library is used for opening a window, drawing images, as well as handling mouse and keyboard events.

## Selected visual representations
<img width="600" alt="fdf-42" src="https://github.com/user-attachments/assets/9ebdb24c-a590-4184-9233-43dee9068594">

*42 in isometric projection*

<img width="600" alt="fdf-42" src="https://github.com/user-attachments/assets/5574394c-6e84-4b97-9382-b982c74250bf">

*julia in isometric projection*

<img width="600" alt="fdf-42" src="https://github.com/user-attachments/assets/15521c6c-a1d9-4c57-b316-a39f386dce2e">

*julia in parallel projection*


## Usage
To run the program with the map 42.fdf for example  
*On macOS*
```
make bonus && ./fdf maps/42.fdf
```
*On Linux*
```
make -f Makefile_linux bonus && ./fdf maps/42.fdf
```

ACTIONS                                   | KEYS / MOUSE
| :---                                    | :---:
Apply colors                              | C
Translate                                 | WSAD
Rotate                                    | Arrow keys up, down, left, right
Zoom                                      | Numpad +- / Mouse scrolling up/down
Increment height                          | X
Decrement height                          | Z
Switch to parallel projection             | P
Switch to isometric projection (default)  | I
Reset to initial state                    | Space
Quit                                      | ESC
