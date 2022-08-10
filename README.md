# LED-cube-Bhathi
embedded system

# 8×8×8 LED cube with Interrupts
## Introduction

A microcontroller is a small computer. Both have several things common like the CPU 
(central processing unit), execution of programs, presence of RAM (random-access memory) 
etc. Then we can assume microcontroller is “special purpose computer”. It is often low- power 
device and it is often small and low cost. Today the technology has advanced to such an extent 
that has come a need to display electronic messages to satisfy all purposes, whether it is 
business or domestic use. The solution found to satisfy this need is the matrix display systems 
using LEDs or LCDs. It provides instantaneous and flexible communications.


In this project, 8x8x8 LED cube was selected to build, which has 512 LEDs. LED cube is
like a LED screen, but it is special in that it has a third dimension, making it 3D. In normal 
displays, it is normal to try to stack the pixels as close as possible in order to make it look 
better, but in a cube, one must be able to see through it. A LED cube does not have to be 
symmetrical all the time. It is possible to make an 8x9x10, or even oddly shaped ones. Here I 
have an 8x8x8 shaped one. The code is written in the C language using AVR studio and it is 
burned into the ATmega32 microcontroller using USBasp cable and ATmega32 development 
board.


This LED cube has 512 LEDs. Obviously, having a dedicated IO port for each LED would 
be very impractical. Therefore, I have to use 74HC595 shift registers to solve that issue. In 
here, actually LED cube relies on an optical phenomenon called persistence of vision (POV). If 
we flash a led fast, the image will stay on our retina for a little while after the led turns off. By 
flashing each layer of the cube one after another fast, it gives the illusion of a 3D image and 
looking at a series of 2D images stacked onto one another called multiplexing. Those two 
phenomenon were used in this Project.


Basically, the project is a 3D LED cube display (8x8x8 pixel) which displays different 
patterns. Patterns can change using push buttons. All circuits were soldered on zero dot boars 
permanently. All the displaying patterns were stored in the microcontroller. All the patterns 
were controlled using nine shift registers. The patterns are displayed on a 3D structure, which 
is made up of steel rods. The complete display system circuit is power supply run on 5V, 4A 
that is provided externally. This unique way of displaying messages is a very eye catching. 
Therefore it can uses in the field of advertising, toys, decorating etc.


Full report link : https://github.com/bhathi97/LED-cube-Bhathi/blob/main/report.pdf


Video link : https://github.com/bhathi97/LED-cube-Bhathi/blob/main/video.m4v


## guid line
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/guid3.png)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/guid1.png)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/guid2.png)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/guid4.png)


## photos
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic1.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic2.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic3.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic4.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic5.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic6.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic7.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic8.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic9.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic10.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic11.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic12.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic13.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic14.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic15.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic16.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic17.jpg)
![](https://github.com/bhathi97/LED-cube-Bhathi/blob/main/pic18.jpg)








