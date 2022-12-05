# FDF

Fdf (wireframe model) is a 42 project which is about representing a landscape as a 3D object
in which all surfaces are outlined in lines.

## Instal

Copy the command line and execute it in your consol.

```git clone git@github.com:Thib1708/fdf.git```

## Runing 

Use the "make" command to compile the project then execute the new file created called "fdf" with a map.

```make; ./fdf test_map/42.fdf```
![Alt text]([/Users/thibaultgiraudon/Desktop/img.jpg?raw=true "Title"](https://lh5.googleusercontent.com/sQOUM1SIdgLqNdRSpSHQy8Plkb_C00ojLzl7TW3maHfRCbJOHzhvbeDDPOvpvi7yNOMF32B9uJimTx3_a2uS_PsS13hDdvx_POtQgnNRw56v5wLUsM9v6UXttnRSZND6VxapPd5-jAtDYmRXFy520ll9IHqvC64VDQ9UbdYnWPqpblcI_Zfq7YHlgU9IBTeq=w1280))

## How it work 

### Pars the file
The subject advice you to use your get_next_line and split functions. Thats what I do.
First I get a line with get_next_line then with ft_split I retrive only the number and with the atoi function I transform all strings into integer.
I put all these value into an 2D array.

### Isometric perspective
To convert 3D coordonate into 2D coordonate I use a formula found on the french isometric perspective's wikipedia page.

### MinilibX
Thanks to the mlx (minilibX) I can create a window, an image and display color pixel on it.
Using the bresenham algorithm I learn to draw a line from a point A to B. 
