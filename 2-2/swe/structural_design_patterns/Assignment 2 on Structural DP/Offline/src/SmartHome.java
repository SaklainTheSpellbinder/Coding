import java.util.ArrayList;
import java.util.List;
import java.util.Set;

//main interface
interface SmartDevice{
    String getStatus();
    double getPowerUsage();
    void activate();
    void deactivate();
    Class<?>getDeviceType();
}

//leaves
abstract class BasicSmartDevice implements SmartDevice{
    protected boolean on=false;
    @Override
    public void activate() {
        on=true;
    }

    @Override
    public void deactivate() {
        on=false;
    }

    @Override
    public Class<?> getDeviceType() {
        return this.getClass();
    }
}

class SmartLight extends BasicSmartDevice{

    @Override
    public String getStatus() {
        if(on){
            return "Light: ON";
        }
        else{
            return "Light: OFF";
        }
    }

    @Override
    public double getPowerUsage() {
        return on?10.0:0.0;
    }
}

class SmartThermostat extends BasicSmartDevice{
    @Override
    public String getStatus() {
        if(on){
            return "Thermostat: ON";
        }
        else{
            return "Thermostat: OFF";
        }
    }

    @Override
    public double getPowerUsage() {
        return on?150.0:0.0;
    }
}

class SmartSpeaker extends BasicSmartDevice{
    @Override
    public String getStatus() {
        if(on){
            return "Speaker: Playing";
        }
        else{
            return "Speaker: Idle";
        }
    }

    @Override
    public double getPowerUsage() {
        return on?5.0:0.0;
    }
}


//composite room and home superclass
abstract class SmartDeviceGroup implements SmartDevice{
    public abstract List<SmartDevice> getChildren();

    @Override
    public Class<?> getDeviceType() {
        return this.getClass();
    }
}

//composite classes
class Room extends SmartDeviceGroup{
    private final String name;
    private final List<SmartDevice> devices=new ArrayList<>();
    public Room(String name){
        this.name=name;
    }

    public void addDevice(SmartDevice device){
        devices.add(device);
    }

    public void removeDevice(SmartDevice device){
        devices.remove(device);
    }

    @Override
    public List<SmartDevice> getChildren() {
        return devices;
    }

    @Override
    public void activate() {
        for (SmartDevice s : devices){
            s.activate();
        }
    }


    @Override
    public void deactivate() {
        for (SmartDevice s : devices){
            s.deactivate();
        }
    }

    @Override
    public double getPowerUsage() {
        double total=0.0;
        for(SmartDevice s: devices){
            total+=s.getPowerUsage();
        }
        return total;
    }

    @Override
    public String getStatus() {
        StringBuilder sb=new StringBuilder("["+name+"]");
        for(SmartDevice d: devices){
            sb.append("\n ").append(d.getStatus());
        }
        return sb.toString();
    }
}

class Home extends SmartDeviceGroup{
    private final String name;
    private final List<SmartDevice> rooms=new ArrayList<>();
    public Home(String name){
        this.name=name;
    }

    public void addRoom(SmartDevice device){
        rooms.add(device);
    }

    public void removeRoom(SmartDevice room){
        rooms.remove(room);
    }

    @Override
    public List<SmartDevice> getChildren() {
        return rooms;
    }

    @Override
    public void activate() {
        for (SmartDevice s : rooms){
            s.activate();
        }
    }


    @Override
    public void deactivate() {
        for (SmartDevice s : rooms){
            s.deactivate();
        }
    }

    @Override
    public double getPowerUsage() {
        double total=0.0;
        for(SmartDevice s: rooms){
            total+=s.getPowerUsage();
        }
        return total;
    }

    @Override
    public String getStatus() {
        StringBuilder sb=new StringBuilder("==="+name+"===");
        for(SmartDevice d: rooms){
            sb.append("\n ").append(d.getStatus());
        }
        return sb.toString();
    }
}



//devicelevel decorators
abstract class DeviceDecorator implements SmartDevice{
    protected final SmartDevice wrapped;
    protected DeviceDecorator(SmartDevice wrapped){
        this.wrapped=wrapped;
    }

    @Override
    public void activate() {
        wrapped.activate();
    }

    @Override
    public void deactivate() {
        wrapped.deactivate();
    }

    @Override
    public double getPowerUsage() {
        return wrapped.getPowerUsage();
    }

    @Override
    public String getStatus() {
        return wrapped.getStatus();
    }

