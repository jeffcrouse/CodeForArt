Chapter 1 - Getting Started
===========================

This chapter will help you get started with the basics of openFrameworks, such as the proper method for creating a project, setting window size, and basic drawing. But first...

Your First Look inside oF
-------------------------

By this point, I assume that you've http://www.openframeworks.cc/download/[downloaded openFrameworks and followed the appropriate setup guide]. So the first thing you'll want to do is uncompress the openFrameworks archive and place the resulting folder somewhere you can easily access. Personally, I like to drop it in my Documents folder and then put a shortcut in my sidebar, like this:

image:images/shortcut.png["Shortcut",width="350"]

No matter where you put it, when you open up the folder, you should see a set of folders that looks basically like this:

image::images/structure1.png[addons, apps, and libs folders]

So what are these folders?

addons;;
    The "core" openFrameworks contains only the most essential functionality. Everything in the addons folder can be added to an application piecemeal. This includes stuff like reading an XML file, loading a 3D model, or using the computer vision library, openCV. 

apps;;
	This is where the applications that you make will be stored, and where you will be working most of the time. You will notice that there are already 2 folders in "apps": "examples" and "addonExamples". 

libs;; 
	This folder contains all the libraries that openFramworks uses as well as the oF core.


NOTE:  Of course, if you are reading this documentation, you probably also have a CodeForArt folder in there with addons, apps, and libs.

Take a Tour of the Examples
---------------------------

Inside the "apps" folder, you will see 2 sub-folders: "examples" and "addonsExamples". Both of these folders contain openFrameworks projects that illustrate some of the things that openFrameworks can do. Before you get into making your own app, it's a good idea to take a tour of all of the example applications. The process is slightly different depending on which IDE you are using. 

XCode
~~~~~

Navigate to apps/examples/graphicsExample and double-click on "graphicsExample.xcodeproj". 

image::images/graphicsExample01.png["navigate to graphicsExample",width="800"]

You should see a window that looks something like this:

image::images/graphicsExample02.png["graphicsExample 02",width="800"]

IMPORTANT: Find out which version you are using in the menubar: XCode > About XCode. If you are using XCode < 4.0 the window will look significantly different, but don't panic -- it should be fairly easy to find the corresponding interface features.

You'll notice a big "Run" button at the top left side of the screen. In XCode 3, it is called "Build & Run". That will run the currently active target. But you might find that, by default, the active target is the openFrameworks library, which, by itself, doesn't do anything. What we want to run is "graphicsExample" program. So if you see this:

image::images/target-bad.png[openFrameworks library chosen]

Click and drag down so that it looks like this:

image::images/target-good.png[graphicsExample target chosen]

Now click "Run!"  You should see this:

image::images/graphicsExample03.png["graphicsExample, running",width="800"]

Press escape or Apple+Q to exit out of the program.

[WARNING]
.Troubleshooting compilation
=====================================================================
If you are getting errors, try switching the "Base SDK" setting to 10.6

. Click on the "graphicsExample" in the section on the far left
. Click on "Build Settings" as shown below
. Make sure the "All" and "Combined" ovals are selected as shown below
. Next to *Base SDK*, click and drag to "10.6"

image:images/tenpointsix.png["10.6 Fix",width="600"]

It's possible that you will have to do this for every project, so you might as well get used to it :)
=====================================================================

Now you should open and run all of the other examples.

Code::Blocks
~~~~~~~~~~~~

coming soon!

Visual Studio
~~~~~~~~~~~~~

coming soon!



Creating Your First Project
---------------------------

As mentioned in the introduction, openFrameworks takes care of most of the tedious work of setting up a c++ project in your IDE of choice. However, unlike programs like Flash or Processing, there is no "File > New" that allows you to create a project. Instead, the preferred method is to duplicate one of the example projects. 

IMPORTANT: By extension, this means that you should never edit any of the example projects or put your own apps into the examples folders. They are placed there to provide starting points for your own apps, but you'll want to keep them pristene so that you always have a working starting point for your projects. You'll see the importance of this more as you move forward.

As simple as this seems, this can be a huge stumbling block for a lot of beginners, so first lets agree on some terminology. 

