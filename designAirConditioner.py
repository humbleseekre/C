'''
You already have some methods to use:

getTemp() // get current temperature
heat() // heating mode
cool() // cooling mode
off() // turn off the air condition
Please desgin the following methods (like a remote control):

setToHeat()/setToCool()
setTemp()
switchOn()/switchOff()
When the air condition is running, you should make sure that the room temperature can always reach the 
temperature you set. It means that if current temperature is lower than your target temperature, the air condition 
should be turned on. And if current temperature is higher than your target temperature, the air condition should standby.
'''

# Default Methods: AC.on(), AC.off(), AC.getTemp() to get current temperature, AC.heat(), AC.cool()
from enum import Enum
class AcMode(Enum):
    cool = 1
    heat = 0

class AcState(Enum):
    standby = 2
    on = 1
    off = 0
    
class AirControlSystem:
    def __init__(self):
        self.__targetTemperature = 75
        self.__mode = AcMode.cool
        self.__state = AcState.off
    
    def switchOn(self):
        if(self.__state==AcState.off):
            self.__state=AcState.on
            AC.on()
        else:
            raise Exception("AC is already On")
    
    def switchOff(self):
        if(self.__state==AcState.on or self.__state==AcState.standby):
            self.__state=AcState.off
            if(self.__state==AcState.on):
                AC.off()
        else:
            raise Exception("AC is already Off")
    
    def setACState(self):
        if(self.__state==AcState.off):
            raise Exception("AC is Off, please turn on the AC to set state")
        if(self.__mode==AcMode.heat):
            if(self.__targetTemperature>AC.getTemp()):
                if(self.state==AcState.standby):
                    self.__state = AcState.on
                    AC.on()
            else:
                if(self.state==AcState.on):
                    self.__state =  AcState.standby
                    AC.off()
        elif(self.__mode==AcMode.cool):
            if(self.__targetTemperature<getTemp()):
                if(self.state==AcState.standby):
                    self.__state = AcState.on
                    AC.on()
            else:
                if(self.state==AcState.on):
                    self.__state =  AcState.standby
                    AC.off()
        
    def setTemp(self, temperature):
        if(self.__state==AcState.off):
            raise Exception("AC is Off, please turn on the AC to set temperature")
        self.__targetTemperature = temperature
        self.setACState()
    
    def setToHeat(self):
        if(self.__state==AcState.off):
            raise Exception("AC is Off, please turn on the AC to set mode")
        if(self.__mode==AcMode.heat):
            raise Exception("AC is already on heat")
        self.__mode = AcMode.heat
        AC.heat()
        self.setACState()
        
    def setToCool(self):
        if(self.__state==AcState.off):
            raise Exception("AC is Off, please turn on the AC to set mode")
        if(self.__mode==AcMode.cool):
            raise Exception("AC is already on cool")
        self.__mode = AcMode.cool
        AC.cool()
        self.setACState()           