    @Override
    public Class<?> getDeviceType() {
        return wrapped.getDeviceType();
    }
}

class AccessRestricted extends DeviceDecorator{
    private final int pin;
    private boolean locked=true;

    public AccessRestricted(SmartDevice wrapped,int pin){
        super(wrapped);
        this.pin=pin;
    }

    public void unlock(int tintin){
        if(tintin==pin){
            locked=false;
        }
    }

    @Override
    public void activate() {
        if(locked){
            return;
        }
        wrapped.activate();
    }

    @Override
    public void deactivate() {
        if(locked){
            return;
        }
        wrapped.deactivate();
    }

    @Override
    public String getStatus() {
        String s=wrapped.getStatus();
        if(locked){
            s+=" [LOCKED]";
        }
        return s;
    }
}

class TimerControlled extends DeviceDecorator{
    private final int seconds;
    private boolean running=false;
    public TimerControlled(SmartDevice wrapped,int seconds){
        super(wrapped);
        this.seconds=seconds;
    }

    @Override
    public void activate() {
        wrapped.activate();
        running=true;
    }

    @Override
    public void deactivate() {
        wrapped.deactivate();
        running=false;
    }

    @Override
    public String getStatus() {
        String s=wrapped.getStatus();
        if(running){
            s+=" (auto-off in " + seconds + "s)";
        }
        return s;
    }

    public void simulateTimerExpiry(){
        if(running){
            wrapped.deactivate();
            running=false;
        }
    }
}

class PowerThrottled extends DeviceDecorator{
    private final double cap;
    public PowerThrottled(SmartDevice wrapped,double cap){
        super(wrapped);
        this.cap=cap;
    }

    @Override
    public double getPowerUsage() {
        return Math.min(wrapped.getPowerUsage(),cap);
    }

    @Override
    public String getStatus() {
        String s=wrapped.getStatus();
        if(wrapped.getPowerUsage()>cap){
            s +=" [throttled to " + cap + "W]";
        }
        return s;
    }
}

//eco and premium stuff
abstract class PremiumDecorator extends SmartDeviceGroup{
    protected final SmartDeviceGroup wrapped;
    protected PremiumDecorator(SmartDeviceGroup wrapped){
        this.wrapped=wrapped;
    }

    @Override
    public List<SmartDevice> getChildren() {
        return wrapped.getChildren();
    }

    @Override
    public Class<?> getDeviceType() {
        return wrapped.getDeviceType();
    }
}

class EcoMode extends PremiumDecorator{
    private final double budget;
    public EcoMode(SmartDeviceGroup wrapped,double budget){
        super(wrapped);
        this.budget=budget;
    }

    @Override
    public void activate() {
        wrapped.activate();
        List<SmartDevice>children=wrapped.getChildren();
        for(int i=children.size()-1;i>=0&& getPowerUsage()>budget;i--){
            children.get(i).deactivate();
        }
    }

    @Override
    public void deactivate() {
        wrapped.deactivate();
    }

    @Override
    public double getPowerUsage() {
        return wrapped.getPowerUsage();
    }

    @Override
    public String getStatus() {
        return "[ECO: " + budget + "W budget]\n" + wrapped.getStatus();
    }
}

class GuestMode extends PremiumDecorator{
    private final Set<Class<?>> allowedTypes;
    public GuestMode(SmartDeviceGroup wrapped,Set<Class<?>> allowedTypes){
        super(wrapped);
        this.allowedTypes=allowedTypes;
    }

    private boolean isAllowed(SmartDevice child){
        return allowedTypes.contains(child.getDeviceType());
    }

    @Override
    public void activate() {
        for(SmartDevice child:wrapped.getChildren()){
            if(isAllowed(child)){
                child.activate();
            }
        }
    }

    @Override
    public void deactivate() {
        wrapped.deactivate();
    }

    @Override
    public double getPowerUsage() {
        double total=0.0;
        for(SmartDevice child: wrapped.getChildren()){
            if(isAllowed(child)){
                total+=child.getPowerUsage();
            }
        }
        return total;
    }

    @Override
    public String getStatus() {
        StringBuilder sb=new StringBuilder("[GUEST MODE]");
        for(SmartDevice child: wrapped.getChildren()){
            sb.append("\n ").append(child.getStatus());
            if(!isAllowed(child)){
                sb.append(" [guest-restricted]");
            }
        }
        return sb.toString();
    }
}

public class SmartHome {
}