When you open your apps folder, you see 2 folders: _examples_ and _addonsExamples_. Let's call these folders *workspaces*.

If you open one of those workspaces, you see more folders, like _easyCamExample_, _floatingPointImageExample_, _movieGrabberExample_, and _serialExample_. Each one of those folders is a *project*. Each contains (among other things) an ".xcodeproj" file and a "src" folder. A *project* _must_ be inside a *workspace* and can be compiled into a single application.

image:images/workspace04.png["Workspace terminology"]

We want to create a *project*, but every project has to live inside a *workspace*, and we're not supposed to put anything into the *examples* and *addonsExamples* workspaces, so our first step is going to be to make a new *workspace* by simply creating a folder called "MyFirstWorkspace" in the apps folder. You will probably end up making many workspaces while using openFrameworks. You can use them however you want, but the important thing is that they are directly inside the "apps" folder, ie: you can't have a workspace inside another workspace. 

image:images/workspace01.png["My First Workspace"]

Next we will [underline]#copy# (NOT move) the entire "emptyExample" folder from the "examples" workspace and paste it into "MyFirstWorkspace". On a mac, you can literally click on the emptyExample folder, press apple+C, then navigate to the "MyFirstWorkspace" folder and press apple+V. So the result should look like this:

image:images/workspace02.png["My First Project"]

Next, we can rename the duplicate project folder from "emptyExample" to "MyFirstProject". 

image:images/workspace03.png["My First Project"]

The super important thing here is that your XCode Project file is *exactly* 3 folders "below" the Root Folder (refer to colorful diagram above). So, whenever you make a new project, or if you are suddenly getting thousands of errors for no apparent reason, you should always double check that your XCode Project file is in the correct place.

The reason for this has to do with the 'lib' folder. We previously mentioned that openFrameworks is a "glue" for a bunch of different libraries, and these libraries are located in the 'lib' directory. We also discovered that it is the the job of the IDE know how to find and link together the various libraries. So, when the IDE tries to compile your program, it is set up to look for libraries in "../../../lib", or, in other words: "go back three folders (http://support.dtsearch.com/webhelp/dtsearch/relative_paths.htm[relative] to your .xcodeproj) and then look for a lib directory."  For instance, if you dig deep into the settings of any openFrameworks project, you will find paths like "../../../libs/FreeImage/include" and "../../../libs/poco/include". So, as long as your .xcodeproj file is within of_preRelease_v007_osx/apps/[workspace]/[project], everything will compile. If not, things will get ugly.

Okay!  Now you have created your first very own openFrameworks project. Double click on the XCode Project file in your new "MyFirstProject" and make sure "emptyExample" is selected as the target and click "Run" and you should see:

image:images/PlainGray.png["Plain Gray Window",width="600"]

Nothing! But that's exactly what you should see. Well, it's not too exciting yet, but you are well on your way.

Press escape or Apple+Q to exit out of the program.

[WARNING]
.Renaming your Project in XCode
=====================================================================
You might be tempted to also rename "emptyExample.xcodeproj" to "MyFirstProject.xcodeproj", and if you are using XCode < 4, you can. But as of XCode 4, this seems to cause some problems. So, instead, open up your project in XCode and click on the "emptyExample" title in the upper left as shown here:

image:images/rename01.png["Renaming your Project"]

After you rename it, you will get a dialog box asking you if you'd like to rename a bunch of other stuff. Click "Rename"

image:images/rename02.png["Renaming your Project"]

voila!
=====================================================================


When you click "Run" from within XCode, what actually happens behind the scenes is that your code is compiled into an executable and placed within the "bin" directory. Then that application is run just as if you had double clicked it. So, if you look in "MyFirstWorkspace/MyFirstApplication/bin" folder, you should see an application icon. This is your application! If you double-click on it, you will see the same gray window. Now you can send this application to all of your friends (who use a Mac) and they can launch your wonderful gray window program.

image:images/workspace05.png["Your Executable"]

Writing Code
------------

Okay, now that you know how to create a project, it's time to start writing some code inside it. The next few sections will introduce you to the structure of an openFrameworks application.

testApp.cpp
-----------

