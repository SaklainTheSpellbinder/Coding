package State;

public class SoldOutState implements State {
    private final GumballMachine machine;
    public SoldOutState(GumballMachine gumballMachine) {
        machine=gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Machine is sold out");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("No quarter inserted");
    }

    @Override
    public void turnCrank() {
        System.out.println("No gumball available");
    }

    @Override
    public void dispense() {
        System.out.println("Nothing dispensed");
    }
}
