/*
Design a home automation sytem to remotely control all the switches, devices in a home.

You are required to provide a low level design (define data models and interaction between them) for
a home automation system wherein a user can control (turn on/off) all switches in a house. 
The design should be scalable and flexible.
*/
public interface Device {
public abstract void turnOn();
public abstract void turnOff();
}
public class Light implements Device {
String lightname;

Light(String lightname){
    this.lightname = lightname;
}

public void changeColor(){
    System.out.println(lightname + " change color");
}

@Override
public void turnOn() {
    System.out.println(lightname + " is turned on.");
}

@Override
public void turnOff() {
    System.out.println(lightname + " is turned off.");
}
}
public class Tv implements Device {
String tvName;

Tv(String tvName){
    this.tvName = tvName;
}

@Override
public void turnOn() {
    System.out.println( tvName + " is turned on.");
}

@Override
public void turnOff() {
    System.out.println(tvName + " is turned off.");
}
}
import java.util.ArrayList;
import java.util.List;

public class Controller {
List bedroomDevices = new ArrayList<>();
List livingroomDevices = new ArrayList<>();

public void addDeviceToBedRoom(Device device){
    bedroomDevices.add(device);
}

public void addDeviceToLivingRoom(Device device){
    livingroomDevices.add(device);
}

public void turnOnDevice(Device device){
    device.turnOn();
}

public void turnOffDevice(Device device){
    device.turnOff();
}

public void turnOnbedroomDevices(){
    for(Device d:bedroomDevices){
        d.turnOn();
    }
}

public void turnOffbedroomDevices(){
    for(Device d:bedroomDevices){
        d.turnOff();
    }
}
}
public class Test {
public static void main(String[] args){
Light light1 = new Light("light1");
Light light2 = new Light("light2");
Light light3 = new Light("light3");

    Tv tv1 = new Tv("Tv1");
    Tv tv2 = new Tv("Tv2");


    Controller controller = new Controller();

    controller.addDeviceToBedRoom(light1);
    controller.addDeviceToBedRoom(light2);
    controller.addDeviceToBedRoom(tv1);

    controller.addDeviceToLivingRoom(tv2);
    controller.addDeviceToLivingRoom(light1);

    controller.turnOnbedroomDevices();

    controller.turnOffDevice(tv1);


}
}