So it's finally time to start looking at some code. The first thing you need to do is open up a project in XCode. I'm going to assume that we are working with "MyFirstProject" inside the workspace "MyFirstWorkspace" from the last section. When you first open it up, take a look in the *Navigator View* (the panel on the far left of XCode) and click the disclosure triangle like this:

image:images/expand01.gif["Open up the project"]

. Click the disclosure triangle next to "MyFirstProject"
. Click the disclosure triangle next to "src"
. Click on testApp.cpp

testApp.cpp is going to become your very good friend over the next few tutorials. In the *Editor Window*, you should see something like starts like this:

[source,cpp]
---------------------------------------------------------------------
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}
---------------------------------------------------------------------

So what is going on here?

In a lot of ways, testApp.cpp is a lot like hello.cpp, the file that we wrote in the Introduction. It's a plain text file that contains `c++` source code. The difference now is that we are editing it through our IDE, so there is some really nice syntax highlighting that will hopefully make it easier to make sense of the code, and it will be a lot easier to compile and run when we want to.

On a very basic level, what you see here is a bunch of empty functions. A http://en.wikipedia.org/wiki/Function_(computer_science)[function] is a set of instructions that make up part of a larger program. Just in the snippet of code above, there are 4 functions: setup, update, draw, and keyPressed. Each of the functions is followed by a set of curly brackets ({}). What usually goes inside of these curly brackets are the instructions that make up the functions. 

If you refer back to the Q&A "What is a software framework?" in the introduction, the film production company analogy is particularly useful at this point. What you are looking at in testApp.cpp is how openFrameworks has provided all of the infrastructure and logistical details. Now it's your job to define what happens. You do this by putting code into the fuctions in testApp.cpp

These functions will be called by openFrameworks at different points during the execution of your program. Let's take a look at a few of them.

setup;;
	This function is called (ie: the code inside the curly brackets runs) before your program actually launches. So, let's say, for instance, you wanted to set the size of the window. You probably want this to happen before the window actually opens, so setup would be a good place for that.
	
update, draw;;
	After the setup function runs, the update and draw functions begin a loop that continues until your program ends. So, after setup() runs, update() runs, then draw(), then update(), then draw(), etc. and by default, this happens as fast as your computer can handle. update() is typically used for updating the state of your program (ie: changing the value of variables), while draw() is used to actually draw things into your window.

keyPressed, keyReleased, mouseMoved, mouseDragged, mousePressed;;
	Unlike the previous three functions, these functions are called only when a user does something. Can you guess what?
	
But enough with the reading. Let's see these things in action.

Making a Mark
-------------

We will start by drawing a simple circle in our gray window using the ofCircle function. Type `ofCircle(200, 200, 60);` on the blank line inside the draw() function so that your draw function looke like this:

[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
    ofCircle(200, 300, 60);
}
---------------------------------------------------------------------

NOTE: Notice the semicolon at the end of the line. All function calls must end with a semicolon. Function names are always case sensitive, so OfSetColor will nto work, nor OFsetcolor, etc.

Now run your program. You should see something like:

image:images/MyFirstProject01.png["A Plain White Circle", width="500"]

Congratulations!  You just made something appear on the screen! It's all downhill from here.

But what did we just do?  

http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofCircle[ofCircle] is a function that comes with openFrameworks (hence the 'of' prefix). You can invoke the ofCircle function inside your draw function as many times as you'd like. The numbers inside of the parenthesis after 'ofCircle' are called http://en.wikipedia.org/wiki/Parameter_(computer_programming)[arguments]. They determine exactly what the function does. They answer the questions: "okay, you want to draw a circle, but where? and how big?" Functions can take any number of arguments, always separated by commas, but ofCircle takes 3: an x coordinate, a y coordinate, and a radius. There are a few things you need to know to make sense of these arguments:

. All measurements in openFrameworks are in pixels. By saying that our circle has a radius of 60, that means that it will take up PI*60^2^ pixels total.
. This may seem obvious, but the coordinates refer to the center of the circle. Other shapes (such as rectangles) use the upper left corner.
. The "origin" of the coordinate system is in the upper left of the window. So, our circle appears 200 pixels from the left side of the screen, and 300 pixels from the top.

