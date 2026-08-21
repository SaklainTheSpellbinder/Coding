package State;

public class SoldState implements State {
    private final GumballMachine machine;
    public SoldState(GumballMachine gumballMachine) {
        machine=gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Please wait");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Too late to eject");
    }

    @Override
    public void turnCrank() {
        System.out.println("Already turned");
    }

    @Override
    public void dispense() {
        machine.releaseBall();

        if(machine.getCount()>0){
            machine.setState(machine.getNoQuarterState());
        }
        else{
            System.out.println("Machine is sold out");
            machine.setState(machine.getSoldOutState());
        }
    }
}
