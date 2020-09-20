# CPSC350_Assignment1
This is Assignment 1 for the Data Structures and Algorithms class. (DnaStats)

1) Identifying info 
a) Emilee Mason
b) ID# 2321064 
c) email:  emmason@chapman.edu
d) CPSC 350 - 01
e) Assignment 1: c++ review? 

2) List all source files submitted for assignment 
a) DnaStats.h //header file 
b) DnaStats.cpp //implementation file, has most if not all of the code
c) main.cpp //runs the code

3) Description of any bugs/errors:
(I have a couple things to address, I'm sorry)
I made methods that open and return fstream things (like Reader, Writer, and Appender) but for some reason I kept 
getting errors when I'd try to pass the fstream objects through a parameter into a close method (I think it has to
do with pointers and things?). So instead of having matching close methods with the open methods, I just put 
"[fstreamName].close()" when I needed to close the object.

From what I can tell, there shouldn't be too many bugs input wise. The code does tell you if you put it in wrong and
 you'll have to type in the 'quit' or 'yes' as quotes because for some reason, the tolower() and toupper() functions
weren't working correctly for me? So be aware if you run into a loop, the program should tell you why or at least have 
give you an option to put in. 

I also suspect the some of the calculations going into outputing the 1000 DNA lines might not be exactly correct? I 
think it has to do with the psuedo random number produce and the way it gets converted into an integer, it sometimes
leaves empty lines if the variance/SD is large, but I'm not super sure about that. 

Also, if you want to write a new file, the code will always out put the writen calculations and 1000 DNA strings 
to "mason.out", and it will overwrite the first one to make the new one. I'm almost postitive that's not supposed
to happen? But it does? 

4) List of references:
Overall,
cplusplus.com
tutorialspoint.com (these two helpped me understand the all the syntax/basics of c++)
stackoverflow.com (troubleshooting the specific problems/errors I was getting)

Here are some more specific code structures I looked at to fix some weird bugs or problems I couldn't solve on my own:
http://cplusplus.com/doc/tutorial/files/ 
This website helped me understand how to do basic file IO in c++.

https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
https://www.tutorialspoint.com/how-to-convert-std-string-to-lower-case-in-cplusplus
I used this idea to make the bigrams all the same case, but I couldn't figure out how to implement it to the entire
line of DNA letters.

http://cplusplus.com/doc/tutorial/pointers/
Kinda pointed me in the right direction, but I don't think I completely understand pointers and references yet.

https://www.educba.com/math-functions-in-c-plus-plus/
http://www.cplusplus.com/reference/cmath/log/
These helpped me with some math Functions in C++.

https://stackoverflow.com/questions/31089952/using-rand-rand-max-1
Helpped me understand how to get a double out of the rand() function.

5) Instructions for running Assignment: (with some docker instructions cause why not)
	1) Grab file from GitHub, unzip it(if needed), and place it within a docker accessible location
	2) Open up powershell or terminal and start up your docker container
		(ie, docker start [container], docker attach [container])
	3) cd to the file (should be labeled CPSC350_Assignment1)
	4) "make all"
	5) "./Assignment1"
	6) Follow instructions given by code.