NOTE: The order of the arguments is important. The first argument to ofCircle will always mean "x coordinate" and the third will always mean "radius".

If you hadn't just read about it here, you could have found information about ofCircle on the http://www.openframeworks.cc/documentation/[openFrameworks documentation page], which you will be using more as we move on.

Adding some Color
-----------------

Your circle is great, but kind of boring. What if we want to introduce some color to our application?  To do that, we need the the http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofSetColor[ofSetColor] function. Try adding `ofSetColor(255, 0, 255);` right above the ofCircle line, so that your draw function looks like this:

[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 0, 255);
	ofCircle(200, 300, 60);
}
---------------------------------------------------------------------

Now try running your application. 

image:images/MyFirstProject02.png["A purple circle", width="500"]

Similar to ofCircle, the ofSetColor function takes 3 arguments, but the numbers have very different meanings. If you look at the documentation for http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofSetColor[ofSetColor], you'll notice that they arguments actually represent the red, green, and blue values for the color that you want to use, on a scale of 0-255. So when we typed `ofSetColor(255, 0, 255);`, we were saying "until further notice, draw everything with 100% red, 0 green, and 100% blue."  

TIP: Try changing the values to get different color variations.

This last point is important: when we call "ofSetColor", it's like picking a crayon out of a box. Everything that gets drawn after that (below that line of code) will be drawn in that color until we call ofSetColor again. So if we want to draw another circle on the screen, we could simply call the ofCircle function again:


[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 0, 255);
    ofCircle(200, 300, 60);
    
    ofCircle(500, 500, 100);
}
---------------------------------------------------------------------


But if we wanted that circle to be a different color, we would have to call ofSetColor again:

[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 0, 255);
    ofCircle(200, 300, 60);
    
    ofSetColor(0, 255, 255);
    ofCircle(500, 500, 100);
}
---------------------------------------------------------------------

image:images/MyFirstProject03.png["Two Colorful Circles", width="500"]


All The Shapes You Can Handle
-----------------------------

Of course, oF can draw more than circles. 

. http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofRect[ofRect] draws a rectangle. arguments are (x, y, width, height) 
. http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofTriangle[ofTriangle] draws a triangle. arguments are the coordinates of the three points: (x1, y1, x2, y2, x3, y3)
. http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofLine[ofLine] draws a line. arguments are the start coordinate and the end coordinate (x1, y1, x2, y2)
. http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofEllipse[ofEllipse] arguments are: (x, y, width, height)
. http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofCurve[ofCurve] Draws a curve from point (x1, y1) to point (x2, y2). The curve is shaped by the two control points (x0,y0) and (x3,y3).

NOTE: Control points can be tricky. If you've used the pen tool in photoshop or illustrator, you probably understand them. If not, check out http://www.actionscript.org/resources/articles/172/1/Understanding-curves-and-control-point-placement/Page1.html[this tutorial]. It's about ActionScript, but it gives a great overiew of the concept of curves and control points.

TIP:  Try making 3 different projects in your "MyFirstWorkspace" workspace. In each one, draw a different shape in a different location using a different color.

Adding Movement
---------------

Drawing static shapes is great, but what if we want our shapes to move around the screen?

