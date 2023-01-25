# FDF

Fdf (wireframe model) is a 42 project which is about representing a landscape as a 3D object
in which all surfaces are outlined in lines.

## Instal

Copy the command line and execute it in your consol.

```git clone git@github.com:Thib1708/fdf.git```

## Runing 

Use the "make" command to compile the project then execute the new file created called "fdf" with a map.

```make; ./fdf test_map/42.fdf```

![alt text](https://github.com/Thib1708/fdf/blob/main/assets/42test.png?raw=true)

## How it work 

Fdf work with an map given as argument such as : //LINK TO MAP
First, we need to pars this file in a 2D array, then transform a point a(x,y,z) in 3D space to a point b(x,y) in 2D space and finaly draw line between those points.

### Pars the file
I parsed the file a first time to get the leght and the heigh of the map and check if the are only integer and all the lie have the same leght.
I parsed the file a second time to saved each line one by one in the 2D array allocated to the right size.

### Transform point and draw line
I've decided to draw line one by one from the current to the closer one below and the one on the rigth.
