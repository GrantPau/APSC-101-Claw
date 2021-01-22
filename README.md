# APSC 101 Claw

##Purpose

An autonomous claw that picks up objects and releases them at different locations. Using an Arduino, the goal is to construct a device that grabs household items quickly and safely place them at their destination within the time limit. This collaborative project was developed by all the members in Team F8.

<p align="center">
  <img src="https://github.com/GrantPau/APSC-101-Claw/blob/main/Drawings%2C%20Schematics%2C%20CAD%20Models/final-design.PNG"/>
</p>
<p align="center">Figure 1: Final Claw Design<p align="center">


## How it Works
A program is written in Arduino IDE that reads the distance from an ultrasonic sensor. When it reaches a certain distance between the claw and the object or ground, it tells a servo motor to rotate, allowing the claw to open or close. The device is powered by a power bank which is also mounted on the claw. The Arduino code is available [here](https://github.com/GrantPau/APSC-101-Claw/blob/main/Arduino%20Code/main/main.ino).

![](https://github.com/GrantPau/APSC-101-Claw/blob/main/Drawings%2C%20Schematics%2C%20CAD%20Models/GIFs%20for%20ReadMe/grabbing-test.gif)
<p align="center">Figure 2: Grabbing Test<p align="center">
<br/>
<br/>
<br/>
<p align="center">
  <img src="https://github.com/GrantPau/APSC-101-Claw/blob/main/Drawings%2C%20Schematics%2C%20CAD%20Models/circuit-schematic.PNG"/>
</p>
<p align="center">Figure 3: Ciruit Schematic with Distance Sensor and Servo Motor<p align="center">


## Design
The final prototype takes most of the heavy components placed on side of the claw and minimal mass on the other end. By connecting the lighter end to the rotating shaft of the motor, the overall torque ensures that only the lighter end is able to rotate, giving the operational task to collect or release objects. The heavier mass on the other side of the claw prevents this side from moving which allows for more control and grip when grabbing items. Material-wise, the claw is constructed out of sheet metal. These pieces were bent and connected using hand tools in order to achieve the shape of the final design. More drawings, schematics, and models are available [here](https://github.com/GrantPau/APSC-101-Claw/tree/main/Drawings%2C%20Schematics%2C%20CAD%20Models).

 
![](https://github.com/GrantPau/APSC-101-Claw/blob/main/Drawings%2C%20Schematics%2C%20CAD%20Models/GIFs%20for%20ReadMe/virtual-prototype.gif)
<p align="center">Figure 4: Virtual Prototype Animation<p align="center">
<br/>
<br/>
<br/>

<p align="center">
  <img src="https://github.com/GrantPau/APSC-101-Claw/blob/main/Drawings%2C%20Schematics%2C%20CAD%20Models/third-angle-projection-of-final-design.PNG"/>
</p>
<p align="center">Figure 5: Third Angle Projection of Final Design<p align="center">