We mentioned earlier that the draw() function is called repeatedly after the program is started. This is very important because it is how we achieve animation in openFrameworks. It might be a little unintuitive if you are used to  Flash or even something like stop-frame animation, where you can add something to a "stage" and then reposition it as needed. This is *not* how openFrameworks (or most computer animation) works. Actually, openFrameworks is more like traditional (we're talking old-school Disney/Bambi) animation, where we must redraw the frame completely every single "frame". In the parlance of openFrameworks, every time the draw() function is called is one "frame". So, in actuality, when you run the program above and see your purple circle, what you are actually looking at is the circle being drawn, then cleared (a single frame), and then drawn, then cleared, repeatedly. It's just happening so fast that it appears to stay where it is.

In the example above, when we draw our circle, we use two numbers to tell the ofCircle function where to draw the circle within the window. So it follows that, if we want the circle to appear to move, we need to change these numbers over time. Perhaps the first time draw() happens, the circle is drawn at (200, 300), but in the next time, we want it to be one pixel to the right (201, 300), and then another pixel to the right (202, 300), and so on. 

In `c++`, and in programming in general, whenever you have a value that you want to change, you create a "variable". Variables come in different shapes and sizes depending on what they represent, such as decimal numbers, whole numbers, a letter, or a bunch of letters. In this case, we want to create variables that can stand in for coordinates in our ofCircle function, so we will use 2 *int*s.

Put this at the top of your testApp.cpp, right under the `#include` line, so that your file starts like this:

[source,cpp]
---------------------------------------------------------------------
#include "testApp.h"

int myCircleX;
int myCircleY;
---------------------------------------------------------------------

In those 2 new lines of code, we "declared" 2 new variables: one called 'myCircleX' and one called 'myCircleY'. You could actually name them whatever you want (within reason), but it's a good idea to name them something that is related to how they will be used. We also said that these variables will be used to hold whole-number integer values, or *int*s. Declaring a variable is an important and necessary step. It's like telling your application "okay, I'm going to need to store a number that might change."

The next thing we need to do is give those variables a starting value. We know that the endgame here is to have these variables change over time. But before we can change them, we need to give them an initial value. In other words, before our circle starts moving, where will it appear? 

In a previous section, we learned that the setup() function gets called once when the application launches, and then never called again. This sounds like it could be useful for giving our variables some initial values. So in your setup() function, add the following lines.

[source,cpp]
---------------------------------------------------------------------
void testApp::setup(){
	myCircleX = 300;
	myCircleY = 200;
}
---------------------------------------------------------------------

Perfect!  So, to recap, we now have 2 variables, 'myCircleX', and 'myCircleY', and we have just "initialized" them, or populated with an "initial" value. Notice that, just like any mathmatical equation, we use the equals sign (=) to assign the number 300 to 'myCircleX'. In `c++` parlance, the equals sign is known as the "assignment operator", because it's used to assign a value to a variable. The "assignment" always flows from right to left; that is, the value that is being assigned is on the right and thing that is receiving the assignment is on the left.

Now we can edit our ofCircle call a bit :

[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 0, 255);
	ofCircle(myCircleX, myCircleY, 60);
}
---------------------------------------------------------------------

Notice that we are still passing 3 arguments to the ofCircle function.  But now, instead of the old "hard-coded" (200, 300) values that we can't change, we are letting the variables that we made stand in.

If you run your app now, you shouldn't notice any change. That's because we haven't gotten around to changing the variables yet. So let's do it.

Let's edit our draw function a little so that it looks like this:

[source,cpp]
---------------------------------------------------------------------
void testApp::draw(){
	myCircleX = myCircleX + 1;
	
	ofSetColor(255, 0, 255);
	ofCircle(myCircleX, myCircleY, 60);
}
---------------------------------------------------------------------

In this new line, we are using the "assignment operator" again, just like in the setup function. In English, that line would say "take the value of myCircleX plus one, and assign that to myCircleX".  In other words, we are incrementing myCircleX by 1. `c++` provides a shortcut for the common task of incrementing a variable: `myCircleX++;`  This is extremely common, so let's actually change our code to use this handy shortcut:

....
myCircleX = myCircleX + 1;
....
becomes
....
myCircleX++;
....

If you run your program now, you should see your circle move off the screen to the right!  Animation!

There is just one thing we need to fix before moving on to more pressing aesthetic concerns. If you read back through the descriptions of what the update() and draw() functions are supposed to be used for, you'll notice that the draw function is for drawing (so far, so good), but the update() function is where we are supposed to take care of updating variables. There are some very good reasons for this that we will get into later, but for now, let's move the line we just wrote to the update function.  So, your update and draw functions should look like this:

[source,cpp]
---------------------------------------------------------------------
void testApp::update(){
    myCircleX++;
}

void testApp::draw(){
	ofSetColor(255, 0, 255);
	ofCircle(myCircleX, myCircleY, 60);
}
---------------------------------------------------------------------

You shouldn't notice any difference in terms of functionality, but it's a good habit to get into.

Framerate
---------




